#ifndef CHECKINGACCOUNT_H
#define CHECKINGACCOUNT_H
#include "bankaccount.h"

class CheckingAccount : public BankAccount
{
public:
    CheckingAccount();
    void MakeWithdrawl(double);

private:
    double overdraftFee;

};

#endif // CHECKINGACCOUNT_H
