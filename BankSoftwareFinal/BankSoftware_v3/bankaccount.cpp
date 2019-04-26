#include "bankaccount.h"

BankAccount::BankAccount()
{

}

double BankAccount::GetBalance() const
{
    return balance;
}

int BankAccount::GetAccountNum() const
{
    return accountNum;
}

void BankAccount::MakeDeposit(double amt)
{
    balance += amt;
}

double BankAccount::GetTransactionHistory(int i) const
{
    return transactionHistory[i];
}

void BankAccount::RecordTransaction(double amt)
{
    transactionHistory.push_back(amt);
}

QVector <double> BankAccount::GetAllTransactions() const
{
    return transactionHistory;
}
