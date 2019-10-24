/*
Written by Kefin Sajan
Date: 10/24/19
*/

#include "SBCustomer.h"

SBCustomer::SBCustomer(const Person& customer, const SBAccount& acct, const Date& dt) :
Person(customer),
SBAccount(acct),
sinceDt(dt)
{}

Date SBCustomer::getStartDate()
{
    return sinceDt;
}
