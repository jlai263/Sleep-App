#include "habitreminder.h"
#include <QDebug>

HabitReminder::HabitReminder()
{
}

HabitReminder::~HabitReminder()
{
}

void HabitReminder::setHabit(const Habit &habit)
{
    m_habit = habit;
}

Habit HabitReminder::habit() const
{
    return m_habit;
}

void HabitReminder::notify() const
{
    // Example override of notify()
    qDebug() << "[Habit Reminder] Title:" << title()
             << " - Habit Name:" << m_habit.name()
             << " - Details:" << details();
}
