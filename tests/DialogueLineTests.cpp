/**
Author: Mr.Sajan
Date:   10/19/2019
*/

#include "DialogueLineTests.h"
#include "TestResult.h"
#include "../source/DialogueLine.h"

DialogueLineTests::DialogueLineTests(const std::string& n): Testable(n) {}

void DialogueLineTests::build()
{
    tests.push([](void) -> TestResult {
        DialogueLine D1("Hello! ", Person());
        std::string expected = "Hello! ";
        std::string result = D1.getLineToSay();
        bool passed = ( expected == result );
        
        return TestResult(expected, result, passed);
    });
    
    tests.push([](void) -> TestResult {
        DialogueLine D1("", Person("11123", "", "", Date::now(), true));
        std::string expected = "11123";
        std::string result = D1.getPerson().getIDNum();
        bool passed = ( expected == result );
        
        return TestResult(expected, result, passed);
    });
}



