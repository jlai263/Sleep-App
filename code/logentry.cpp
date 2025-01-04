#include "logentry.h"
#include <QDebug>

LogEntry::LogEntry()
{
}

LogEntry::~LogEntry()
{
}

void LogEntry::setTime(const QDateTime &time)
{
    m_time = time;
}

QDateTime LogEntry::time() const
{
    return m_time;
}

void LogEntry::setMessage(const QString &msg)
{
    m_message = msg;
}

QString LogEntry::message() const
{
    return m_message;
}
