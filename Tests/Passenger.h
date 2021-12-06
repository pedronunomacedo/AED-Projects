//
// Created by ruben on 24/11/2021.
//

#ifndef AIRPORTMANAGEMENT_AED_PROJECT_PASSENGER_H
#define AIRPORTMANAGEMENT_AED_PROJECT_PASSENGER_H
#include "Ticket.h"
#include "Flight.h"
#include "Plane.h"
#include<iostream>
#include<vector>
#include <string>
using namespace std;


class Passenger {
private:
    vector<Ticket> boughtTickets;
    string passengerName;
    int passengerSSN;
public:
    Passenger(string &passengerName, int &passengerSSN);
    bool operator==(const Passenger &p)const;
    void setTicket(Ticket ticket);
    bool buyTicket();
    bool ticketExist(int numFlight);
    void checkIn(int flightNumber);
    string getName()const;
    int getSSN()const;
};


#endif //AIRPORTMANAGEMENT_AED_PROJECT_PASSENGER_H
