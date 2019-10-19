/**
Author: Kefin Sajan
Date:   10/19/2019
*/

#ifndef DIALOGUE_LINE_H
#define DIALOGUE_LINE_H

#include <string>
#include "Person.h"

class DialogueLine {
public:
    DialogueLine(const std::string& line, const Person& currPerson);

    /*Getters*/
    std::string getLineToSay() const;
    Person getPerson() const;
    
private:
    std::string LineToSay;
    Person P1;
};

#endif /* DIALOGUE_LINE_H */
