//
// Created by pedro on 01/12/2021.
//

#include "Ticket.h"

Ticket::Ticket(bool package, int flightNumber) {
    this->package = package;
    this->flightNumber = flightNumber;
}

int Ticket::getFlightNumber() const {
    return flightNumber;
}

bool Ticket::getPackage() const {
    return package;
}


