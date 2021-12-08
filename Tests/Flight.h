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
    Flight(unsigned int number,unsigned int time,Date date,string ori,string des);
    unsigned int getAvailablePlaces(int &plate);
    unsigned int getOccupiedPlaces() const;
    void setFlightNumber(unsigned int flightNumber);
    void setDestination(string destination);
    void setOrigin(string origin);
    void setFlightTime(unsigned int flightTime);
    void setDate(Date departuredate);
    void setOccupiedPlaces();
    string getOrigin()const;
    string getDestination()const;
    Date getDepartureDate()const;
    unsigned int getFlightNumber()const;
    unsigned int getDuration()const;
    void show(){cout << flightNumber << " " << departureDate.getDate() << " " << flightTime << " " << origin << " " << destination << endl;};

private:
    unsigned int flightNumber;
    Date departureDate = Date(0,0,0);     //criar classe date, para poder usar como objeto !!
    unsigned int flightTime;
    string origin;
    string destination;
    unsigned int occupiedPlaces;
};


#endif //AIRPORTMANAGEMENT_AED_PROJECT_FLIGHT_H

