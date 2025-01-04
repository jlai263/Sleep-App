#ifndef SMARTALARM_H
#define SMARTALARM_H

#include <QDateTime>

class SmartAlarm
{
public:
    SmartAlarm();
    ~SmartAlarm();

    // Set the user’s desired wake time (e.g., 07:00)
    void setTargetWakeTime(const QDateTime &time);
    QDateTime targetWakeTime() const;

    // Optionally store how many hours the user wants to sleep
    void setDesiredSleepHours(double hours);
    double desiredSleepHours() const;

    // Example logic: shift the alarm if user’s average is off
    // or if they have certain habits.
    QDateTime calculateOptimalWakeTime(double userAvgHours) const;
    // The param could be from SleepAnalyzer::getAverageSleepHoursLast14Days(), etc.

private:
    QDateTime m_targetWake;
    double m_desiredHours; // e.g. 8.0 by default
};

#endif // SMARTALARM_H
