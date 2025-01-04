#ifndef REMINDER_H
#define REMINDER_H

#include <QString>

// Base class for any kind of reminder
class Reminder
{
public:
    Reminder();
    virtual ~Reminder();

    void setTitle(const QString &title);
    QString title() const;

    void setDetails(const QString &details);
    QString details() const;

    // Virtual function to demonstrate polymorphism
    virtual void notify() const;

private:
    QString m_title;
    QString m_details;
};

#endif // REMINDER_H
