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
#include <queue>
using namespace std;


class Plane {
    Plane(string plat, string typ, unsigned int cap, list<Flight> plan, stack<Service> done, queue<Service> toDo);
    string getPlate() const;
    string getType() const;
    unsigned int getCapacity() const;
    void setPlate(string pl);
    void setType(string typ);
    void setCapacity(unsigned int cap);
    bool checkIfIsAvailable(Date maintenanceDay, Date wantedDay);

public:
    list<Flight> flightPlan;
private:

    string plate;
    string type;
    unsigned int capacity;
    stack<Service> servicesDone;
    queue<Service> toDoServices;

};


#endif //AIRPORTMANAGEMENT_AED_PROJECT_PLANE_H
