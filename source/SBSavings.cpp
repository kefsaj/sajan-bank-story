/*
 Written By Kefin Sajan
 Date: 10/24/19
 */

#include "SBSavings.h"

SBSavings::SBSavings(const SBAccount& acct, double intRate) :
    SBAccount(acct),
    interestRate(intRate)
{}

SBSavings::SBSavings(const std::string& AccNum, const Date& created, double bal, double intRate) :
    SBAccount(AccNum, created, bal),
    interestRate(intRate)
{}

void SBSavings::withdraw(double ToWithdraw)
{
    if(balance >= ToWithdraw)
    {
        balance -= ToWithdraw;
    }
    else
    {
        throw ("Insufficient balance.");
    }
    
}

double SBSaving::getInterestRate() const
{
    return interestRate;
}
