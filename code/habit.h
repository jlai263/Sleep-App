#ifndef HABIT_H
#define HABIT_H

#include <QString>
#include <QDateTime>

enum class HabitFrequency {
    Daily,
    Weekly,
    Custom
};


class Habit
{
public:
    Habit();

    // Accessors
    QString name() const;
    void setName(const QString &n);

    HabitFrequency frequency() const;
    void setFrequency(HabitFrequency freq);

    QString notes() const;
    void setNotes(const QString &notes);

    // Times of day, for reminders (optional)
    QList<QTime> reminderTimes() const;
    void setReminderTimes(const QList<QTime> &times);

private:
    QString m_name;
    HabitFrequency m_frequency;
    QString m_notes;
    QList<QTime> m_reminderTimes;
};

#endif // HABIT_H
