/*
 Written By Kefin Sajan
 Date: 10/24/19
 */

#ifndef SB_MANAGAER_H
#define SB_MANAGAER_H

#include "SBCustomer.h"
#include <vector>
#include <stdint.h>

class SBManager
{
public:
    SBManager(const std::vector<SBCustomer>& custms);
    
    void addCustomer(const SBCustomer& customer);
    void removeCustomer(const SBCustomer& customer);
    
    uint32_t numberOfOpenAccounts() const;
    double assets() const;
    double liabilities() const;
    double getNetWorth() const;
    std::vector<SBCustomer> getCustomer() const;
    
private:
    std::vector<SBCustomer> customers;
};

#endif /* SB_MANAGAER_H */
