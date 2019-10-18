
#ifndef DATE_H
#define DATE_H

#include <ctime>

class Date
{
    
private:
    int DAY;
    int MONTH;
    int YEAR;
    
public:
    Date()= default;
    Date(const int& D, const int& M, const int& Y);
    now();
    
    /* Getters*/
    Date getDate() const;
    
    /* Setters*/
    void setDate(const int& DAY, const int& MONTH, const int& YEAR);
    
}
