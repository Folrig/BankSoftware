#include "savingsaccount.h"

SavingsAccount::SavingsAccount()
{
    balance = 500.00;
    accountNum = 981337;
    interestRate = 0.10;
}

void SavingsAccount::MakeWithdrawl(double amt)
{
    balance -= amt;
}
