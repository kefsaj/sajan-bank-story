/*
Written By Kefin Sajan
Date: 10/24/19
*/

#include "SBChecking.h"

SBChecking::SBChecking(const SBAccount& acct) : SBAccount(acct)
{}

SBChecking::SBChecking(const std::string& AccNum, const Date& created, double bal) :
    SBAccount(AccNum, created, bal)
{}

void SBChecking::withdraw(double ToWithdraw)
{
    if(balance >= ToWithdraw)
    {
        balance -= ToWithdraw;
    }
    else
    {
        throw ("Balance insufficient!");
    }
}
