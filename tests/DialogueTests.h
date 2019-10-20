/**
Author: Mr.Bloom
Date:   10/20/2019
*/

#ifndef DIALOGUE_TESTS_H
#define DIALOGUE_TESTS_H

#include "Testable.h"

class DialogueTest: public Testable {
public:
    DialogueTest(const std::string& n);
    virtual void build();
}

#endif /* DIALOGUE_TESTS_H */
