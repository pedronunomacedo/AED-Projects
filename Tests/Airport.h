//
// Created by ruben on 15/12/2021.
//

#ifndef PLANE_CPP_AIRPORT_H
#define PLANE_CPP_AIRPORT_H

#include <iostream>
#include <sstream>
#include "BST.h"
#include "Transports.h"

using namespace std;

class Airport {
private:
    string name;
    BST<Transports> transports;
public:
    //Airport(string name) : transports(Transports("",0, Schedule()));

};


#endif //PLANE_CPP_AIRPORT_H
