#include "reminder.h"
#include <QDebug>

Reminder::Reminder()
{
}

Reminder::~Reminder()
{
}

void Reminder::setTitle(const QString &title)
{
    m_title = title;
}

QString Reminder::title() const
{
    return m_title;
}

void Reminder::setDetails(const QString &details)
{
    m_details = details;
}

QString Reminder::details() const
{
    return m_details;
}

void Reminder::notify() const
{
    // Basic notify example (just logs to console)
    qDebug() << "[Reminder] Title:" << m_title
             << "- Details:" << m_details;
}
