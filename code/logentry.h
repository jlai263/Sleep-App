#ifndef LOGENTRY_H
#define LOGENTRY_H

#include <QDateTime>
#include <QString>

// A generic log entry with timestamp and some message
class LogEntry
{
public:
    LogEntry();
    ~LogEntry();

    void setTime(const QDateTime &time);
    QDateTime time() const;

    void setMessage(const QString &msg);
    QString message() const;

private:
    QDateTime m_time;
    QString m_message;
};

#endif // LOGENTRY_H
