
#ifndef PERSON_TESTS_H
#define PERSON_TESTS_H

#include "Testable.h"

class PersonTests: public Testable
{
public:
    PersonTests(const std::string& n);
    virtual void build();
};

#endif /* PERSON_TESTS_H */
