/*
Written By Kefin Sajan
Date: 10/23/19
*/

#ifndef SB_CHECKING_H
#define SB_CHECKING_H

#include "SBAccount.h"

class SBChecking : public SBAccount
{
public:
    SBChecking() = default;
    SBChecking(const SBAccount& acct);
    SBChecking(const Date& created, double bal);
    virtual void withdraw(double ToWithdraw);
};

#endif /* SB_CHECKING_H */

