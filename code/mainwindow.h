#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "sleeplog.h"
#include "habitmanager.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    // Already existing sleep-related slots
    void onAddSleepSessionClicked();
    void onAnalyzeSleepClicked();
    void onSaveDataClicked();
    void onLoadDataClicked();

    void onSmartAlarmClicked();
    void onManageHabitsClicked();

private:
    Ui::MainWindow *ui;

    SleepLog m_sleepLog;       // For your sleep sessions
    HabitManager m_habitManager; // For your habits

    void rebuildTableFromLog();
};

#endif // MAINWINDOW_H
