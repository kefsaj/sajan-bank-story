
/**
Author: Mr.Bloom
Date:   10/18/2019
*/

#include "PersonTests.h"
#include "DialogueLineTests.h"
#include "DialogueTests.h"
#include "../source/DialoguePlayer.h"
#include <vector>

void testDialoguePlayer()
{
    Person kef("1204432", "Kefin", "Sajan", Date::now(), true);
    Person bloom("1204433", "Jonah", "Bloom", Date::now(), true);
    Person msMorfe("1204434", "Gabriela", "Morfe", Date::now(), false);
    Person zofranov("1204435", "Markov", "Zofranov", Date::now(), true);
    Dialogue dialogue({
        DialogueLine("Hello, everyone. Thanks for attending.", kef),
        DialogueLine("You're probably wondering why I called this meeting.", kef),
        DialogueLine("What? We're finally going bankrupt?", bloom),
        DialogueLine("That's one, at three you're out.", kef),
        DialogueLine("Okay, so why are we here?", msMorfe),
        DialogueLine("We've finally caught the man who stole nearly 5 mill from us last year", kef),
        DialogueLine("What?? That's great news! Who did it?", zofranov),
        DialogueLine("Well... that's the bad news. It was someone in this very room...", kef),
        DialogueLine("*chocked*", bloom),
        DialogueLine("Well... and who did it?", msMorfe),
        DialogueLine("I think Mr. Bloom could answer that question, isn't that right, Mr. Bloom?", kef),
    });
    
    DialoguePlayer::sharedInstance().playDialogue(dialogue);
}

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
    
    testDialoguePlayer();
    
    return 0;
}
