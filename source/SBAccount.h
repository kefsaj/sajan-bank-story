/*
 Written By Kefin Sajan
 Date: 10/23/19
 */

#ifndef SBACCOUNT_H
#define SBACCOUNT_H

#include "Date.h"
#include <string.h>

class SBAccount
{
public:
    SBAccount(const std::string& AccNum, const Date& created, double bal);
    virtual ~SBAccount();
    virtual void withdraw(double ToWithdraw) = 0;
    virtual void deposit(double ToDeposit);
    
    /* Getters */
    virtual Date getAccOpenDt() const;
    virtual double getBalance() const;
    virtual std::string getAccNumber() const;
        
protected:
    Date accOpenDt;
    double balance;
    std::string AccNumber;
};

#endif /* SBACCOUNT_H */
