//
// Created by pedro on 01/12/2021.
//

#ifndef AIRPORTMANAGEMENT_AED_PROJECT_COMPANY_H
#define AIRPORTMANAGEMENT_AED_PROJECT_COMPANY_H
#include <iostream>
#include <vector>
#include "Plane.h"
#include "Flight.h"
#include "Passenger.h"
#include "Airport.h"
#include <fstream>
#include <list>


#if defined(_WIN32)
#define CLEAR_MACRO() system("cls")
#elif defined(unix) || defined(__unix__) || defined(__unix)
#define CLEAR_MACRO() system("clear")
#endif

using namespace std;



class Company {
public:
    Company(ifstream &dataPl, ifstream &dataPs, ifstream &dataAir);
    void mainMenu();
    void record(ofstream &dataPl, ofstream &dataPs, ofstream &dataAir);
private:
    list<Airport> airports;
    list<Plane> planes;
    list<Passenger> passengers;
    vector<Flight> getFlightsToCheckIn()const;
    void update();
    bool checkPassenger(Passenger &p);
    void userMenu();
    void settingsMenu();
    void showAllFlights();
    void showAllPassengers();
    void showAllPlanes();
    void showAllServices();
    void buyTicket(Passenger &p);
    void addPlane();
    void addFlight();
    void addPassenger();
    void addService();
    void removePlane();
    void removeFlight();
    void removePassenger();
    void removeService();
    void checkIn(Passenger &p);

};


#endif //AIRPORTMANAGEMENT_AED_PROJECT_COMPANY_H
