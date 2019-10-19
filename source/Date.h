
#ifndef DATE_H
#define DATE_H

#include <stdint.h>

class Date
{
private:
    uint8_t DAY;
    uint8_t MONTH;
    uint8_t YEAR;
    
public:
    Date() = default;
    Date(uint8_t D, uint8_t M, uint8_t Y);
    
    /* Getters */
    uint8_t getDAY() const;
    uint8_t getMONTH() const;
    uint8_t getYEAR() const;
    
    /* Setters */
    void setDAY(uint8_t D);
    void setMONTH(uint8_t M);
    void setYEAR(uint8_t Y);
    void setDate(uint8_t D, uint8_t M, uint8_t Y);
    
    /* Operators */
    Date& operator+(const Date& other);
    Date& operator-(const Date& other);
    
    /* Static members */
    static Date now();
    
};

#endif /* DATE_H */
