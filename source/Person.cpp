/**
Author: Kefin Sajan
Date:   10/18/2019
*/

#include "Person.h"
 
Person::Person(const std::string& ID, const std::string& FN, const std::string& LN, const Date& D, const bool S):
    IDNum(ID),
    FNAME(FN),
    LNAME(LN),
    DOB(D),
    SEX(S)
{}

 /* Getters */
Date Person::getDOB() const {
    return DOB;
}

unsigned char Person::getAGE() const {
    return (Date::now() - DOB).getYEAR();
}

std::string Person::getFNAME() const {
    return FNAME;
}

std::string Person::getLNAME() const {
    return LNAME;
}

std::string Person::getIDNum() const {
    return IDNum;
}

bool Person::getSEX() const {
    return SEX;
}

/* Setters */
void Person::setDOB(Date const &D) {
    DOB = D;
}

void Person::setFNAME(std::string const &FN) {
    FNAME = FN;
}

void Person::setLNAME(std::string const &LN) {
    LNAME = LN;
}

void Person::setIDNum(std::string const &ID) {
    IDNum = ID;
}

void Person::setSEX(const bool S) {
    SEX = S;
}
