#include <iostream>
#include <istream>
#include <string>
#include <ctime>
#include <filesystem>

#include "../include/Company.h"
#include "../include/Date.h"

using namespace std;


int main() {
    ifstream planes, passengers, airports;

    std::__fs::filesystem::path currentPath = std::__fs::filesystem::current_path();
    cout << "Current folder path: " << currentPath << endl;

    planes.open("data/planes.csv");
    passengers.open("data/passengers.csv");
    airports.open("data/airports.csv");

    if (!planes.is_open() || !passengers.is_open() || !airports.is_open()) {
        cout << "Files not Found\n";
        return 1;
    }

    Company comp(planes, passengers, airports);

    planes.close();
    passengers.close();
    airports.close();

    comp.mainMenu();     // start the program

    ofstream planesR ("planes.csv");
    ofstream passengersR ("passengers.csv");
    ofstream airportsR ("airports.csv");

    comp.record(planesR, passengersR, airportsR);      // load the changes commit in the .txt file

    planesR.close();
    passengersR.close();
    airportsR.close();



    return 0;
}