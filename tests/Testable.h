
#ifndef TESTABLE_H
#define TESTABLE_H

#include "TestResult.h"

#include <string>
#include <queue>
#include <functional>

class Testable
{
public:
    Testable(const std::string& n);
    virtual ~Testable() = default;
    
    virtual void build() = 0;
    virtual void run();
    
private:
    std::string name;
protected:
    std::queue<std::function<TestResult(void)>> tests;
};

#endif /* TESTABLE_H */
