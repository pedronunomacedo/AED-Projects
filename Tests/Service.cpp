//
// Created by ruben on 24/11/2021.
//

#include "Service.h"

Service::Service(string &type, Date &serviceDate, string &employeeName){
    this->type = type;
    this->serviceDate = serviceDate;
    this->employeeName = employeeName;
}

string Service::getType()const {
    return type;
}

Date Service::getDate()const {
    return serviceDate;
}

string Service::getEmployeeName()const {
    return employeeName;
}

void Service::show() const {
    cout << setw(floor((14.0-type.size())/2)+type.size()) << type << setw(ceil((14.0-type.size())/2)+1) << "|" << serviceDate.show() << " |" << setw( floor((23-employeeName.size())/2)+employeeName.size()-1 ) << employeeName << endl;
    cout << "-----------------------------------------------------------" << endl;
}

