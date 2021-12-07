//
// Created by ruben on 29/11/2021.
//

#ifndef AIRPORTMANAGEMENT_AED_PROJECT_DATE_H
#define AIRPORTMANAGEMENT_AED_PROJECT_DATE_H
#include <iostream>
#include <ctime>
using namespace std;

class Date {
public:
    Date(unsigned int day, unsigned int month, unsigned int year) {this->day = day; this->month = month; this->year = year;};
    Date() {time_t ttime = time(0); tm local_time; localtime_s(&local_time, &ttime); year = 1900 + local_time.tm_year; month = 1 + local_time.tm_mon; day = local_time.tm_mday;}
    unsigned int getYear() const {return year;};
    unsigned int getMonth() const {return month;};
    unsigned int getDay() const {return day;};
    string getDate() const {return to_string(day) + '/' + to_string(month) + '/' + to_string(year);}; // returns the date in format "yyyy/mm/dd"
    bool isEqualTo(const Date& date) const{return year == date.getYear() && month == date.getMonth() && day == date.getDay();};
private:
    unsigned int year;
    unsigned int month;
    unsigned int day;
};


#endif //AIRPORTMANAGEMENT_AED_PROJECT_DATE_H
