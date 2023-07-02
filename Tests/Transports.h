//
// Created by ruben on 15/12/2021.
//

#ifndef PLANE_CPP_TRANSPORTS_H
#define PLANE_CPP_TRANSPORTS_H

#include <iostream>

using namespace std;

class Transports {
private:
    string type;
    unsigned int distance;
public:
    Transports(string type, unsigned int distance);
    unsigned int getDistance() const;
    string getType() const;
    bool operator < (const  Transports & w) const {return distance < w.distance ; }
    bool operator == (const  Transports & w) const {return distance == w.distance; }
};


#endif //PLANE_CPP_TRANSPORTS_H
