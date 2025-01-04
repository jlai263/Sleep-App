#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QMessageBox>
#include <QHeaderView>
#include <QFileDialog>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonValue>

#include "addsleepsessiondialog.h"
#include "sleepanalysisdialog.h"
#include "sleepanalyzer.h"
#include "managehabitsdialog.h"
#include "smartalarm.h"
#include "smartalarmdialog.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Connect Sleep-related buttons
    connect(ui->btnAddSleepSession, &QPushButton::clicked,
            this, &MainWindow::onAddSleepSessionClicked);
    connect(ui->btnAnalyzeSleep, &QPushButton::clicked,
            this, &MainWindow::onAnalyzeSleepClicked);

    // Connect Save/Load for Sleep Data
    connect(ui->btnSaveData, &QPushButton::clicked,
            this, &MainWindow::onSaveDataClicked);
    connect(ui->btnLoadData, &QPushButton::clicked,
            this, &MainWindow::onLoadDataClicked);

    // Connect "Manage Habits" button.
    connect(ui->btnManageHabits, &QPushButton::clicked,
            this, &MainWindow::onManageHabitsClicked);
    connect(ui->btnSmartAlarm, &QPushButton::clicked,
            this, &MainWindow::onSmartAlarmClicked);

    // Override the table columns to 4 (we only had 2 in the .ui)
    ui->tblSleepSessions->setColumnCount(4);
    ui->tblSleepSessions->setHorizontalHeaderLabels(
        QStringList() << "Start Time" << "End Time" << "Quality" << "Notes");
    ui->tblSleepSessions->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tblSleepSessions->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tblSleepSessions->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tblSleepSessions->setSelectionMode(QAbstractItemView::SingleSelection);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onAddSleepSessionClicked()
{
    AddSleepSessionDialog dlg(this);
    if (dlg.exec() == QDialog::Accepted) {
        QDateTime start = dlg.startTime();
        QDateTime end   = dlg.endTime();
        int q           = dlg.quality();
        QString n       = dlg.notes();

        // Add to SleepLog
        m_sleepLog.addSession(start, end, q, n);

        // Insert row in the table
        int newRow = ui->tblSleepSessions->rowCount();
        ui->tblSleepSessions->insertRow(newRow);

        ui->tblSleepSessions->setItem(newRow, 0,
                                      new QTableWidgetItem(start.toString("yyyy-MM-dd hh:mm")));
        ui->tblSleepSessions->setItem(newRow, 1,
                                      new QTableWidgetItem(end.toString("yyyy-MM-dd hh:mm")));
        ui->tblSleepSessions->setItem(newRow, 2,
                                      new QTableWidgetItem(QString::number(q)));
        ui->tblSleepSessions->setItem(newRow, 3,
                                      new QTableWidgetItem(n));
    }
}

void MainWindow::onAnalyzeSleepClicked()
{
    SleepAnalyzer analyzer;
    analyzer.setSleepLog(m_sleepLog);
    double score = analyzer.adjustedSleepScore(m_habitManager);
    qDebug() << "Your Sleep Score:" << score;

    SleepAnalysisDialog dlg(this);
    dlg.setAnalyzer(analyzer);
    dlg.exec();
}
void MainWindow::onSaveDataClicked()
{
    QString fileName = QFileDialog::getSaveFileName(
        this, "Save All Data", "",
        "JSON Files (*.json);;All Files (*)");
    if (fileName.isEmpty())
        return;

    // Build the "sleepSessions" array
    QJsonArray sleepArray;
    for (auto &sess : m_sleepLog.sessions()) {
        QJsonObject obj;
        obj["start"]   = sess.start.toString(Qt::ISODate);
        obj["end"]     = sess.end.toString(Qt::ISODate);
        obj["quality"] = sess.quality;
        obj["notes"]   = sess.notes;
        sleepArray.append(obj);
    }

    // Get habits array from manager
    QJsonArray habitArray = m_habitManager.toJsonArray();

    // Combine into single root object
    QJsonObject root;
    root["sleepSessions"] = sleepArray;
    root["habits"]        = habitArray;

    QJsonDocument doc(root);

    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly)) {
        QMessageBox::warning(this, "Error", "Could not open file for writing.");
        return;
    }
    file.write(doc.toJson(QJsonDocument::Indented));
    file.close();

    QMessageBox::information(this, "Save", "Data saved to file.");
}
void MainWindow::onLoadDataClicked()
{
    QString fileName = QFileDialog::getOpenFileName(
        this, "Load All Data", "",
        "JSON Files (*.json);;All Files (*)");
    if (fileName.isEmpty())
        return;

    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly)) {
        QMessageBox::warning(this, "Error", "Could not open file for reading.");
        return;
    }
    QByteArray rawData = file.readAll();
    file.close();

    QJsonParseError err;
    QJsonDocument doc = QJsonDocument::fromJson(rawData, &err);
    if (err.error != QJsonParseError::NoError) {
        QMessageBox::warning(this, "Error", "JSON parse error: " + err.errorString());
        return;
    }
    if (!doc.isObject()) {
        QMessageBox::warning(this, "Error", "Root of file is not a JSON object!");
        return;
    }


    QJsonObject root = doc.object();

    // Load Sleep
    QJsonValue sleepVal = root["sleepSessions"];
    if (sleepVal.isArray()) {
        // Clear old
        m_sleepLog = SleepLog();
        ui->tblSleepSessions->setRowCount(0);

        for (auto v : sleepVal.toArray()) {
            QJsonObject obj = v.toObject();
            QString startStr = obj["start"].toString();
            QString endStr   = obj["end"].toString();
            int quality      = obj["quality"].toInt();
            QString notes    = obj["notes"].toString();

            QDateTime start = QDateTime::fromString(startStr, Qt::ISODate);
            QDateTime end   = QDateTime::fromString(endStr,   Qt::ISODate);

            m_sleepLog.addSession(start, end, quality, notes);
        }
        rebuildTableFromLog();
    }

    // Load Habits
    QJsonValue habitVal = root["habits"];
    if (habitVal.isArray()) {
        m_habitManager.loadFromJson(habitVal.toArray());
    }

    QMessageBox::information(this, "Load", "Data loaded from file.");
}

void MainWindow::rebuildTableFromLog()
{
    ui->tblSleepSessions->setRowCount(0);

    auto allSessions = m_sleepLog.sessions();
    for (const auto &s : allSessions) {
        int newRow = ui->tblSleepSessions->rowCount();
        ui->tblSleepSessions->insertRow(newRow);

        ui->tblSleepSessions->setItem(newRow, 0,
                                      new QTableWidgetItem(s.start.toString("yyyy-MM-dd hh:mm")));
        ui->tblSleepSessions->setItem(newRow, 1,
                                      new QTableWidgetItem(s.end.toString("yyyy-MM-dd hh:mm")));
        ui->tblSleepSessions->setItem(newRow, 2,
                                      new QTableWidgetItem(QString::number(s.quality)));
        ui->tblSleepSessions->setItem(newRow, 3,
                                      new QTableWidgetItem(s.notes));
    }
}

void MainWindow::onManageHabitsClicked()
{
    ManageHabitsDialog dlg(this);
    dlg.setHabitManager(m_habitManager);

    if (dlg.exec() == QDialog::Accepted) {

    }

    m_habitManager = dlg.habitManager();
}

void MainWindow::onSmartAlarmClicked()
{
    SleepAnalyzer analyzer;
    analyzer.setSleepLog(m_sleepLog);
    double score = analyzer.adjustedSleepScore(m_habitManager);

    SmartAlarmDialog dlg(this);
    dlg.setSleepScore(score);

    if (dlg.exec() == QDialog::Accepted) {
        SmartAlarm finalAlarm = dlg.smartAlarm();
        qDebug() << "Smart alarm's target wake time:"
                 << finalAlarm.targetWakeTime()
                 << "Need at least"
                 << finalAlarm.desiredSleepHours()
                 << "hours of sleep.";
    }
}

