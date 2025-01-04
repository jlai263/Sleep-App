#ifndef SLEEPLOG_H
#define SLEEPLOG_H

#include <QDateTime>
#include <QVector>
#include <QString>

class SleepLog
{
public:
    struct Session {
        QDateTime start;
        QDateTime end;
        int quality;       // 1 to 5
        QString notes;     // arbitrary text
    };

    SleepLog();
    ~SleepLog();

    void addSession(const QDateTime &start,
                    const QDateTime &end,
                    int quality = 0,
                    const QString &notes = "");

    QVector<Session> sessions() const;

private:
    QVector<Session> m_sessions;
};

#endif // SLEEPLOG_H
