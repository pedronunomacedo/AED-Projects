//
// Created by ruben on 29/11/2021.
//

#ifndef AIRPORTMANAGEMENT_AED_PROJECT_DATE_H
#define AIRPORTMANAGEMENT_AED_PROJECT_DATE_H
#include <iostream>
#include <ctime>
#include <vector>
#include <iomanip>
using namespace std;

class Date {
public:
    Date();
    Date(string &d);
    void setYear(int y);
    void setMonth(int m);
    void setDay(int d);
    void setHour(int h);
    void setMinute(int min);
    void setSecond(int sec);
    int getYear() const;
    int getMonth() const;
    int getDay() const;
    int getHour() const;
    int getMinute() const;
    int getSecond() const;
    string show() const;        //esta alterado !
    int daysSince2020() const;
    int daysBetweenDates(Date &date2);
private:
    string data;
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
    char sep1 = '/';
    char sep2 = '_';
    char sep3 = ':';
    vector<int> monthsDays = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; // monthsDays is not a leap year
};


#endif //AIRPORTMANAGEMENT_AED_PROJECT_DATE_H
