#include <iostream>
#include "Tests/Company.h"
#include <istream>


using namespace std;



int main() {
    ifstream planes, passengers;
    planes.open("PLANES.txt");
    passengers.open("PASSENGERS.txt");

    if (!planes.is_open() || !passengers.is_open()) {
        cout << "Files not Found\n";
        return 1;
    }

    Company comp(planes, passengers);

    planes.close();
    passengers.close();

    comp.mainMenu();     // start the program

    ofstream planesR ("C:/Users/ruben/AirportManagement_AED_Project/Tests/PLANES.txt");
    ofstream passengersR ("C:/Users/ruben/AirportManagement_AED_Project/Tests/PASSENGERS.txt");

    comp.record(planesR, passengersR);      // load the changes commit in the .txt file

    planesR.close();
    passengersR.close();

    return 0;
}