//
// Created by ruben on 24/11/2021.
//

#include "Passenger.h"
#include <iomanip>


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



bool Passenger::operator==(const Passenger &p) const {
    if (passengerSSN == p.getSSN())
        return true;
    return false;
}

vector<Ticket> Passenger::getTickets() {
    return boughtTickets;
}

void Passenger::show() const {
    cout << passengerName << setw(15-passengerName.size()) << "|" << setw(9) << passengerSSN;
    if (boughtTickets.size() != 0) {
        for (auto &t: boughtTickets)
            cout << setw(5) << "|" << setw(10) << t.getPackage() << setw(9) << "|" << setw(14) << t.getFlightNumber() << endl;
    }
    else {
        cout << setw(5) << "|" << setw(12) << "none" << setw(7) << "|" << setw(15) << "none" << endl;
    }
}



