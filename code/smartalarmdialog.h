#ifndef SMARTALARMDIALOG_H
#define SMARTALARMDIALOG_H

#include <QDialog>
#include <QDateTime>
#include "smartalarm.h"

namespace Ui {
class SmartAlarmDialog;
}

class SmartAlarmDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SmartAlarmDialog(QWidget *parent = nullptr);
    ~SmartAlarmDialog();

    void setSleepScore(double score);
    SmartAlarm smartAlarm() const;

private slots:
    void onCalculateClicked();
    void onOkClicked();
    void onCancelClicked();

private:
    Ui::SmartAlarmDialog *ui;
    SmartAlarm m_alarm;
    double m_sleepScore;
};

#endif // SMARTALARMDIALOG_H
