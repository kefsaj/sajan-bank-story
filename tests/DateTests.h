/*
*  Created on: 10/24/2019
*      Author: Bryan Morfe
*/

#ifndef DATE_TESTS_H
#define DATE_TESTS_H

#include "Testable.h"

using namespace std;

class DateTests : public Testable
{
public:
    DateTests(const string& n);
    virtual void build();
};

#endif /* DATE_TESTS_H */
