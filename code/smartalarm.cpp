#include "smartalarm.h"

SmartAlarm::SmartAlarm()
    : m_desiredHours(8.0) // default to 8
{
}

SmartAlarm::~SmartAlarm()
{
}

void SmartAlarm::setTargetWakeTime(const QDateTime &time)
{
    m_targetWake = time;
}

QDateTime SmartAlarm::targetWakeTime() const
{
    return m_targetWake;
}

void SmartAlarm::setDesiredSleepHours(double hours)
{
    m_desiredHours = hours;
}

double SmartAlarm::desiredSleepHours() const
{
    return m_desiredHours;
}

// Example logic: if user's average hours < desired, shift the alarm a bit later
// or if they're oversleeping, shift earlier. Tweak as you like.
QDateTime SmartAlarm::calculateOptimalWakeTime(double userAvgHours) const
{
    // Start with target
    QDateTime result = m_targetWake;

    // If user is consistently sleeping less than desired, let them sleep 30 min more
    if (userAvgHours < m_desiredHours - 1.0) {
        // Shift alarm 30 minutes later
        result = result.addSecs(30 * 60);
    }
    // If user is oversleeping
    else if (userAvgHours > m_desiredHours + 1.0) {
        // Shift alarm 30 minutes earlier
        result = result.addSecs(-30 * 60);
    }
    // Otherwise just leave it as is

    return result;
}
