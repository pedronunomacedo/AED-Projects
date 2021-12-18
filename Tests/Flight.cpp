//
// Created by ruben on 24/11/2021.
//

#include "Flight.h"
#include <iomanip>

Flight::Flight(unsigned int number,unsigned int time,Date date,string ori,string des, unsigned int capacity, int occupiedPlaces){
    flightNumber = number;
    flightTime = time;
    departureDate = date;
    origin = ori;
    destination = des;
    this->capacity = capacity;
    this->occupiedPlaces = occupiedPlaces;
}

unsigned int Flight::getAvailablePlaces() {
    return  capacity - occupiedPlaces;
}

int Flight::getFlightNumber() const{
    return flightNumber;
}

int Flight::getDuration() const{
    return flightTime;
}

string Flight::getDestination() const{
    return destination;
}

string Flight::getOrigin() const{
    return origin;
}

Date Flight::getDepartureDate() const{
    return departureDate;
}

void Flight::setFlightNumber( unsigned int flightNumber )           //passar por referencia !!
{
    this->flightNumber = flightNumber;
}

void Flight::setDestination(string destination)
{
    this->destination = destination;
}

void Flight::setOrigin(string origin)
{
    this->origin = origin;
}

void Flight::setFlightTime(unsigned int flightTime)
{
    this->flightTime = flightTime;
}

void Flight::setDate(Date departureDate)
{
    this->departureDate = departureDate;
}


int Flight::getOccupiedPlaces() {
    return occupiedPlaces;
}

bool Flight::operator==(const Flight &f) const {
    if (flightNumber == f.getFlightNumber()) { return true;}
    return false;
}

bool Flight::operator<(const Flight &f) const {
    if (flightNumber < f.getFlightNumber()) { return true;}
    return false;
}

void Flight::show() {
    cout << setw(13) << flightNumber << setw(11) << "|" << setw(15) << departureDate.show() << setw(7) << "|" << setw(12) << flightTime << setw(10) << "|" << setw(5 + origin.size()) << origin << setw(12-origin.size()) << "|" << setw(7 + destination.size()) << destination << setw(15-destination.size()) << "|"  << setw(15) << getAvailablePlaces() << endl;
    cout << "------------------------------------------------------------------------------------------------------------------------------------" << endl;
}

int Flight::getCapacity() const {
    return capacity;
}

void Flight::setOccupiedPlaces() {
    occupiedPlaces++;
}

