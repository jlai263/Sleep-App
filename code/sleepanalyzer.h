#ifndef SLEEPANALYZER_H
#define SLEEPANALYZER_H

#include "sleeplog.h"

class HabitManager;

class SleepAnalyzer
{
public:
    SleepAnalyzer();
    ~SleepAnalyzer();

    void setSleepLog(const SleepLog &log);

    double getTotalSleepHours() const;
    double getAverageSleepHours() const;
    double getTotalSleepHoursLast14Days() const;
    double getAverageSleepHoursLast14Days() const;
    double getAverageQualityLast14Days() const;

    // We pass the manager so we can see user’s habits
    double adjustedSleepScore(const HabitManager &habits);

    // Access the SleepLog if needed
    const SleepLog & getLog() const;

private:
    SleepLog m_log;
};

#endif // SLEEPANALYZER_H
