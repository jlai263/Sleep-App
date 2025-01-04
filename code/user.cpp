#include "user.h"
#include <QDebug>

User::User()
    : m_age(0)
{
}

User::~User()
{
}

void User::setUsername(const QString &username)
{
    m_username = username;
}

QString User::username() const
{
    return m_username;
}

void User::setAge(int age)
{
    m_age = age;
}

int User::age() const
{
    return m_age;
}
