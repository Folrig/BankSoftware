#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H
#include <QVector>

class BankAccount
{
public:
    BankAccount();
    double GetBalance() const;
    int GetAccountNum() const;
    void MakeDeposit(double);
    virtual void MakeWithdrawl(double) = 0;
    double GetTransactionHistory(int) const;
    void RecordTransaction(double);
    QVector <double> GetAllTransactions() const;

protected:
    double balance;
    int accountNum;
    QVector <double> transactionHistory;

};

#endif // BANKACCOUNT_H
