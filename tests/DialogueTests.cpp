/**
Author: Mr.Sajan
Date:   10/20/2019
*/

#include "DialogueTests.h"
#include "Testable.h"
#include "../source/Dialogue.h"

DialogueTests::DialogueTests(const std::string& n): Testable(n) {}

void DialogueTests::build()
{
    Person peter("12234", "Peter", "Lolac", Date::now(), true);
    Person lola("12235", "Lola", "Peterc", Date::now(), false);
    
    Dialogue dg({
        DialogueLine("Hi", peter),
        DialogueLine("Hello, there!", lola),
        DialogueLine("Who are you?", peter),
        DialogueLine("I'm Lola, you?", lola),
        DialogueLine("Peter... Parker... nah jkn!", peter),
    });
    
    dg.addDialogueLine(DialogueLine("Yeah... I figured", lola));
    
    tests.push([dg](void) -> TestResult {
        std::string expected = "6";
        std::string result = std::to_string(dg.getDialogueLines().size());
        bool passed = (expected == result);
        
        return TestResult(expected, result, passed);
    });
    
    tests.push([dg](void) -> TestResult {
        std::string expected = "Yeah... I figured";
        std::string result = dg.getDialogueLines().back().getLineToSay();
        bool passed = (expected == result);
        
        return TestResult(expected, result, passed);
    });
    
    tests.push([dg](void) -> TestResult {
        Dialogue dg2(dg);
        dg2.setDialogueLines({});
        std::string expected = "0";
        std::string result = std::to_string(dg2.getDialogueLines().size());
        bool passed = (expected == result);
        
        return TestResult(expected, result, passed);
    });
}
