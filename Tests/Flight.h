//
// Created by ruben on 24/11/2021.
//

#ifndef AIRPORTMANAGEMENT_AED_PROJECT_FLIGHT_H
#define AIRPORTMANAGEMENT_AED_PROJECT_FLIGHT_H

#include <iostream>
#include "Date.h"

using namespace std;



class Flight {
private:
    int flightNumber;
    Date departureDate;     //criar classe date, para poder usar como objeto !!
    int flightTime;
    string origin;
    string destination;
};


#endif //AIRPORTMANAGEMENT_AED_PROJECT_FLIGHT_H
