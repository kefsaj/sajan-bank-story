
#include "Date.h"

#include <ctime>
#include <stdexcept>

Date::Date(uint8_t D, uint8_t M, uint8_t Y) {
    
    if(Y < 1970 || Y > 2039 || M > 12 || D > 31) {
        throw std::logic_error("Invalid date range");
    }
    
    DAY = D;
    MONTH = M;
    YEAR = Y;
}


/* Getters*/
uint8_t Date::getDAY() const {
    return DAY;
}

uint8_t Date::getMONTH() const {
    return MONTH;
}

uint8_t Date::getYEAR() const {
    return YEAR;
}

/* Setters*/
void Date::setDate(uint8_t D, uint8_t M, uint8_t Y)
{
    if(Y < 1970 || M > 12 || D > 31) {
        throw std::logic_error("Invalid date range");
    }
    
    DAY = D;
    MONTH = M;
    YEAR = Y;
    
}

/* Operators */
Date& Date::operator+(const Date& other) {
    
    if(DAY + other.DAY > 12) {
        MONTH = 1 + (MONTH + 1) % 13;
    }
    
    DAY = 1 + (DAY + other.DAY) % 32;
    
    if(MONTH )
    
    YEAR += other.YEAR;
    
    return *this;
}

Date& Date::operator-(const Date& other) {
    
    return *this;
}

Date Date::now() {
    
    time_t timenow = time(0);
    struct tm* localtm = localtime(&timenow);
    
    return Date(localtm->tm_mday, localtm->tm_mon, localtm->year);
}
