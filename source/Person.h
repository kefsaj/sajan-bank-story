/**
 Author: Kefin Sajan
 Date:   10/18/2019
 */

#ifndef PERSON_H
#define PERSON_H

#include <string>
#include "Date.h"

class Person {
private:
    std::string IDNum;
    std::string FNAME;
    std::string LNAME;
    Date DOB;
    bool SEX;
    
public:
    /* Constructors */
    Person() = default;
    Person(const std::string& ID, const std::string& FN, const std::string& LN, const Date& D, const bool S);
    
    /* Getters */
    Date getDOB() const;
    unsigned char getAGE() const;
    std::string getFNAME() const;
    std::string getLNAME() const;
    std::string getIDNum() const;
    bool getSEX() const;
    
    /* Setters */
    void setDOB(Date const &D);
    void setFNAME(std::string const &FN);
    void setLNAME(std::string const &LN);
    void setIDNum(std::string const &ID);
    void setSEX(const bool S);
};

#endif /* PERSON_H */

