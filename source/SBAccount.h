/*
 Written By Kefin Sajan
 Date: 10/23/19
 */

#ifndef SBACCOUNT_H
#define SBACCOUNT_H

#include "Date.h"

class SBAccount
{
public:
    SBAccount(const Date& created, double bal);
    virtual ~SBAccount();
    virtual void withdraw(double ToWithdraw) = 0;
    virtual void deposit(double ToDeposit);
    
    /* Getters */
    virtual Date getAccOpenDt() const;
    virtual double getBalance() const;
    double getAccNumber() const;
        
protected:
    Date accOpenDt;
    double balance;
private:
    static double AccNumber = 0;
};

#endif /* SBACCOUNT_H */
