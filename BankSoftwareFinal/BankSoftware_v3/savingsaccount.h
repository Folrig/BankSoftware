#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H
#include "bankaccount.h"

class SavingsAccount : public BankAccount
{
public:
    SavingsAccount();
    void MakeWithdrawl(double);

private:
    double interestRate;

};

#endif // SAVINGSACCOUNT_H
