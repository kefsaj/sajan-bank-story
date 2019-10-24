/*
 Written by Kefin Sajan
 Date: 10/24/19
 */

#ifndef SB_CUSTOMER_H
#define SB_CUSTOMER_H

#include "Person.h"
#include "SBAccount.h"

class SBCustomer : public Person
{
public:
    SBCustomer(const Person& customer, const SBAccount& acc, const Date& dt);
    Date getStartDate();
private:
    Date sinceDt;
};
#endif /* SB_CUSTOMER_H */
