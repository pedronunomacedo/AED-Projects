#include <iostream>
#include "Tests/Company.h"
#include <istream>
#include "Tests/Date.h"


using namespace std;




int main() {



    ifstream planes, passengers;
    planes.open("PLANES.txt"); // Just need the name of the file to open!
    passengers.open("PASSENGERS.txt");

    if (!planes.is_open() || !passengers.is_open()) {
        cout << "Files not Found\n";
        return 1;
    }

    Company comp(planes, passengers);

    planes.close();
    passengers.close();

    comp.mainMenu();     // start the program

    ofstream planesR ("PLANES.txt");
    ofstream passengersR ("PASSENGERS.txt");

    comp.record(planesR, passengersR);      // load the changes commit in the .txt file

    planesR.close();
    passengersR.close();



    return 0;
}