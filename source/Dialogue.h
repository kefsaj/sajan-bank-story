/**
Author: Kefin Sajan
Date:   10/20/2019
*/

#ifndef DIALOGUE_H
#define DIALOGUE_H

#include <vector>
#include "DialogueLine.h"

class Dialogue {
public:
    Dialogue() = default;
    Dialogue(const std::vector<DialogueLine>& dialogueL);
    
    /* Getter */
    std::vector<DialogueLine> getDialogueLines() const;
    
    void setDialogueLines(const std::vector<DialogueLine>& DialogueLines);
    void addDialogueLine(const DialogueLine& lineToAdd);
private:
    std::vector<DialogueLine> dialogueLines;
};

#endif /* DIALOGUE_H */

