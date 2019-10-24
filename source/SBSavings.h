/*
Written By Kefin Sajan
Date: 10/24/19
*/

#ifndef SB_SAVING_TEST_H
#define SB_SAVING_TEST_H

#include "SBAccount.h"
#include "Date.h"

class SBSavings : public SBAccount
{
public:
    SBSavings() = default;
    SBSavings(const SBAccount& acct, const double intRate);
    SBSavings(const Date& created, double bal, double intRate);
    virtual void withdraw(double ToWithdraw);
    
    /* Getters */
    double getInterestRate() const;
private:
    double interestRate;
};

#endif /* SB_SAVING_TEST_H */

