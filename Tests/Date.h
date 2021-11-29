//
// Created by ruben on 29/11/2021.
//

#ifndef AIRPORTMANAGEMENT_AED_PROJECT_DATE_H
#define AIRPORTMANAGEMENT_AED_PROJECT_DATE_H


class Date {
public:
    Date(unsigned int year, unsigned int month, unsigned int day) {this->day = day; this->month = month; this->year = year;};
    void setDate(unsigned int year, unsigned int month, unsigned int day) {this->year = year; this->month = month; this->day = day;};
    unsigned int getYear() const {return year;};
    unsigned int getMonth() const {return month;};
    unsigned int getDay() const {return day;};
    string getDate() const {return to_string(year) + '/' + to_string(month) + '/' + to_string(day);}; // returns the date in format "yyyy/mm/dd"
    bool isEqualTo(const Date& date) {return year == date.getYear() && month == date.getMonth() && day == date.getDay();};
private:
    unsigned int year;
    unsigned int month;
    unsigned int day;
};


#endif //AIRPORTMANAGEMENT_AED_PROJECT_DATE_H
