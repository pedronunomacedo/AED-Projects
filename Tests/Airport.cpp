//
// Created by ruben on 15/12/2021.
//

#include "Airport.h"
#include <iomanip>
#include <cmath>



void Airport::showTransports() const {
    unsigned int dis; string typ;
    BSTItrIn<Transports> it(transports);
    cout << "      Type      |      Distance (Km)      " << endl;
    cout << "==========================================" << endl;
    while (!it.isAtEnd()){
        typ = it.retrieve().getType();
        dis = it.retrieve().getDistance();
        cout << setw(floor((16.0-typ.size())/2)+typ.size()) << typ << setw(ceil((16.0-typ.size())/2)+1) << "|" << setw(floor((25-to_string(dis).size())/2)+
        to_string(dis).size()) << dis << endl;
        cout << "------------------------------------------" << endl;
        it.advance();
    }
}

void Airport::addTransport(string typ, unsigned int dis) {
    transports.insert(Transports(typ,dis));
}

void Airport::removeTransport(string typ, unsigned int dis) {
    BSTItrIn<Transports> it(transports);
    while(!it.isAtEnd()){
        if(it.retrieve().getType() == typ && it.retrieve().getDistance() == dis){
            transports.remove(it.retrieve());
            break;
        }
        it.advance();
    }
}


void Airport::readFile(ifstream &f) {
    string line, name;
    string sep = " - ";
    int nT;
    getline(f, line);
    stringstream ss(line);
    ss >> name >> sep >> nT;
    this->name = name;
    for (int i = 0; i < nT; i++){
        string line1, ty;
        int dist;
        getline(f,line1);
        stringstream s(line1);
        s >> ty >> sep >> dist;
        transports.insert(Transports(ty,dist));
    }
}

int Airport::getTransportsSize() {
    int s = 0;
    BSTItrIn<Transports> it(transports);
    while (!it.isAtEnd()){
        s++;
        it.advance();
    }
    return s;
}

string Airport::getName() {
    return name;
}

vector<Transports> Airport::getTransports() {
    vector<Transports> transportes;
    BSTItrIn<Transports> it(transports);
    while (!it.isAtEnd()){
        transportes.push_back(Transports(it.retrieve().getType(),it.retrieve().getDistance()));
        it.advance();
    }
    return transportes;
}
