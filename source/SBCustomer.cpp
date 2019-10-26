/*
Written by Kefin Sajan
Date: 10/24/19
*/

#include "SBCustomer.h"

SBCustomer::SBCustomer(const Person& c, const Date& dt, const std::vector<SBAccount*>& Acct) :
    Person(c),
    sinceDt(dt),
    Accounts(Acct)
{}

void SBCustomer::openAccount(SBAccount* acct)
{
    Accounts.push_back(acct);
}

void SBCustomer::closeAccount(SBAccount* acct)
{
    bool found = false;
    for(size_t i = 0; i < Accounts.size() && !found; ++i)
    {
        if(acct->getAccNumber() == Accounts[i].getAccNumber())
        {
            Accounts.erase(i);
            found = true;
        }
    }
    
    if(!found)
    {
        throw ("Account not found!");
    }
}

Date SBCustomer::getStartDate() const
{
    return sinceDt;
}

std::vector<SBAccount*> getAccount() const
{
    return Accounts;
}
