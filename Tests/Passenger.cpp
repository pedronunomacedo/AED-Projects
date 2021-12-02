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
    // Variables
    int flightNumber;
    bool package, flightExists = false;
    Company company;

    // Print a todos os voos

    // Perguntar qual é o número do voo que deseja
    cout << "What's the flight number you want to buy? ";
    cin >> flightNumber;

    // Verificar se o voo não está lotado (flight.getAvaiablePlaces() > 0)
    for (Plane plane : company.planes) {
        for (Flight flight : plane.flightPlan) {
            if (flightNumber == flight.getFlightNumber()) {
                Flight myFlight(flightNumber, flight.getFlightTime(), flight.get);
                flightExists = true;
                if (flight.getAvailablePlaces() <= 0) {
                    cout << "SOLD OUT!";
                    return false;
                }

                // Chamar a função setTicket() da classe Passenger, caso exista voo com lugares disponíveis
                cout << "The flight is available! Do you want to take package [true or false] ? ";
                cin >> package;
                Ticket ticket1(package, flightNumber);
                setTicket(ticket1);
                // Incrementar occupiedPlaces
                flight.setOccupiedPlaces();
                return true;
            }
        }
    }

    if (!flightExists) { return false; }

}

string Passenger::getName() {
    return passengerName;
}

int Passenger::getSSN() {
    return passengerSSN;
}
