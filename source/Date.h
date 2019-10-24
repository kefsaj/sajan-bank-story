/*
 *  Created on: 10/18/2019
 *      Author: Bryan Morfe
 */

#ifndef DATE_H
#define DATE_H

#include <stdint.h>

class Date
{
private:
    uint8_t DAY;
    uint8_t MONTH;
    uint16_t YEAR;
    static const Date refDATE;
    
public:
    Date() = default;
    Date(uint8_t D, uint8_t M, uint16_t Y);
    Date(uint32_t nDays);
    
    /* Getters */
    uint8_t getDAY() const;
    uint8_t getMONTH() const;
    uint8_t getYEAR() const;
    
    /* Setters */
    void setDate(uint8_t D, uint8_t M, uint16_t Y);
    
    /* Operators */
    Date& operator+(const Date& other);
    Date& operator-(const Date& other);
    bool operator>(const Date& other) const;
    bool operator<(const Date& other) const;
    bool operator==(const Date& other) const;
    
    uint32_t daysSinceRefDate() const;
    
    /* Static members */
    static Date now();
    static Date refDate();
};

#endif /* DATE_H */
