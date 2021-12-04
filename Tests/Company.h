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
#include <windows.h>
#include <fstream>
#include <list>


using namespace std;



class Company {
public:
    Company(ifstream &dataPl, ifstream &dataPs);
    void mainMenu();
    void record(ofstream &dataPl, ofstream &dataPs);
private:
    list<Plane> planes;
    list<Passenger> passengers;
    bool checkPassenger();
    void userMenu();
    void settingsMenu();
    void showAllFlights();
    void showAllPassengers();
    void addPlane();
    void addFlight();
    void addPassenger();
    void removePlane();
    void removeFlight();
    void removePassenger();

};


#endif //AIRPORTMANAGEMENT_AED_PROJECT_COMPANY_H
