#include "PersonTests.h"

#include <vector>

int main()
{
    std::vector<Testable *> unitTests {
        new PersonTests("PersonTests"),
    };
    
    for(auto& unitTest : unitTests)
    {
        unitTest.build();
        unitTest.run();
        delete unitTest;
    }
    
    return 0;
}
