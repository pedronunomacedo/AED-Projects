//
// Created by ruben on 24/11/2021.
//

#ifndef AIRPORTMANAGEMENT_AED_PROJECT_SERVICE_H
#define AIRPORTMANAGEMENT_AED_PROJECT_SERVICE_H
#include <iostream>
#include "Date.h"

using namespace std;

class Service {
public:
    Service(string &type, Date &serviceDate, string &employeeName);
    string getEmployeeName()const;
    Date getDate()const;
    string getType()const;
private:
    string type;
    Date serviceDate = Date(0, 0, 0);
    string employeeName;
};


#endif //AIRPORTMANAGEMENT_AED_PROJECT_SERVICE_H
