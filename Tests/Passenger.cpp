//
// Created by ruben on 24/11/2021.
//

#include "Passenger.h"


/**
 *
 * @param passengerName
 * @param passengerID
 */
Passenger::Passenger(string &passengerName, int &passengerSSN, vector<Ticket> &t) {
    this->passengerName = passengerName;
    this->passengerSSN = passengerSSN;
    boughtTickets = t;

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

string Passenger::getName() const {
    return passengerName;
}

int Passenger::getSSN() const {
    return passengerSSN;
}







bool Passenger::buyTicket() {
    // Variables


    // Print a todos os voos

    // Perguntar qual é o número do voo que deseja

    // Verificar se o voo não está lotado (flight.getAvaiablePlaces() > 0)

}

bool Passenger::operator==(const Passenger &p) const {
    if (passengerSSN == p.getSSN())
        return true;
    return false;
}

vector<Ticket> Passenger::getTickets()const {
    return boughtTickets;
}



