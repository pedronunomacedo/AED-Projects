//
// Created by ruben on 15/12/2021.
//

#include "../include/Transports.h"

/**
 * Creates a new transport near to the airport
* @param type (Type of transport (eg.: taxi, bus, train, and more...))
 * @param distance (Distance of the transport to the airport)
 */
Transports::Transports(string type, unsigned int distance) {
    this->type = type;
    this->distance = distance;
}

unsigned int Transports::getDistance() const {
    return distance;
}

string Transports::getType() const {
    return type;
}
