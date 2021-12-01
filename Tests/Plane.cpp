//
// Created by ruben on 24/11/2021.
//

#include "Plane.h"

Plane::Plane(string plat, string typ,unsigned int cap, list<Flight> plan, stack<Service> done, queue<Service> toDo)
{
    plate = plat;
    type = typ;
    capacity = cap;
    flightPlan = plan;
    servicesDone = done;
    toDoServices = toDo;
}

string Plane::getPlate() const
{
    return plate;
}

string Plane::getType() const
{
    return type;
}

unsigned int Plane::getCapacity() const
{
    return capacity;
}

bool Plane::checkIfIsAvailable( Date maintenanceDay, Date wantedDay )
{
    if( maintenanceDay.getDate() == wantedDay.getDate() )
    {
        cout << "On this day the plane is undergoing maintenance! Try to choose another day! Thank you for your hard work!" << endl;
        return false;
    }
    else
    {
        cout << "Good news, the plane you choose is ready to fly on the day you want! Job done!" << endl;
        return true;
    }
}

void Plane::setPlate(string pl)
{
    plate = pl;
}

void Plane::setCapacity( unsigned int cap )
{
    capacity = cap;
}

void Plane::setType(string typ)
{
    type = typ;
}





