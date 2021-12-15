//
// Created by ruben on 15/12/2021.
//

#include "Schedule.h"

Schedule::Schedule(int hour, int minute, int year, int month, int day) {
    this->hour = hour;
    this->minute = minute;
    this->year = year;
    this->month = month;
    this->day = day;
}
bool Schedule::operator<(const Schedule &sh) const {
    return true;
}