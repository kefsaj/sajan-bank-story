/*
 *  Created on: 10/18/2019
 *      Author: Bryan Morfe
 */

#include "Date.h"

#include <ctime>
#include <stdexcept>
#include <array>

static inline bool isLeapYear(uint16_t year)
{
    return year % 4 == 0;
}

static uint8_t numDaysInMonth(uint8_t month, uint16_t year)
{
    static const std::array<uint8_t, 12> daysInMonth {
        31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
    };
    
    return (isLeapYear(year) && month == 2) ? daysInMonth[month - 1] + 1 : daysInMonth[month - 1];
}

const Date Date::refDATE(1, 1, 1970);

Date::Date(uint8_t D, uint8_t M, uint16_t Y)
{
    if(Y < Date::refDATE.YEAR || M > 12 || M == 0 || D > numDaysInMonth(M, Y) || D == 0) {
        throw std::logic_error("Invalid date range");
    }
    
    DAY = D;
    MONTH = M;
    YEAR = Y;
}

Date::Date(uint32_t nDays)
{
    uint16_t yearsSinceRefDate;
    uint8_t monthsSinceRefDate;
    
    yearsSinceRefDate = nDays / 365;
    nDays -= yearsSinceRefDate * 365;
    uint16_t numDaysInLeapYears = 1 + yearsSinceRefDate / 4;
    
    if(nDays < numDaysInLeapYears)
    {
        yearsSinceRefDate--;
        nDays += 365;
    }
    
    YEAR = refDATE.YEAR + yearsSinceRefDate;
    
    nDays -= numDaysInLeapYears;
    monthsSinceRefDate = 1;
    uint8_t daysInMonth = numDaysInMonth(monthsSinceRefDate, YEAR);
    
    while(nDays >= daysInMonth)
    {
        nDays -= daysInMonth;
        monthsSinceRefDate++;
        daysInMonth = numDaysInMonth(monthsSinceRefDate, YEAR);
    }
        
    MONTH = refDATE.MONTH + monthsSinceRefDate - 1;
    DAY = refDATE.DAY + nDays;
}

/* Getters*/
uint8_t Date::getDAY() const
{
    return DAY;
}

uint8_t Date::getMONTH() const
{
    return MONTH;
}

uint8_t Date::getYEAR() const
{
    return YEAR;
}

std::string Date::formattedString() const
{
    std::string dateString;
    
    dateString = ( MONTH < 10 ? "0" + std::to_string(MONTH) : std::to_string(MONTH) );
    dateString += "/";
    dateString += ( DAY < 10 ? "0" + std::to_string(DAY) : std::to_string(DAY) );
    dateString += "/";
    dateString += std::to_string(YEAR);
    
    return dateString;
}

/* Setters*/
void Date::setDate(uint8_t D, uint8_t M, uint16_t Y)
{
    if(Y < 1970 || M > 12 || D > 31)
    {
        throw std::logic_error("Invalid date range");
    }
    
    DAY = D;
    MONTH = M;
    YEAR = Y;
}

/* Operators */
Date& Date::operator+(const Date& other)
{
    uint32_t nDays = daysSinceRefDate();
    nDays += other.daysSinceRefDate();
    
    Date newDate(nDays);
    
    this->DAY = newDate.DAY;
    this->MONTH = newDate.MONTH;
    this->YEAR = newDate.YEAR;
    
    return *this;
}

Date& Date::operator-(const Date& other)
{
    uint32_t nDays = daysSinceRefDate();
    uint32_t otherNDays = other.daysSinceRefDate();
    
    nDays = nDays > otherNDays ? nDays - otherNDays : otherNDays - nDays;
    
    Date newDate(nDays);
    
    this->DAY = newDate.DAY;
    this->MONTH = newDate.MONTH;
    this->YEAR = newDate.YEAR;
    
    return *this;
}

bool Date::operator>(const Date& other) const
{
    return daysSinceRefDate() > other.daysSinceRefDate();
}

bool Date::operator<(const Date& other) const
{
    return daysSinceRefDate() < other.daysSinceRefDate();
}

bool Date::operator==(const Date& other) const
{
    return daysSinceRefDate() == other.daysSinceRefDate();
}

Date Date::now()
{
    time_t timenow = time(0);
    struct tm* gmtm = gmtime(&timenow);
    
    return Date(gmtm->tm_mday, gmtm->tm_mon, gmtm->tm_year + 1900);
}

Date Date::refDate()
{
    return Date::refDATE;
}

/* Private */
uint32_t Date::daysSinceRefDate() const
{
    uint32_t numDays = YEAR * 365;
    numDays += 1 + (YEAR - Date::refDATE.YEAR) / 4; // number of leap years
    
    for(uint8_t i = 1; i < MONTH; ++i)
    {
        numDays += numDaysInMonth(i, YEAR);
    }
        
    return numDays + DAY;
}
