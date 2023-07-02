//
// Created by ruben on 24/11/2021.
//

#include "../include/Plane.h"
#include <iomanip>

Plane::Plane(int plat, string typ, unsigned int cap, list<Flight> &plan, vector<Service> &done, queue<Service> &toDo)
{
    plate = plat;
    type = typ;
    capacity = cap;
    flightPlan = plan;
    servicesDone = done;
    toDoServices = toDo;
}

/**
 * Compares two planes and checks if they are the same by checking the plates on both planes
 * @param p (Second plane to compare)
 * @return true if the planes are the same, false otherwise
 */
bool Plane::operator==(const Plane &p)const{
    if (plate == p.getPlate())
        return true;
    return false;
}

list<Flight>& Plane::getFlights(){
    return flightPlan;
}

queue<Service> &Plane::getToDoServ(){
    return toDoServices;
}

/**
 * Adds a service to the queue of toDoServices
 * @param p (service to add)
 */
void Plane::setToDoServ(Service &p) {
    toDoServices.push(p);
}

vector<Service> &Plane::getDoneServ(){
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

/**
 * Checks if the wanted given date match to the service given date.
 * @param maintenanceDay (first date to compare)
 * @param wantedDay (second date to compare)
 * @return true if the dates don't match, false otherwise
 */
bool Plane::checkIfIsAvailable( Date maintenanceDay, Date wantedDay )
{
    if(maintenanceDay.show() == wantedDay.show())
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

/**
 * Show the plane in the following format " Plane plate | Plane type | Plane capacity "
 */
void Plane::show() const {
    cout << setw(9) << plate << setw(7) << "|" << setw(9) << type << setw(6) << "|" << setw(10) << capacity << endl;
    cout << "------------------------------------------------" << endl;
}





