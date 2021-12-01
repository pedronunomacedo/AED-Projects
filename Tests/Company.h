//
// Created by pedro on 01/12/2021.
//

#ifndef AIRPORTMANAGEMENT_AED_PROJECT_COMPANY_H
#define AIRPORTMANAGEMENT_AED_PROJECT_COMPANY_H
#include <vector>
#include "Plane.h"
#include "Passenger.h"

class Company {
private:
    vector<Passenger> passengers;
public:
    vector<Plane> planes;
    Company();
};


#endif //AIRPORTMANAGEMENT_AED_PROJECT_COMPANY_H
