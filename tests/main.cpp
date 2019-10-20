
/**
Author: Mr.Bloom
Date:   10/18/2019
*/

#include "PersonTests.h"
#include "DialogueLineTests.h"
#include "DialogueTests.h"
#include <vector>

int main()
{
    std::vector<Testable *> unitTests {
        new PersonTests("PersonTests"),
        new DialogueLineTests("DialogueLineTests"),
        new DialogueTests("DialogueTests"),
    };
    
    for(auto& unitTest : unitTests)
    {
        unitTest->build();
        unitTest->run();
        delete unitTest;
    }
    
    return 0;
}
