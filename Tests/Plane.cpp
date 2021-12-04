//
// Created by ruben on 24/11/2021.
//

#include "Plane.h"

Plane::Plane(int plat, string typ, unsigned int cap, vector<Flight> &plan, vector<Service> &done, queue<Service> &toDo)
{
    plate = plat;
    type = typ;
    capacity = cap;
    flightPlan = plan;
    servicesDone = done;
    toDoServices = toDo;
}

bool Plane::operator==(const Plane &p)const{
    if (plate == p.getPlate())
        return true;
    return false;
}

vector<Flight> Plane::getFlights()const{
    return flightPlan;
}

queue<Service> Plane::getToDoServ()const{
    return toDoServices;
}

vector<Service> Plane::getDoneServ()const{
    return servicesDone;
}

int Plane::getPlate()const{
    return plate;
}

string Plane::getType()const{
    return type;
}

unsigned int Plane::getCapacity()const{
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

void Plane::setPlate(int pl)         //passar por referencia sempre q possivel para evitar copias desnecessarias !!
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





