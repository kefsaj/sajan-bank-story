/**
 * Author: Kefin Sajan
 * Date: 10/22/2019
 */

#ifndef DIALOGUE_PLAYER_H
#define DIALOGUE_PLAYER_H

#include "Dialogue.h"

class DialoguePlayer
{
private:
    static const DialoguePlayer shared;
public:
    static DialoguePlayer sharedInstance();
    void playDialogue(const Dialogue& dialogue) const;
};

#endif /* DIALOGUE_PLAYER_H */
