/**
Author: Mr.Bloom
Date:   10/18/2019
*/
#include "Testable.h"
#include <iostream>

Testable::Testable(const std::string& n): name(n) {}

void Testable::run()
{
    std::cout << "Running " << name << " tests" << std::endl;
    
    std::cout << std::endl;
    
    std::cout << "Test Status" << std::endl;
    
    while(tests.size() > 0)
    {
        auto test = tests.front();
        TestResult testResult = test();
        tests.pop();
        
        if(testResult.passed)
        {
            std::cout << "Passed" << std::endl;
        }
        else
        {
            std::cout << "Failed: Expected " << testResult.expected << " but obtained " << testResult.result << std::endl;
        }
    }
}
