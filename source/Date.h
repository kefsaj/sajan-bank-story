
#ifndef DATE_H
#define DATE_H

#include <stdint.h>

class Date
{
private:
    uint8_t DAY;
    uint8_t MONTH;
    uint16_t YEAR;
    
public:
    Date() = default;
    Date(uint8_t D, uint8_t M, uint16_t Y);
    
    /* Getters */
    uint8_t getDAY() const;
    uint8_t getMONTH() const;
    uint8_t getYEAR() const;
    
    /* Setters */
    void setDate(uint8_t D, uint8_t M, uint16_t Y);
    
    /* Operators */
    Date& operator+(const Date& other);
    Date& operator-(const Date& other);
    
    /* Static members */
    static Date now();
    
};

#endif /* DATE_H */
