#include "window.h"

Window::Window(QWidget *parent) : QMainWindow(parent)
{
    setFixedSize(935, 580);
    setWindowTitle("Bank of James");

    welcomeText = new QLabel(this);
    welcomeText->setText("Welcome, ");
    welcomeText->setGeometry(40, 60, 70, 20);
    welcomeText->setStyleSheet("font: 11pt;");

    usernameLabel = new QLabel(this);
    usernameLabel->setText(GetUsername());
    usernameLabel->setGeometry(109, 60, 70, 20);
    usernameLabel->setStyleSheet("font: 11pt;");

    acctNumText = new QLabel(this);
    acctNumText->setText("Account Number: ");
    acctNumText->setGeometry(210, 60, 130, 20);
    acctNumText->setStyleSheet("font: 11pt;");

    acctNumLabel = new QLabel(this);
    acctNumLabel->setNum(GetAcctNum());
    acctNumLabel->setGeometry(325, 60, 70, 20);
    acctNumLabel->setStyleSheet("font: 11pt;");

    checkingBalanceText = new QLabel(this);
    checkingBalanceText->setText("Checking Balance: $");
    checkingBalanceText->setGeometry(470, 60, 130, 20);
    checkingBalanceText->setStyleSheet("font: 11pt;");

    checkingBalanceLabel = new QLabel(this);
    checkingBalanceLabel->setText(QString::number(checkingAcct.GetBalance(), 'f', 2));
    checkingBalanceLabel->setGeometry(599, 60, 65, 20);
    checkingBalanceLabel->setStyleSheet("font: 11pt;");

    savingsBalanceText = new QLabel(this);
    savingsBalanceText->setText("Savings Balance: $");
    savingsBalanceText->setGeometry(690, 60, 130, 20);
    savingsBalanceText->setStyleSheet("font: 11pt;");

    savingsBalanceLabel = new QLabel(this);
    savingsBalanceLabel->setText(QString::number(savingsAcct.GetBalance(), 'f', 2));
    savingsBalanceLabel->setGeometry(812, 60, 65, 20);
    savingsBalanceLabel->setStyleSheet("font: 11pt;");

    line = new QFrame(this);
    line->setFrameShape(QFrame::HLine);
    line->setGeometry(10, 87, 915, 5);
    line->setFrameShadow(QFrame::Sunken);
    line->setLineWidth(2);

    checkingWindow = new QPushButton("Checking Account", this);
    checkingWindow->setGeometry(105, 140, 179, 30);
    checkingWindow->setStyleSheet("font: 10pt;");
    checkingWindow->setToolTip("Checking account info");
    connect(checkingWindow, SIGNAL(pressed()), this, SLOT(CheckingWindowShow()));

    savingsWindow = new QPushButton("Savings Account", this);
    savingsWindow->setGeometry(105, 200, 179, 30);
    savingsWindow->setStyleSheet("font: 10pt;");
    savingsWindow->setToolTip("Savings account info");
    connect(savingsWindow, SIGNAL(pressed()), this, SLOT(SavingsWindowShow()));

    depositWindowButton = new QPushButton("Make a Deposit", this);
    depositWindowButton->setGeometry(105, 260, 179, 30);
    depositWindowButton->setStyleSheet("font: 10pt;");
    depositWindowButton->setToolTip("Deposit funds");
    connect(depositWindowButton, SIGNAL(pressed()), this, SLOT(DepositWindowShow()));

    withdrawWindowButton = new QPushButton("Make a Withdrawl", this);
    withdrawWindowButton->setGeometry(105, 320, 179, 30);
    withdrawWindowButton->setStyleSheet("font: 10pt;");
    withdrawWindowButton->setToolTip("Withdraw funds");
    connect(withdrawWindowButton, SIGNAL(pressed()), this, SLOT(WithdrawWindowShow()));

    transferWindowButton = new QPushButton("Transfer Funds", this);
    transferWindowButton->setGeometry(105, 380, 179, 30);
    transferWindowButton->setStyleSheet("font: 10pt;");
    transferWindowButton->setToolTip("Transfer funds between accounts");
    connect(transferWindowButton, SIGNAL(pressed()), this, SLOT(TransferWindowShow()));

    checkHistoryButton = new QPushButton("Transaction History", this);
    checkHistoryButton->setGeometry(105, 440, 179, 30);
    checkHistoryButton->setStyleSheet("font: 10pt;");
    checkHistoryButton->setToolTip("View all past transactions");
    connect(checkHistoryButton, SIGNAL(pressed()), this, SLOT(HistoryWindowShow()));

    quitButton = new QPushButton("Quit", this);
    quitButton->setGeometry(105, 500, 179, 30);
    quitButton->setStyleSheet("font: 10pt;");
    quitButton->setToolTip("Quit the program");
    connect(quitButton, SIGNAL(pressed()), this, SLOT(close()));

}

void Window::CheckingWindowShow()
{
    QWidget *checkingWindow = new QWidget;
    checkingWindow->setFixedSize(600, 300);
    checkingWindow->setWindowTitle("Checking Account Info");

    QLabel *checkingWindowAcctText = new QLabel(checkingWindow);
    checkingWindowAcctText->setText("Checking Account Number: ");
    checkingWindowAcctText->setGeometry(55, 55, 180, 20);
    checkingWindowAcctText->setStyleSheet("font: 11pt;");

    QLabel *checkingWindowAcctNum = new QLabel(checkingWindow);
    checkingWindowAcctNum->setNum(checkingAcct.GetAccountNum());
    checkingWindowAcctNum->setGeometry(234, 55, 50, 20);
    checkingWindowAcctNum->setStyleSheet("font: 11pt;");

    QLabel *checkingWindowBalanceLabel = new QLabel(checkingWindow);
    checkingWindowBalanceLabel->setText("Checking Balance: $");
    checkingWindowBalanceLabel->setGeometry(335, 55, 180, 20);
    checkingWindowBalanceLabel->setStyleSheet("font: 11pt;");

    QLabel *checkingWindowBalance = new QLabel(checkingWindow);
    checkingWindowBalance->setText(QString::number(checkingAcct.GetBalance(), 'f', 2));
    checkingWindowBalance->setGeometry(470, 55, 50, 20);
    checkingWindowBalance->setStyleSheet("font: 11pt;");

    okButton = new QPushButton("Okay", checkingWindow);
    okButton->setGeometry(210, 200, 179, 30);
    okButton->setStyleSheet("font: 10pt;");
    okButton->setToolTip("Close the window");
    connect(okButton, SIGNAL(pressed()), checkingWindow, SLOT(close()));

    checkingWindow->show();
}

void Window::SavingsWindowShow()
{
    QWidget *savingsWindow = new QWidget;
    savingsWindow->setFixedSize(600, 300);
    savingsWindow->setWindowTitle("Savings Account Info");

    QLabel *savingsWindowAcctText = new QLabel(savingsWindow);
    savingsWindowAcctText->setText("Savings Account Number: ");
    savingsWindowAcctText->setGeometry(59, 55, 180, 20);
    savingsWindowAcctText->setStyleSheet("font: 11pt;");

    QLabel *savingsWindowAcctNum = new QLabel(savingsWindow);
    savingsWindowAcctNum->setNum(savingsAcct.GetAccountNum());
    savingsWindowAcctNum->setGeometry(234, 55, 50, 20);
    savingsWindowAcctNum->setStyleSheet("font: 11pt;");

    QLabel *savingsWindowBalanceLabel = new QLabel(savingsWindow);
    savingsWindowBalanceLabel->setText("Savings Balance: $");
    savingsWindowBalanceLabel->setGeometry(339, 55, 180, 20);
    savingsWindowBalanceLabel->setStyleSheet("font: 11pt;");

    QLabel *savingsWindowBalance = new QLabel(savingsWindow);
    savingsWindowBalance->setText(QString::number(savingsAcct.GetBalance(), 'f', 2));
    savingsWindowBalance->setGeometry(470, 55, 50, 20);
    savingsWindowBalance->setStyleSheet("font: 11pt;");

    okButton = new QPushButton("Okay", savingsWindow);
    okButton->setGeometry(210, 200, 179, 30);
    okButton->setStyleSheet("font: 10pt;");
    okButton->setToolTip("Close the window");
    connect(okButton, SIGNAL(pressed()), savingsWindow, SLOT(close()));

    savingsWindow->show();
}

void Window::DepositWindowShow()
{
    QWidget *depositWindow = new QWidget();
    depositWindow->setFixedSize(500, 320);
    depositWindow->setWindowTitle("Deposit Account Selection");

    QLabel *depositWindowText = new QLabel(depositWindow);
    depositWindowText->setGeometry(40, 30, 330, 25);
    depositWindowText->setText("Select the account to deposit to:");
    depositWindowText->setStyleSheet("font: 12pt;");

    QFrame *windowLine = new QFrame(this);
    windowLine->setFrameShape(QFrame::HLine);
    windowLine->setGeometry(10, 46, 480, 5);
    windowLine->setFrameShadow(QFrame::Sunken);
    windowLine->setLineWidth(2);

    QPushButton *depositChecking = new QPushButton("Checking", depositWindow);
    depositChecking->setGeometry(55, 85, 130, 30);
    depositChecking->setStyleSheet("font: 10pt;");
    depositChecking->setToolTip("Deposit to checking");
    connect(depositChecking, SIGNAL(pressed()), this, SLOT(MakeCheckingDeposit()));
    connect(depositChecking, SIGNAL(pressed()), depositWindow, SLOT(close()));

    QPushButton *depositSavings = new QPushButton("Savings", depositWindow);
    depositSavings->setGeometry(310, 85, 130, 30);
    depositSavings->setStyleSheet("font: 10pt;");
    depositSavings->setToolTip("Deposit to savings");
    connect(depositSavings, SIGNAL(pressed()), this, SLOT(MakeSavingsDeposit()));
    connect(depositSavings, SIGNAL(pressed()), depositWindow, SLOT(close()));

    okButton = new QPushButton("Close Window", depositWindow);
    okButton->setGeometry(185, 210, 130, 30);
    okButton->setStyleSheet("font: 10pt;");
    okButton->setToolTip("Close the window");
    connect(okButton, SIGNAL(pressed()), depositWindow, SLOT(close()));

    depositWindow->show();
}

void Window::MakeCheckingDeposit()
{
    bool ok;
    double depositAmt = QInputDialog::getDouble(this, tr("Deposit to Checking"), tr("Amount to deposit:"), 0.00, 0.00, 10000000.00, 2, &ok);

    if (ok)
    {
        if (depositAmt >= 0.00)
        {
            checkingAcct.MakeDeposit(depositAmt);
            checkingAcct.RecordTransaction(depositAmt);
            checkingBalanceLabel->setText(QString::number(checkingAcct.GetBalance(), 'f', 2));
        }
        else
        {
            QWidget *error001 = new QWidget;
            error001->setFixedSize(350, 200);

            QLabel *errorMessage001 = new QLabel(error001);
            errorMessage001->setText("Please deposit a positive number!");
            errorMessage001->setGeometry(60, 60, 240, 30);
            errorMessage001->setStyleSheet("font: 11pt;");

            QPushButton *closeButton = new QPushButton("Okay", error001);
            closeButton->setGeometry(110, 130, 130, 30);
            closeButton->setStyleSheet("font: 10pt;");
            closeButton->setToolTip("Close the window");
            connect(closeButton, SIGNAL(pressed()), error001, SLOT(close()));

            error001->show();
        }
    }
}

void Window::MakeSavingsDeposit()
{
    bool ok;
    double depositAmt = QInputDialog::getDouble(this, tr("Deposit to Savings"), tr("Amount to deposit:"), 0.00, 0.00, 10000000.00, 2, &ok);

    if (ok)
    {
        if (depositAmt >= 0.00)
        {
            savingsAcct.MakeDeposit(depositAmt);
            savingsAcct.RecordTransaction(depositAmt);
            savingsBalanceLabel->setText(QString::number(savingsAcct.GetBalance(), 'f', 2));
        }
        else
        {
            QWidget *error001 = new QWidget;
            error001->setFixedSize(350, 200);

            QLabel *errorMessage001 = new QLabel(error001);
            errorMessage001->setText("Please deposit a positive number!");
            errorMessage001->setGeometry(60, 60, 240, 30);
            errorMessage001->setStyleSheet("font: 11pt;");

            QPushButton *closeButton = new QPushButton("Okay", error001);
            closeButton->setGeometry(110, 130, 130, 30);
            closeButton->setStyleSheet("font: 10pt;");
            closeButton->setToolTip("Close the window");
            connect(closeButton, SIGNAL(pressed()), error001, SLOT(close()));

            error001->show();
        }
    }
}

void Window::WithdrawWindowShow()
{
    QWidget *withdrawWindow = new QWidget();
    withdrawWindow->setFixedSize(500, 320);
    withdrawWindow->setWindowTitle("Withdrawl Account Selection");

    QLabel *withdrawWindowText = new QLabel(withdrawWindow);
    withdrawWindowText->setGeometry(40, 30, 330, 25);
    withdrawWindowText->setText("Select the account to withdraw from:");
    withdrawWindowText->setStyleSheet("font: 12pt;");

    QFrame *windowLine = new QFrame(this);
    windowLine->setFrameShape(QFrame::HLine);
    windowLine->setGeometry(10, 51, 480, 5);
    windowLine->setFrameShadow(QFrame::Sunken);
    windowLine->setLineWidth(2);

    QPushButton *withdrawChecking = new QPushButton("Checking", withdrawWindow);
    withdrawChecking->setGeometry(55, 85, 130, 30);
    withdrawChecking->setStyleSheet("font: 10pt;");
    withdrawChecking->setToolTip("Withdraw from checking");
    connect(withdrawChecking, SIGNAL(pressed()), this, SLOT(MakeCheckingWithdrawl()));
    connect(withdrawChecking, SIGNAL(pressed()), withdrawWindow, SLOT(close()));

    QPushButton *withdrawSavings = new QPushButton("Savings", withdrawWindow);
    withdrawSavings->setGeometry(310, 85, 130, 30);
    withdrawSavings->setStyleSheet("font: 10pt;");
    withdrawSavings->setToolTip("Withdraw from savings");
    connect(withdrawSavings, SIGNAL(pressed()), this, SLOT(MakeSavingsWithdrawl()));
    connect(withdrawSavings, SIGNAL(pressed()), withdrawWindow, SLOT(close()));

    okButton = new QPushButton("Close Window", withdrawWindow);
    okButton->setGeometry(185, 210, 130, 30);
    okButton->setStyleSheet("font: 10pt;");
    okButton->setToolTip("Close the window");
    connect(okButton, SIGNAL(pressed()), withdrawWindow, SLOT(close()));

    withdrawWindow->show();
}

void Window::MakeCheckingWithdrawl()
{
    bool ok;
    double withdrawlAmt = QInputDialog::getDouble(this, tr("Withdraw from Checking"), tr("Amount to withdraw:"), 0.00, 0.00, 10000000.00, 2, &ok);

    if (ok)
    {
        if (withdrawlAmt < 0)
        {
            QWidget *error001 = new QWidget;
            error001->setFixedSize(350, 200);

            QLabel *errorMessage001 = new QLabel(error001);
            errorMessage001->setText("Please withdrawl a positive number!");
            errorMessage001->setGeometry(60, 60, 240, 30);
            errorMessage001->setStyleSheet("font: 11pt;");

            QPushButton *closeButton = new QPushButton("Okay", error001);
            closeButton->setGeometry(110, 130, 130, 30);
            closeButton->setStyleSheet("font: 10pt;");
            closeButton->setToolTip("Close the window");
            connect(closeButton, SIGNAL(pressed()), error001, SLOT(close()));

            error001->show();
        }
        else if (checkingAcct.GetBalance() <= 0)
        {
            QWidget *error001 = new QWidget;
            error001->setFixedSize(350, 200);

            QLabel *errorMessage001 = new QLabel(error001);
            errorMessage001->setText("Account balance below $0.00!");
            errorMessage001->setGeometry(60, 60, 240, 30);
            errorMessage001->setStyleSheet("font: 11pt;");

            QPushButton *closeButton = new QPushButton("Okay", error001);
            closeButton->setGeometry(110, 130, 130, 30);
            closeButton->setStyleSheet("font: 10pt;");
            closeButton->setToolTip("Close the window");
            connect(closeButton, SIGNAL(pressed()), error001, SLOT(close()));

            error001->show();
        }
        else
        {
            checkingAcct.MakeWithdrawl(withdrawlAmt);
            checkingAcct.RecordTransaction(-(withdrawlAmt));
            checkingBalanceLabel->setText(QString::number(checkingAcct.GetBalance(), 'f', 2));
        }
    }
}

void Window::MakeSavingsWithdrawl()
{
    bool ok;
    double withdrawlAmt = QInputDialog::getDouble(this, tr("Withdraw from Savings"), tr("Amount to withdraw:"), 0.00, 0.00, 10000000.00, 2, &ok);

    if (ok)
    {
        if (withdrawlAmt < 0)
        {
            QWidget *error001 = new QWidget;
            error001->setFixedSize(350, 200);

            QLabel *errorMessage001 = new QLabel(error001);
            errorMessage001->setText("Please withdrawl a positive number!");
            errorMessage001->setGeometry(60, 60, 240, 30);
            errorMessage001->setStyleSheet("font: 11pt;");

            QPushButton *closeButton = new QPushButton("Okay", error001);
            closeButton->setGeometry(110, 130, 130, 30);
            closeButton->setStyleSheet("font: 10pt;");
            closeButton->setToolTip("Close the window");
            connect(closeButton, SIGNAL(pressed()), error001, SLOT(close()));

            error001->show();
        }
        else if (savingsAcct.GetBalance() <= 0)
        {
            QWidget *error001 = new QWidget;
            error001->setFixedSize(350, 200);

            QLabel *errorMessage001 = new QLabel(error001);
            errorMessage001->setText("Account balance at $0.00!");
            errorMessage001->setGeometry(60, 60, 240, 30);
            errorMessage001->setStyleSheet("font: 11pt;");

            QPushButton *closeButton = new QPushButton("Okay", error001);
            closeButton->setGeometry(110, 130, 130, 30);
            closeButton->setStyleSheet("font: 10pt;");
            closeButton->setToolTip("Close the window");
            connect(closeButton, SIGNAL(pressed()), error001, SLOT(close()));

            error001->show();
        }
        else if (withdrawlAmt > savingsAcct.GetBalance())
        {
            QWidget *error001 = new QWidget;
            error001->setFixedSize(350, 200);

            QLabel *errorMessage001 = new QLabel(error001);
            errorMessage001->setText("Insufficient funds for withdrawl!");
            errorMessage001->setGeometry(60, 60, 240, 30);
            errorMessage001->setStyleSheet("font: 11pt;");

            QPushButton *closeButton = new QPushButton("Okay", error001);
            closeButton->setGeometry(110, 130, 130, 30);
            closeButton->setStyleSheet("font: 10pt;");
            closeButton->setToolTip("Close the window");
            connect(closeButton, SIGNAL(pressed()), error001, SLOT(close()));

            error001->show();
        }
        else
        {
            savingsAcct.MakeWithdrawl(withdrawlAmt);
            savingsAcct.RecordTransaction(-(withdrawlAmt));
            savingsBalanceLabel->setText(QString::number(savingsAcct.GetBalance(), 'f', 2));
        }
    }
}

void Window::TransferWindowShow()
{
    QWidget *transferWindow = new QWidget();
    transferWindow->setFixedSize(500, 320);
    transferWindow->setWindowTitle("Transfer Account Selection");

    QLabel *transferWindowText = new QLabel(transferWindow);
    transferWindowText->setGeometry(40, 40, 330, 20);
    transferWindowText->setText("Select the accounts to transfer between:");
    transferWindowText->setStyleSheet("font: 12pt;");

    QFrame *windowLine = new QFrame(this);
    windowLine->setFrameShape(QFrame::HLine);
    windowLine->setGeometry(10, 46, 480, 5);
    windowLine->setFrameShadow(QFrame::Sunken);
    windowLine->setLineWidth(2);

    QPushButton *transferToSavings = new QPushButton("FROM checking TO savings", transferWindow);
    transferToSavings->setGeometry(37, 90, 163, 30);
    transferToSavings->setStyleSheet("font: 10pt;");
    transferToSavings->setToolTip("Transfer to savings");
    connect(transferToSavings, SIGNAL(pressed()), this, SLOT(TransferCheckingToSavings()));
    connect(transferToSavings, SIGNAL(pressed()), transferWindow, SLOT(close()));

    QPushButton *transferToChecking = new QPushButton("FROM savings TO checking", transferWindow);
    transferToChecking->setGeometry(310, 90, 163, 30);
    transferToChecking->setStyleSheet("font: 10pt;");
    transferToChecking->setToolTip("Transfer to checking");
    connect(transferToChecking, SIGNAL(pressed()), this, SLOT(TransferSavingsToChecking()));
    connect(transferToChecking, SIGNAL(pressed()), transferWindow, SLOT(close()));

    okButton = new QPushButton("Close Window", transferWindow);
    okButton->setGeometry(185, 215, 130, 30);
    okButton->setStyleSheet("font: 10pt;");
    okButton->setToolTip("Close the window");
    connect(okButton, SIGNAL(pressed()), transferWindow, SLOT(close()));

    transferWindow->show();
}

void Window::TransferCheckingToSavings()
{
    bool ok;
    double transferAmt = QInputDialog::getDouble(this, tr("Transfer from Checking to Savings"), tr("Amount to transfer:"), 0.00, 0.00, 10000000.00, 2, &ok);

    if (ok)
    {
        if (transferAmt < 0)
        {
            QWidget *error001 = new QWidget;
            error001->setFixedSize(350, 200);

            QLabel *errorMessage001 = new QLabel(error001);
            errorMessage001->setText("Please transfer a positive number!");
            errorMessage001->setGeometry(60, 60, 250, 30);
            errorMessage001->setStyleSheet("font: 11pt;");

            QPushButton *closeButton = new QPushButton("Okay", error001);
            closeButton->setGeometry(110, 130, 130, 30);
            closeButton->setStyleSheet("font: 10pt;");
            closeButton->setToolTip("Close the window");
            connect(closeButton, SIGNAL(pressed()), error001, SLOT(close()));

            error001->show();
        }
        else if (transferAmt > checkingAcct.GetBalance())
        {
            QWidget *error001 = new QWidget;
            error001->setFixedSize(350, 200);

            QLabel *errorMessage001 = new QLabel(error001);
            errorMessage001->setText("You do not have sufficient\nfunds for the transfer");
            errorMessage001->setGeometry(50, 60, 250, 30);
            errorMessage001->setStyleSheet("font: 11pt;");

            QPushButton *closeButton = new QPushButton("Okay", error001);
            closeButton->setGeometry(110, 130, 130, 30);
            closeButton->setStyleSheet("font: 10pt;");
            closeButton->setToolTip("Close the window");
            connect(closeButton, SIGNAL(pressed()), error001, SLOT(close()));

            error001->show();
        }
        else
        {
            savingsAcct.MakeDeposit(transferAmt);
            checkingAcct.MakeWithdrawl(transferAmt);
            savingsAcct.RecordTransaction(transferAmt);
            checkingAcct.RecordTransaction(-(transferAmt));
            savingsBalanceLabel->setText(QString::number(savingsAcct.GetBalance(), 'f', 2));
            checkingBalanceLabel->setText(QString::number(checkingAcct.GetBalance(), 'f', 2));
        }
    }
}

void Window::TransferSavingsToChecking()
{
    bool ok;
    double transferAmt = QInputDialog::getDouble(this, tr("Transfer from Savings to Checking"), tr("Amount to transfer:"), 0.00, 0.00, 10000000.00, 2, &ok);

    if (ok)
    {
        if (transferAmt < 0)
        {
            QWidget *error001 = new QWidget;
            error001->setFixedSize(350, 200);

            QLabel *errorMessage001 = new QLabel(error001);
            errorMessage001->setText("Please transfer a positive number!");
            errorMessage001->setGeometry(60, 60, 250, 30);
            errorMessage001->setStyleSheet("font: 11pt;");

            QPushButton *closeButton = new QPushButton("Okay", error001);
            closeButton->setGeometry(110, 130, 130, 30);
            closeButton->setStyleSheet("font: 10pt;");
            closeButton->setToolTip("Close the window");
            connect(closeButton, SIGNAL(pressed()), error001, SLOT(close()));

            error001->show();
        }
        else if (transferAmt > savingsAcct.GetBalance())
        {
            QWidget *error001 = new QWidget;
            error001->setFixedSize(350, 200);

            QLabel *errorMessage001 = new QLabel(error001);
            errorMessage001->setText("You do not have sufficient\nfunds for the transfer");
            errorMessage001->setGeometry(60, 60, 250, 30);
            errorMessage001->setStyleSheet("font: 11pt;");

            QPushButton *closeButton = new QPushButton("Okay", error001);
            closeButton->setGeometry(110, 130, 130, 30);
            closeButton->setStyleSheet("font: 10pt;");
            closeButton->setToolTip("Close the window");
            connect(closeButton, SIGNAL(pressed()), error001, SLOT(close()));

            error001->show();
        }
        else
        {
            checkingAcct.MakeDeposit(transferAmt);
            savingsAcct.MakeWithdrawl(transferAmt);
            checkingAcct.RecordTransaction(transferAmt);
            savingsAcct.RecordTransaction(-(transferAmt));
            checkingBalanceLabel->setText(QString::number(checkingAcct.GetBalance(), 'f', 2));
            savingsBalanceLabel->setText(QString::number(savingsAcct.GetBalance(), '2', 2));
        }
    }
}

void Window::HistoryWindowShow()
{
    QWidget *historyWindow = new QWidget;
    historyWindow->setFixedSize(550, 660);
    historyWindow->setWindowTitle("Transaction History");

    QFrame *windowHLine = new QFrame(historyWindow);
    windowHLine->setFrameShape(QFrame::HLine);
    windowHLine->setGeometry(20, 60, 512, 15);
    windowHLine->setFrameShadow(QFrame::Sunken);
    windowHLine->setLineWidth(1);

    QFrame *windowVLine = new QFrame(historyWindow);
    windowVLine->setFrameShape(QFrame::VLine);
    windowVLine->setGeometry(260, 70, 20, 505);
    windowVLine->setFrameShadow(QFrame::Sunken);
    windowVLine->setLineWidth(1);

    QLabel *recentHistory = new QLabel(historyWindow);
    recentHistory->setText("Recent Transaction History");
    recentHistory->setGeometry(40, 20, 242, 30);
    recentHistory->setStyleSheet("font: 15pt;");

    QLabel *checkingHistoryText = new QLabel(historyWindow);
    checkingHistoryText->setText("Checking Account");
    checkingHistoryText->setGeometry(40, 80, 132, 21);
    checkingHistoryText->setStyleSheet("font: 12pt;");

    QLabel *savingsHistoryText = new QLabel(historyWindow);
    savingsHistoryText->setText("Savings Account");
    savingsHistoryText->setGeometry(290, 80, 132, 21);
    savingsHistoryText->setStyleSheet("font: 12pt;");

    QPushButton *closeButton = new QPushButton("Okay", historyWindow);
    closeButton->setGeometry(205, 600, 130, 30);
    closeButton->setStyleSheet("font: 10pt;");
    closeButton->setToolTip("Close window");
    connect(closeButton, SIGNAL(pressed()), historyWindow, SLOT(close()));

    int yAxisOffset = 110;
    for (int i = 0; i < checkingAcct.GetAllTransactions().size(); i++)
    {
        QLabel *checkingTransactionType = new QLabel(historyWindow);
        if (checkingAcct.GetTransactionHistory(i) > 0)
        {
            checkingTransactionType->setText("Deposit");
        }
        else
        {
            checkingTransactionType->setText("Withdrawl");
        }
        checkingTransactionType->setGeometry(50, yAxisOffset, 70, 16);
        checkingTransactionType->setStyleSheet("font: 11pt;");

        QLabel *checkingDollarSign = new QLabel(historyWindow);
        checkingDollarSign->setText("$");
        checkingDollarSign->setGeometry(140, yAxisOffset, 16, 16);
        checkingDollarSign->setStyleSheet("font: 11pt;");

        QLabel *checkingTransactionStatement = new QLabel(historyWindow);
        checkingTransactionStatement->setText(QString::number(checkingAcct.GetTransactionHistory(i), 'f', 2));
        checkingTransactionStatement->setGeometry(150, yAxisOffset, 111, 16);
        checkingTransactionStatement->setStyleSheet("font: 11pt;");

        yAxisOffset += 25;
    }

    yAxisOffset = 110;
    for (int i = 0; i < savingsAcct.GetAllTransactions().size(); i++)
    {
        QLabel *savingsTransactionType = new QLabel(historyWindow);
        if (savingsAcct.GetTransactionHistory(i) > 0)
        {
            savingsTransactionType->setText("Deposit");
        }
        else
        {
            savingsTransactionType->setText("Withdrawl");
        }
        savingsTransactionType->setGeometry(300, yAxisOffset, 70, 16);
        savingsTransactionType->setStyleSheet("font: 11pt;");

        QLabel *savingsDollarSign = new QLabel(historyWindow);
        savingsDollarSign->setText("$");
        savingsDollarSign->setGeometry(390, yAxisOffset, 16, 16);
        savingsDollarSign->setStyleSheet("font: 11pt;");

        QLabel *savingsTransactionStatement = new QLabel(historyWindow);
        savingsTransactionStatement->setText(QString::number(savingsAcct.GetTransactionHistory(i), 'f', 2));
        savingsTransactionStatement->setGeometry(400, yAxisOffset, 111, 16);
        savingsTransactionStatement->setStyleSheet("font: 11pt;");

        yAxisOffset += 25;
    }

    historyWindow->show();
}
