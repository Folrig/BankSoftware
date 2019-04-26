#include "checkingaccount.h"

CheckingAccount::CheckingAccount()
{
    balance = 500.00;
    accountNum = 133798;
    overdraftFee = 20.00;
}

void CheckingAccount::MakeWithdrawl(double amt)
{
    if (balance < amt)
    {
        balance -= (amt + overdraftFee);
    }
    else
    {
        balance -= amt;
    }
}
