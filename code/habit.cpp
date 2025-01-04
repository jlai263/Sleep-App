#include "habit.h"

Habit::Habit()
    : m_frequency(HabitFrequency::Daily)
{
}

QString Habit::name() const
{
    return m_name;
}

void Habit::setName(const QString &n)
{
    m_name = n;
}

HabitFrequency Habit::frequency() const
{
    return m_frequency;
}

void Habit::setFrequency(HabitFrequency freq)
{
    m_frequency = freq;
}

QString Habit::notes() const
{
    return m_notes;
}

void Habit::setNotes(const QString &notes)
{
    m_notes = notes;
}

QList<QTime> Habit::reminderTimes() const
{
    return m_reminderTimes;
}

void Habit::setReminderTimes(const QList<QTime> &times)
{
    m_reminderTimes = times;
}
