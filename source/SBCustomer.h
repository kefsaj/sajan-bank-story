/*
 Written by Kefin Sajan
 Date: 10/24/19
 */

#ifndef SB_CUSTOMER_H
#define SB_CUSTOMER_H

#include "Person.h"
#include "SBAccount.h"
#include <vector>

class SBCustomer : public Person
{
public:
    SBCustomer(const Person& c, const Date& dt, const std::vector<SBAccount*>& Acct);
    void openAccount(SBAccount* acct);
    void closeAccount(SBAccount* acct);
    Date getStartDate() const;
    std::vector<SBAccount*> getAccount() const;
    
private:
    Person customer;
    Date sinceDt;
    std::vector<SBAccount*> Accounts;
};
#endif /* SB_CUSTOMER_H */
