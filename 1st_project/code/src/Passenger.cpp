//
// Created by ruben on 24/11/2021.
//

#include "../include/Passenger.h"
#include <iomanip>


Passenger::Passenger(string &passengerName, int &passengerSSN, vector<Ticket> &t) {
    this->passengerName = passengerName;
    this->passengerSSN = passengerSSN;
    boughtTickets = t;

}

/**
 * Adds the ticket given to the vector of boughtTickets by the passenger
 * @param ticket (Ticket to add)
 */
void Passenger::setTicket(Ticket &ticket) {
    cout << ticket.getFlightNumber() << endl;
    boughtTickets.push_back(ticket);
}

/**
 * Verifies if the ticket exists in the boughtTicket vector
 * @param numFlight (Number of flight to search in the boughtTickets vector)
 * @return true, if it exists, false otherwise
 */
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

/**
 * Compares to passengers to see if they are the same by checking the SSN
 * @param p (Passenger to compare)
 * @return true if is the same passenger, false otherwise
 */
bool Passenger::operator==(const Passenger &p) const {
    if (passengerSSN == p.getSSN())
        return true;
    return false;
}

vector<Ticket> &Passenger::getTickets() {
    return boughtTickets;
}

/**
 * Shows the passengers and the tickets associated with him
 */
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



