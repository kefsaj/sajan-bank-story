
#include "Date.h"
#include <chrono>

Date::Date(const int& DAY, const int& MONTH, const int& YEAR):
    YEAR(Y),
    MONTH(M),
    DAY(D)
{}
now(){
    auto timenow =
         chrono::system_clock::to_time_t(chrono::system_clock::now());
     
       cout << ctime(&timenow) << endl;
}

/* Getters*/
Date getDate() const {
    
}

/* Setters*/
void setDate(const int& DAY, const int& MONTH, const int& YEAR);
