#include "habitmanager.h"
#include <QJsonObject>
#include <QJsonValue>
#include <QDebug>

HabitManager::HabitManager() {}
HabitManager::~HabitManager() {}

void HabitManager::addHabit(const Habit &habit)
{
    m_habits.append(habit);
}

void HabitManager::removeHabit(int index)
{
    if (index >= 0 && index < m_habits.size()) {
        m_habits.removeAt(index);
    }
}

QVector<Habit> HabitManager::habits() const
{
    return m_habits;
}

// Convert from JSON array to internal vector of Habit
void HabitManager::loadFromJson(const QJsonArray &arr)
{
    m_habits.clear();
    for (auto val : arr) {
        QJsonObject obj = val.toObject();
        Habit h;

        // name
        QString nameStr = obj["name"].toString();
        h.setName(nameStr);

        // frequency
        QString freqStr = obj["frequency"].toString(); // e.g. "Daily"
        if (freqStr == "Daily") {
            h.setFrequency(HabitFrequency::Daily);
        } else if (freqStr == "Weekly") {
            h.setFrequency(HabitFrequency::Weekly);
        } else {
            h.setFrequency(HabitFrequency::Custom);
        }

        // notes
        h.setNotes(obj["notes"].toString());

        // reminder times (optional)
        QJsonArray timesArr = obj["reminderTimes"].toArray();
        QList<QTime> timesList;
        for (auto tVal : timesArr) {
            QString tStr = tVal.toString();
            QTime time = QTime::fromString(tStr, "HH:mm");
            if (time.isValid()) {
                timesList.append(time);
            }
        }
        h.setReminderTimes(timesList);

        m_habits.append(h);
    }
}

// Convert from internal habits to JSON array
QJsonArray HabitManager::toJsonArray() const
{
    QJsonArray arr;
    for (auto &h : m_habits) {
        QJsonObject obj;
        obj["name"] = h.name();

        // freq to string
        QString freqStr;
        switch (h.frequency()) {
        case HabitFrequency::Daily:  freqStr = "Daily";  break;
        case HabitFrequency::Weekly: freqStr = "Weekly"; break;
        default:                     freqStr = "Custom"; break;
        }
        obj["frequency"] = freqStr;

        obj["notes"] = h.notes();

        // reminder times
        QJsonArray timesArr;
        for (auto &t : h.reminderTimes()) {
            timesArr.append(t.toString("HH:mm"));
        }
        obj["reminderTimes"] = timesArr;

        arr.append(obj);
    }
    return arr;
}
