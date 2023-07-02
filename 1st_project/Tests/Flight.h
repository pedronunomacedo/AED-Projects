//
// Created by ruben on 24/11/2021.
//

#ifndef AIRPORTMANAGEMENT_AED_PROJECT_FLIGHT_H
#define AIRPORTMANAGEMENT_AED_PROJECT_FLIGHT_H

#include <iostream>
#include "Date.h"


using namespace std;



class Flight {
public:
    Flight(unsigned int number,unsigned int time,Date date,string ori,string des, unsigned int capacity, int occupiedPlaces);
    bool operator== (const Flight &f) const;
    bool operator< (const Flight &f) const;
    unsigned int getAvailablePlaces();
    void setFlightNumber(unsigned int flightNumber);
    void setDestination(string destination);
    void setOrigin(string origin);
    void setFlightTime(unsigned int flightTime);
    void setDate(Date departuredate);
    void setOccupiedPlaces();
    int getOccupiedPlaces();
    string getOrigin()const;
    string getDestination()const;
    Date getDepartureDate()const;
    int getCapacity()const;
    int getFlightNumber()const;
    int getDuration()const;
    void show();

private:
    int flightNumber, capacity;
    Date departureDate = Date();     //criar classe date, para poder usar como objeto !!
    int flightTime;
    string origin;
    string destination;
    int occupiedPlaces;
};


#endif //AIRPORTMANAGEMENT_AED_PROJECT_FLIGHT_H

