#ifndef USER_H
#define USER_H

#include <QString>

// Simple user class storing some basic info
class User
{
public:
    User();
    ~User();

    void setUsername(const QString &username);
    QString username() const;

    void setAge(int age);
    int age() const;

private:
    QString m_username;
    int m_age;
};

#endif // USER_H
