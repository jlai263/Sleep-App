#include "smartalarmdialog.h"
#include "ui_smartalarmdialog.h"

#include <QTime>
#include <QDebug>

SmartAlarmDialog::SmartAlarmDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SmartAlarmDialog)
    , m_sleepScore(0.0)  // Default sleep score
{
    ui->setupUi(this);

    ui->timeTargetWake->setTime(QTime(7, 0));

    // Connect buttons
    connect(ui->btnCalculate, &QPushButton::clicked,
            this, &SmartAlarmDialog::onCalculateClicked);
    connect(ui->buttonBoxOk, &QPushButton::clicked,
            this, &SmartAlarmDialog::onOkClicked);
    connect(ui->buttonBoxCancel, &QPushButton::clicked,
            this, &SmartAlarmDialog::onCancelClicked);
}

SmartAlarmDialog::~SmartAlarmDialog()
{
    delete ui;
}

void SmartAlarmDialog::setSleepScore(double score)
{
    m_sleepScore = score;
}

SmartAlarm SmartAlarmDialog::smartAlarm() const
{
    return m_alarm;
}

void SmartAlarmDialog::onCalculateClicked()
{
    // Get the user's chosen wake time
    QTime wakeTime = ui->timeTargetWake->time();
    QDateTime now = QDateTime::currentDateTime();
    QDateTime targetDt = QDateTime(now.date(), wakeTime);

    // Calculate needed sleep hours based on sleep score
    double neededSleepHours = (m_sleepScore >= 8.0) ? 7.0 : 8.0;

    // Subtract the needed hours from the wake time
    QDateTime bedtime = targetDt.addSecs(-static_cast<qint64>(neededSleepHours * 3600));

    // Update SmartAlarm
    m_alarm.setTargetWakeTime(targetDt);
    m_alarm.setDesiredSleepHours(neededSleepHours);

    // Update UI with the calculated bedtime
    ui->lblOptimalTime->setText(bedtime.time().toString("HH:mm"));
}

void SmartAlarmDialog::onOkClicked()
{
    accept();
}

void SmartAlarmDialog::onCancelClicked()
{
    reject();
}
