/**
Author: Kefin Sajan
Date:   10/19/2019
*/

#include "DialogueLine.h"

DialogueLine::DialogueLine(const std::string& line, const Person& currPerson):
    LineToSay(line),
    P1(currPerson)
{}

/*Getters*/
std::string DialogueLine::getLineToSay() const {
    return LineToSay;
}

Person DialogueLine::getPerson() const {
    return P1;
}
