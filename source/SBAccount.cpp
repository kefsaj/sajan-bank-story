/*
Written By Kefin Sajan
Date: 10/23/19
*/

#include "SBAccount.h"
#include <stdexcept>

SBAccount::SBAccount(const std::string& AccNum, const Date& created, double bal) :
    AccNumber(AccNum),
    balance(bal)
{
    if(created > Date::now())
    {
        throw std::logic_error("Account cannot be opened in the future.");
    }
    
    accOpenDt = created;
}

SBAccount::~SBAccount()
{}

Date SBAccount::getAccOpenDt() const
{
    return AccOpenDt;
}

double SBAccount::getBalance() const
{
    return balance;
}

void SBAccount::deposit( double ToDeposit)
{
    if( ToDeposit <= 0 )
        throw std::logic_error("Cannot deposit negative ammount.");
    balance += ToDeposit;
}

std::string SBAccount::getAccNumber() const
{
    return AccNumber;
}
