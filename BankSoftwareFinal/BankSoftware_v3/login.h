#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QString>
#include <QMessageBox>
#include <QLineEdit>

class Login : public QDialog
{
    Q_OBJECT
public:
    explicit Login(QWidget *parent = nullptr);
    void SetUsername(QString);
    QString GetUsername();
    void SetPassword(QString);
    QString GetPassword();
    bool ValidLoginResult();

private:
    QString username;
    QString password;
    bool validLogin = false;

    QFrame *line;
    QLabel *welcomeText;
    QLabel *usernameText;
    QLabel *passwordText;
    QLineEdit *usernameLineEdit;
    QLineEdit *passwordLineEdit;
    QPushButton *loginButton;

private slots:
    void ValidateCredentials();

};

#endif // LOGIN_H
