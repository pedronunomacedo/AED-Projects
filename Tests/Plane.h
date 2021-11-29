//
// Created by ruben on 24/11/2021.
//

#ifndef AIRPORTMANAGEMENT_AED_PROJECT_PLANE_H
#define AIRPORTMANAGEMENT_AED_PROJECT_PLANE_H

#include <iostream>
#include "Flight.h"
#include "Service.h"
#include <list>
#include <stack>
using namespace std;


class Plane {
private:
    string plate;
    string type;
    int capacity;
    list<Flight> flightPlan;
    list<Service> servicesDone;
    stack<Service> toDoServices;
};


#endif //AIRPORTMANAGEMENT_AED_PROJECT_PLANE_H
