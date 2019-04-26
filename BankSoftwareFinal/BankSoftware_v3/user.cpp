#include "user.h"

User::User()
{
    username = "james";
    password = "password1234";  //the most secure, unguessable password ever
}

QString User::GetUsername() const
{
    return username;
}

QString User::GetPassword() const
{
    return password;
}
