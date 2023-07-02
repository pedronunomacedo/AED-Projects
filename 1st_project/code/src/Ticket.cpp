//
// Created by pedro on 01/12/2021.
//

#include "../include/Ticket.h"

/**
 * Creates a new ticket
 * @param package (true if the passenger wants to take package, false otherwise)
 * @param flightNumber (assign a flight number to the ticket)
 */
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



