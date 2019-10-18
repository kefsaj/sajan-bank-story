/**
Author: Mr.Bloom
Date:   10/18/2019
*/

#include "PersonTests.h"
#include "TestResult.h"
#include "../source/Person.h"

PersonTests::PersonTests(const std::string& n): Testable(n) {}

void PersonTests::build()
{
    Person p1("7311233", "Kefin", "Sajan", Date::now(), true);
    
    tests.push([p1](void) -> TestResult {
        std::string expected = "0";
        std::string result = std::to_string(p1.getAGE());
        bool passed = (expected == result);
        
        return TestResult(expected, result, passed);
    });
    
    tests.push([p1](void) -> TestResult {
        std::string expected = "Kefin";
        std::string result = p1.getFNAME();
        bool passed = (expected == result);
        
        return TestResult(expected, result, passed);
    });
    
    tests.push([p1](void) -> TestResult {
        std::string expected = "Sajan";
        std::string result = p1.getLNAME();
        bool passed = (expected == result);
        
        return TestResult(expected, result, passed);
    });
    
    tests.push([&p1](void) -> TestResult {
        p1.setLNAME("Sajan2.0");
        std::string expected = "Sajan2.0";
        std::string result = p1.getLNAME();
        bool passed = (expected == result);
        
        return TestResult(expected, result, passed);
    });
    
    tests.push([&p1](void) -> TestResult {
        std::string expected = "7311233";
        std::string result = p1.getIDNum();
        bool passed = (expected == result);
        
        return TestResult(expected, result, passed);
    });
    
    tests.push([&p1](void) -> TestResult {
        std::string expected = "1";
        std::string result = std::to_string(p1.getSEX());
        bool passed = (expected == result);
        
        return TestResult(expected, result, passed);
    });
}

