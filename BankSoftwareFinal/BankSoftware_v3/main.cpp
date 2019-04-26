#include <QApplication>
#include "window.h"
#include "user.h"
#include "login.h"

int main (int argc, char **argv)
{
    QApplication app(argc, argv);

    User user;
    Login *l = new Login();
    Window *w = new Window();

    l->SetUsername(user.GetUsername());
    l->SetPassword(user.GetPassword());

    l->exec();

    if (l->ValidLoginResult() == true)
    {
        w->show();
    }

    return app.exec();
}
