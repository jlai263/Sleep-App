#include "sleepanalyzer.h"
#include <QDateTime>

// Make sure we include these so we can use HabitManager, Habit, HabitFrequency
#include "habitmanager.h"
#include "habit.h"

SleepAnalyzer::SleepAnalyzer() {}
SleepAnalyzer::~SleepAnalyzer() {}

void SleepAnalyzer::setSleepLog(const SleepLog &log)
{
    m_log = log;
}

double SleepAnalyzer::getTotalSleepHours() const
{
    double total = 0.0;
    for (const auto &sess : m_log.sessions()) {
        qint64 secs = sess.start.secsTo(sess.end);
        total += secs / 3600.0;
    }
    return total;
}

double SleepAnalyzer::getAverageSleepHours() const
{
    auto all = m_log.sessions();
    if (all.isEmpty())
        return 0.0;
    return getTotalSleepHours() / all.size();
}

double SleepAnalyzer::getTotalSleepHoursLast14Days() const
{
    double total = 0.0;
    QDateTime now = QDateTime::currentDateTime();
    QDateTime cutoff = now.addDays(-14);

    for (const auto &sess : m_log.sessions()) {
        if (sess.end >= cutoff) {
            qint64 secs = sess.start.secsTo(sess.end);
            total += secs / 3600.0;
        }
    }
    return total;
}

double SleepAnalyzer::getAverageSleepHoursLast14Days() const
{
    QDateTime now = QDateTime::currentDateTime();
    QDateTime cutoff = now.addDays(-14);

    double total = 0.0;
    int count = 0;
    for (const auto &sess : m_log.sessions()) {
        if (sess.end >= cutoff) {
            qint64 secs = sess.start.secsTo(sess.end);
            total += secs / 3600.0;
            count++;
        }
    }
    if (count == 0) return 0.0;
    return total / count;
}

// New helper for quality
double SleepAnalyzer::getAverageQualityLast14Days() const
{
    QDateTime now = QDateTime::currentDateTime();
    QDateTime cutoff = now.addDays(-14);

    double totalQuality = 0.0;
    int count = 0;
    for (const auto &sess : m_log.sessions()) {
        if (sess.end >= cutoff) {
            totalQuality += sess.quality; // assume it's 0..5
            count++;
        }
    }
    if (count == 0) return 0.0;
    return totalQuality / count;
}

// The adjusted Sleep Score
double SleepAnalyzer::adjustedSleepScore(const HabitManager &habits)
{
    double hours14 = getAverageSleepHoursLast14Days();
    double quality14 = getAverageQualityLast14Days();
    double score = hours14 + quality14; // baseline

    // incorporate habits
    for (auto &h : habits.habits()) {
        if (h.name() == "Exercise" && h.frequency() == HabitFrequency::Daily) {
            score += 0.3;
        }
        if (h.name() == "Drink water" && h.frequency() == HabitFrequency::Daily) {
            score += 0.2;
        }
    }

    // penalize if not enough sleep
    if (hours14 < 6.0) {
        score -= 1.0;
    } else if (hours14 < 7.0) {
        score -= 0.5;
    }

    return score;
}

const SleepLog & SleepAnalyzer::getLog() const
{
    return m_log;
}
