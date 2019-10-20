/**
Author: Kefin Sajan
Date:   10/20/2019
*/

#include "Dialogue.h"

Dialogue::Dialogue(const std::vector<DialogueLine>& dialogueL): dialogueLines(dialogueL) {}

std::vector<DialogueLine> Dialogue::getDialogueLines() const {
    return dialogueLines;
}

void Dialogue::setDialogueLines(const std::vector<DialogueLine>& DialogueLines) {
    dialogueLines = DialogueLines;
}

void Dialogue::addDialogueLine(const DialogueLine& lineToAdd) {
    dialogueLines.push_back(lineToAdd);
}

