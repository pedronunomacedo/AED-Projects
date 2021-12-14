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

void Passenger::setTicket(Ticket &ticket) {
    cout << ticket.getFlightNumber() << endl;
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

vector<Ticket> &Passenger::getTickets() {
    return boughtTickets;
}

void Passenger::show() const {
    unsigned int i = 0;
    cout << setw(3 + passengerName.size()) << passengerName << setw(12-passengerName.size()) << "|" << setw(11) << passengerSSN ;
    if (!boughtTickets.empty())
        for (auto &t: boughtTickets) {
            if (i == 0 ) {
                cout << setw(3) << "|" << setw(10) << t.getPackage() << setw(9) << "|" << setw(14) << t.getFlightNumber() << endl;
            }
            else { cout << setw(29) << "|" << setw(10) << t.getPackage() << setw(9) << "|" << setw(14) << t.getFlightNumber() << endl;}
            i++;
        }
    else { cout << setw(3) << "|" << setw(11) << "none" << setw(8) << "|" << setw(14) << "none" << endl; }
    cout << "----------------------------------------------------------------------" << endl;
}



