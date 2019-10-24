/*
 Written By Kefin Sajan
 Date: 10/24/19
 */

#include "SBSavings.h"

SBSavings::SBSavings(const SBAccount& acct, const double intRate) :
SBAccount(acct),
interestRate(intRate)
{}

SBSavings::SBSavings(const Date& created, double bal, double intRate) :
SBAccount(created, bal),
interestRate(intRate)
{}

void SBSavings::withdraw(double ToWithdraw)
{
    SBAccount::balance -= ToWithdraw;
}

double SBSaving::getInterestRate() const
{
    return interestRate;
}
