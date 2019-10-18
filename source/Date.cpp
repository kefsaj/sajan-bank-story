
#include "Date.h"

Date::Date(const int& DAY, const int& MONTH, const int& YEAR):
    YEAR(Y),
    MONTH(M),
    DAY(D)
{}
now(){
    
}

/* Getters*/
Date getDate() const;

/* Setters*/
void setDate(const int& DAY, const int& MONTH, const int& YEAR);
