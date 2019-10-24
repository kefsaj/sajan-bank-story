/*
Written By Kefin Sajan
Date: 10/23/19
*/

#include "SBAccount.h"

#include <stdexcept>

SBAccount::SBAccount(const Date& created, double bal) :
    balance(bal)
{
    if(created > Date::now())
    {
        throw logic_error("Account cannot be opened in the future.");
    }
    
    accOpenDt = created;
}

virtual SBAccount::~SBAccount()
{}

virtual Date SBAccount::getAccOpenDt() const
{
    return AccOpenDt;
}

virtual double SBAccount::getBalance() const
{
    return balance;
}

void SBAccount::deposit( double ToDeposit)
{
    if( ToDeposit <= 0 )
        throw logic_error("Cannot deposit negative ammount.");
    balance += ToDeposit;
}

double SBAccount::getAccNumber() const
{
    return AccNumber;
}
