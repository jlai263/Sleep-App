#ifndef HABITMANAGER_H
#define HABITMANAGER_H

#include <QVector>
#include <QJsonArray>
#include "habit.h"

class HabitManager
{
public:
    HabitManager();
    ~HabitManager();

    void addHabit(const Habit &habit);
    void removeHabit(int index);
    QVector<Habit> habits() const;


    void loadFromJson(const QJsonArray &arr);
    QJsonArray toJsonArray() const;

private:
    QVector<Habit> m_habits;
};

#endif // HABITMANAGER_H
