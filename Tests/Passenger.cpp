//
// Created by ruben on 24/11/2021.
//

#include "Passenger.h"
#include "Plane.h"

/**
 *
 * @param passengerName
 * @param passengerID
 */
Passenger::Passenger(string passengerName, int passengerSSN) {
    this->passengerName = passengerName;
    this->passengerSSN = passengerSSN;
}

void Passenger::setTicket(Ticket ticket) {
    boughtTickets.push_back(ticket);

}

bool Passenger::ticketExist(int numFlight) {
    for (Ticket ticket : boughtTickets) {
        if (ticket.getFlightNumber() == numFlight) { return true; }
    }

    return false;
}

void Passenger::checkIn(int flightNumber) {

}

bool Passenger::buyTicket() {
    // Print a todos os voos


    // Perguntar qual é o número do voo que deseja
    // Verificar se o voo não está lotado (flight.getAvaiablePlaces() > 0)
    // Chamar a função setTicket da classe Passenger, casso a parte de cima seja verdadeira
    // Incrementar occupiedPlaces
    return false;
}
