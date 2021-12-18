//
// Created by ruben on 15/12/2021.
//

#include "Transports.h"

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
