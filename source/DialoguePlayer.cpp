/**
* Author: Kefin Sajan
* Date: 10/22/2019
*/

#include "DialoguePlayer.h"
#include <iostream>
#include <string>
#include <unistd.h>

DialoguePlayer DialoguePlayer::sharedInstance()
{
    return DialoguePlayer::shared;
}

void DialoguePlayer::playDialogue(const Dialogue& dialogue) const
{
    static const uint32_t charDelay = 50 * 1000;

    for(auto& dialogueLine : dialogue.getDialogueLines())
    {
        static const uint32_t lineDelay = dialogueLine.getLineToSay().size() * 70000;

        Person p = dialogueLine.getPerson();
        
        if(p.getSEX())
        {
            std::cout << "Mr. " << p.getLNAME() << ": " << std::flush;
        }
        else
        {
            std::cout << "Ms. " << p.getLNAME() << ": " << std::flush;
        }
        
        for(auto& ch : dialogueLine.getLineToSay())
        {
            usleep(charDelay);
            std::cout << ch << std::flush;
        }
        
        usleep(lineDelay);
        
        std::cout << std::endl;
    }
}
