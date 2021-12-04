//
// Created by ruben on 24/11/2021.
//

#ifndef AIRPORTMANAGEMENT_AED_PROJECT_PLANE_H
#define AIRPORTMANAGEMENT_AED_PROJECT_PLANE_H

#include <iostream>
#include "Flight.h"
#include "Service.h"
#include <vector>
#include <queue>
using namespace std;


class Plane {
public:
    Plane(int plat, string typ, unsigned int cap, vector<Flight> &plan, vector<Service> &done, queue<Service> &toDo);
    bool operator==(const Plane &p)const;
    vector<Flight> getFlights()const;
    queue<Service> getToDoServ()const;
    vector<Service> getDoneServ()const;
    unsigned int getCapacity()const;
    string getType()const;          //varios metodos podem ser definidos como const
    int getPlate()const;
    void setPlate(int pl);
    void setType(string typ);
    void setCapacity(unsigned int cap);
    bool checkIfIsAvailable(Date maintenanceDay, Date wantedDay);
private:
    int plate;
    string type;
    unsigned int capacity;
    vector<Service> servicesDone;           //mudar para vetor ou list fica mais pratico
    queue<Service> toDoServices;
    vector<Flight> flightPlan;

};


#endif //AIRPORTMANAGEMENT_AED_PROJECT_PLANE_H
