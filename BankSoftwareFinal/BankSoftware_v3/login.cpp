#include "login.h"

Login::Login(QWidget *parent) : QDialog(parent)
{
    setAttribute(Qt::WA_DeleteOnClose);
    setFixedSize(450, 300);
    setWindowTitle("Welcome to the Bank of James");

    line = new QFrame(this);
    line->setFrameShape(QFrame::HLine);
    line->setGeometry(35, 50, 380, 12);
    line->setFrameShadow(QFrame::Sunken);
    line->setLineWidth(2);

    welcomeText = new QLabel(this);
    welcomeText->setText("Welcome to the Bank of James!");
    welcomeText->setGeometry(75, 10, 300, 30);
    welcomeText->setStyleSheet("font: 16pt;");

    usernameText = new QLabel(this);
    usernameText->setGeometry(115, 102, 80, 16);
    usernameText->setText("Username:");
    usernameText->setStyleSheet("font: 11pt;");

    passwordText = new QLabel(this);
    passwordText->setGeometry(115, 142, 80, 16);
    passwordText->setText("Password:");
    passwordText->setStyleSheet("font: 11pt;");

    usernameLineEdit = new QLineEdit(this);
    usernameLineEdit->setGeometry(210, 100, 120, 22);
    usernameLineEdit->setStyleSheet("font: 11pt;");
    usernameLineEdit->setPlaceholderText("username");

    passwordLineEdit = new QLineEdit(this);
    passwordLineEdit->setGeometry(210, 140, 120, 22);
    passwordLineEdit->setStyleSheet("font: 11pt;");
    passwordLineEdit->setPlaceholderText("password");
    passwordLineEdit->setEchoMode(QLineEdit::Password);

    loginButton = new QPushButton("Login", this);
    loginButton->setGeometry(140, 210, 150, 50);
    loginButton->setStyleSheet("font: 11pt;");
    loginButton->setToolTip("Login");
    connect(loginButton, SIGNAL(pressed()), this, SLOT(ValidateCredentials()));

}

void Login::SetUsername(QString u)
{
    username = u;
}

QString Login::GetUsername()
{
    return username;
}

void Login::SetPassword(QString p)
{
    password = p;
}

QString Login::GetPassword()
{
    return password;
}

void Login::ValidateCredentials()
{
    QString usernameInput = usernameLineEdit->text();
    QString passwordInput = passwordLineEdit->text();

    if (usernameInput == GetUsername() && passwordInput == GetPassword())
    {
        validLogin = true;
        hide();
    }
    else
    {
        QMessageBox::warning(this, "Invalid Entry", "Username = james\nPassword = password1234");
    }
}

bool Login::ValidLoginResult()
{
    return validLogin;
}
