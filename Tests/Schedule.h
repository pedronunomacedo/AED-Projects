//
// Created by ruben on 15/12/2021.
//

#ifndef PLANE_CPP_SCHEDULE_H
#define PLANE_CPP_SCHEDULE_H

#include <iostream>
using namespace std;

class Schedule {
private:
    int hour, minute, year, month, day;
public:
    Schedule(int hour, int minute, int year, int month, int day);
    int convertDate(int hour, int minute, int year, int month, int day) const;
    bool operator< (const Schedule &sh) const;
};


#endif //PLANE_CPP_SCHEDULE_H
