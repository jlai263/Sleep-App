#ifndef HABITREMINDER_H
#define HABITREMINDER_H

#include "habit.h"
#include "reminder.h"

// A reminder specifically tied to a habit
class HabitReminder : public Reminder

{
virtual void notify() const override;

public:
    HabitReminder();
    ~HabitReminder();

    void setHabit(const Habit &habit);
    Habit habit() const;

private:
    Habit m_habit;
};

#endif // HABITREMINDER_H
