//
// Created by ruben on 15/12/2021.
//

#ifndef PLANE_CPP_AIRPORT_H
#define PLANE_CPP_AIRPORT_H

#include <iostream>
#include <sstream>
#include <fstream>
#include "BST.h"
#include "Transports.h"

using namespace std;

class Airport {
private:
    string name;
    BST<Transports> transports;
public:
    Airport(): name(""), transports(Transports("",0)){};
    vector<Transports> getTransports();
    string getName();
    void readFile (ifstream &f);
    void showTransports() const;
    void addTransport(string typ, unsigned int dis);
    void removeTransport(string typ, unsigned int d);
    int getTransportsSize ();

};


#endif //PLANE_CPP_AIRPORT_H
