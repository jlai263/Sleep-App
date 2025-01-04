#include "sleeplog.h"

SleepLog::SleepLog() {}
SleepLog::~SleepLog() {}

void SleepLog::addSession(const QDateTime &start,
                          const QDateTime &end,
                          int quality,
                          const QString &notes)
{
    Session s;
    s.start   = start;
    s.end     = end;
    s.quality = quality;
    s.notes   = notes;
    m_sessions.append(s);
}

QVector<SleepLog::Session> SleepLog::sessions() const
{
    return m_sessions;
}
