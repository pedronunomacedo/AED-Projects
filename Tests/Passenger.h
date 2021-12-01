//
// Created by ruben on 24/11/2021.
//

#ifndef AIRPORTMANAGEMENT_AED_PROJECT_PASSENGER_H
#define AIRPORTMANAGEMENT_AED_PROJECT_PASSENGER_H
#include "Ticket.h"
#include "Flight.h"
#include<iostream>
#include<vector>
#include <string>
using namespace std;


class Passenger {
private:
    vector<Ticket> boughtTickets;
    Ticket ticket;
    string passengerName;
    int passengerSSN;
public:
    Passenger(string passengerName, int passengerSSN);
    void setTicket(Ticket ticket);
    bool buyTicket();
    bool ticketExist(int numFlight);
    void checkIn(int flightNumber);
};


#endif //AIRPORTMANAGEMENT_AED_PROJECT_PASSENGER_H
