//
// Created by Pedro Macedo on 16/12/2021.
//

#ifndef PLANE_CPP_DATE_H
#define PLANE_CPP_DATE_H
#include <iostream>
#include <ctime>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

class Date {
public:
    Date(string data);
    unsigned int getYear() const;
    unsigned int getMonth() const;
    unsigned int getDay() const;
    string getDate() const; // returns the date in format "yyyy/mm/dd"
    int DaysBetweenDates(string &date2);
private:
    string date2;
    unsigned int year2;
    unsigned int month2;
    unsigned int day2;
    unsigned int hour2;
    unsigned int minute2;
    unsigned int second2;
    char sep = '/';
};
#endif //PLANE_CPP_DATE_H