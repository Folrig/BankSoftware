#ifndef USER_H
#define USER_H
#include <QString>

class User
{
public:
    User();
    QString GetUsername() const;
    QString GetPassword() const;

private:
    QString username;
    QString password;

};

#endif // USER_H
