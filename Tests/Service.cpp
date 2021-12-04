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

