#ifndef WINDOW_H
#define WINDOW_H

#include <QMainWindow>
#include <QObject>
#include <QPushButton>
#include <QLabel>
#include <QString>
#include <QFrame>
#include <QInputDialog>
#include "checkingaccount.h"
#include "savingsaccount.h"

class Window : public QMainWindow
{
    Q_OBJECT
public:
    explicit Window(QWidget *parent = nullptr);
    CheckingAccount checkingAcct;
    SavingsAccount savingsAcct;
    QString GetUsername() const { return username; }
    int GetAcctNum() const { return acctNum; }

private:
    QString username = "Mr. James";
    int acctNum = 13377;

    QPushButton *checkingWindow;
    QPushButton *savingsWindow;
    QPushButton *depositWindowButton;
    QPushButton *withdrawWindowButton;
    QPushButton *transferWindowButton;
    QPushButton *checkHistoryButton;
    QPushButton *okButton;
    QPushButton *quitButton;

    QFrame *line;

    QLabel *welcomeText;
    QLabel *usernameLabel;
    QLabel *acctNumText;
    QLabel *acctNumLabel;
    QLabel *checkingBalanceText;
    QLabel *checkingBalanceLabel;
    QLabel *savingsBalanceText;
    QLabel *savingsBalanceLabel;

private slots:
    void CheckingWindowShow();
    void SavingsWindowShow();
    void DepositWindowShow();
    void MakeCheckingDeposit();
    void MakeSavingsDeposit();
    void WithdrawWindowShow();
    void MakeCheckingWithdrawl();
    void MakeSavingsWithdrawl();
    void TransferWindowShow();
    void TransferCheckingToSavings();
    void TransferSavingsToChecking();
    void HistoryWindowShow();

};

#endif // WINDOW_H
