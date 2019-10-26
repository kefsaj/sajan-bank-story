/*
 Date: 10/26/19
 */

#include "SBManager.h"

SBManager::SBManager(const std::vector<SBCustomer>& custms) :
    customer(custms)
{}

std::vector<SBCustomer> getCustomer() const
{
    return customers;
}

void SBManager::addCustomer(const SBCustomer& customer)
{
    customers.push_back(customer);
}

void SBManager::removeCustomer(const SBCustomer& customer)
{
    bool found = false;
    for(size_t i = 0; i < customers.size() && !found; i++)
    {
        if(customer->getCustomers() == customers[i].getCustomer())
        {
            customers.erase(i);
            found = true;
        }
    }
    if(!found)
    {
        throw ("Customer not found!");
    }
}

double SBManager::assests() const
{
    double totalassets = 0;
    for(auto& customers : customers)
    {
        for(auto& account : customer.getAccounts())
        {
            totalassets += account->getBalance();
        }
    }
    return totalassets;
}

double SBManager::liabilities() const
{
    double totalLiab = 0;
    for(auto& customers : customer)
    {
        for(auto& account : customer.getAccounts())
        {
            totalLiab += account->getBalance();
        }
    }
    return totalLiab;
}

double SBManager::getNetWorth() const
{
    return (assests() - liabilities());
}

uint32_t numberOfOpenAccounts() const
{
    uint32_t openAccts = 0;
    for(auto& customers : customer)
    {
        for(auto& account : customer.getAccounts())
        {
            openAccts++;
        }
    }
    return openAccts;
}
