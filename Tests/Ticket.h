//
// Created by pedro on 01/12/2021.
//

#ifndef AIRPORTMANAGEMENT_AED_PROJECT_TICKET_H
#define AIRPORTMANAGEMENT_AED_PROJECT_TICKET_H


class Ticket {
private:
    bool package;
    int flightNumber;
public:
    Ticket(bool package, int flightNumber);
    int getFlightNumber() const;
    bool getPackage() const;
};


#endif //AIRPORTMANAGEMENT_AED_PROJECT_TICKET_H
