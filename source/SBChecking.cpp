/*
Written By Kefin Sajan
Date: 10/24/19
*/

#include "SBChecking.h"

SBChecking::SBChecking(const SBAccount& acct) : SBAccount(acct)
{}

SBChecking::SBChecking(const Date& created, double bal) :
    SBAccount(created, bal)
{}

void SBChecking::withdraw(double ToWithdraw)
{
    SBAccount::balance -= ToWithdraw;
}
