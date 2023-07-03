//
// Created by ruben on 15/12/2021.
//

#include "../include/Airport.h"
#include <iomanip>
#include <cmath>


/**
 * Shows the closest transports to the airport and the distance (in Km) they are from the airport
 */
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

/**
 * Adds the given transport to the BST (Binary Search Tree) of nearest transports to the airport
 * @param typ (type of transport)
 * @param dis (distance between the transport and the airport)
 */
void Airport::addTransport(string typ, unsigned int dis) {
    transports.insert(Transports(typ,dis));
}

/**
 * Remove the transport with the characteristics given from the BST
 * @param typ (type of transport)
 * @param dis (distance between the transport and the airport)
 */
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

/**
 * Reads the information about the nearest transports from the AIRPORT.txt file and saves the
 * information in a BST
 * @param f (file with the information)
 */
void Airport::readFile(ifstream &f) {
    string line, name;
    string sep = ",";
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

/**
 * Calculates the size of the BST
 * @return Number of transports near to the airport
 */
int Airport::getTransportsSize() {
    int s = 0;
    BSTItrIn<Transports> it(transports);
    while (!it.isAtEnd()){
        s++;
        it.advance();
    }
    return s;
}

/**
 *
 * @return Name of the airport
 */
string Airport::getName() {
    return name;
}

/**
 * Saves the information located in the BST into a vector of transports
 * @return Vector with the nearest transports to the airport
 */
vector<Transports> Airport::getTransports() {
    vector<Transports> transportes;
    BSTItrIn<Transports> it(transports);
    while (!it.isAtEnd()){
        transportes.push_back(Transports(it.retrieve().getType(),it.retrieve().getDistance()));
        it.advance();
    }
    return transportes;
}
