//
// Created by ruben on 24/11/2021.
//

#ifndef AIRPORTMANAGEMENT_AED_PROJECT_FLIGHT_H
#define AIRPORTMANAGEMENT_AED_PROJECT_FLIGHT_H

#include <iostream>
#include "Date.h"
#include "Plane.h"

using namespace std;



class Flight {
public:
    Flight(unsigned int number,unsigned int time,Date date,string ori,string des);
    unsigned int getAvailablePlaces(string &plate) const;
    unsigned int getFlightNumber() const;
    unsigned int getFlightTime() const;
    unsigned int getOccupiedPlaces() const;
    Date getDepartureDate() const;
    void setFlightNumber(unsigned int flightNumber);
    void setDestination(string destination);
    void setOrigin(string origin);
    void setFlightTime(unsigned int flightTime);
    void setDate(Date departuredate);
    void setOccupiedPlaces();
    string getDestination() const;
    string getOrigin() const;

private:
    unsigned int flightNumber;
    Date departureDate = Date(0,0,0);     //criar classe date, para poder usar como objeto !!
    unsigned int flightTime;
    string origin;
    string destination;
    unsigned int occupiedPlaces;
};


#endif //AIRPORTMANAGEMENT_AED_PROJECT_FLIGHT_H

