//
// Created by pedro on 01/12/2021.
//

#include "Company.h"
#include <string>
#include <iostream>
#include <sstream>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

Company::Company(ifstream &dataPl, ifstream &dataPs) {
    // read planes !
    int nPlanes;
    string nPl;
    getline(dataPl,nPl);
    nPlanes = stoi(nPl);
    for (int i = 0; i < nPlanes; i++){
        vector<Flight> fls;
        vector<Service> doneServ;
        queue<Service> toDoServ;
        string line, typeP, nFl, nDS, nTDS;
        int numberP, capP;
        string sep = " - ";
        getline(dataPl,line);
        stringstream ss(line);
        ss >> numberP >> sep >> typeP >> sep >> capP;
        getline(dataPl,nFl);
        int nFlights = stoi(nFl);
        for (int j = 0; j < nFlights; j++){
            string l, origin, dest;
            char sep1 = '/';
            int numberF, durationF;
            int d,m,y;
            getline(dataPl,l);
            stringstream ss1(l);
            ss1 >> numberF >> sep >> d >> sep1 >> m >> sep1 >> y >> sep >> durationF >> sep >> origin >> sep >> dest;
            Date dateF(d,m,y);
            Flight f (numberF,durationF,dateF,origin,dest);
            fls.push_back(f);
        }

        getline(dataPl,nDS);
        int nDoneServ = stoi(nDS);
        for (int j = 0; j < nDoneServ; j++){
            char sep1 = '/';
            string l, typeS, nameS;
            int d,m,y;
            getline(dataPl,l);
            stringstream ss1(l);
            ss1 >> typeS >> sep >> d >> sep1 >> m >> sep1 >> y >> sep >> nameS;
            Date dateS(d,m,y);
            Service sv(typeS, dateS, nameS);        //contrutor tem de estar public !
            doneServ.push_back(sv);
        }

        getline(dataPl,nTDS);
        int nToDoServ = stoi(nTDS);
        for (int j = 0; j < nToDoServ; j++){
            char sep1 = '/';
            string l, typeS, nameS;
            int d,m,y;
            getline(dataPl,l);
            stringstream ss1(l);
            ss1 >> typeS >> sep >> d >> sep1 >> m >> sep1 >> y >> sep >> nameS;
            Date dateS(d,m,y);
            Service sv(typeS, dateS, nameS);
            toDoServ.push(sv);
        }
        Plane p(numberP, typeP, capP , fls, doneServ, toDoServ);
        planes.push_back(p);
    }


    // read passengers !
    string line;
    string sep = " - ";
    while (getline(dataPs, line)){
        stringstream ss(line);
        int ssn;
        string name;
        ss >> name >> sep >> ssn;
        Passenger p(name, ssn);
        passengers.push_back(p);
    }
}

bool Company::checkPassenger(){
    int ssn;
    cout << "Enter your SSN : "; cin >> ssn;
    for (auto &k : passengers)
        if (k.getSSN() == ssn)
            return true;
    cout << "You are not registered !\nRegister first\n";
    return false;
}
void Company::userMenu() {
    int userChoice;
    do{
        system("cls");
        cout << "User Menu\n\n";
        cout << "1 - Register\n";
        cout << "2 - Check-in\n";
        cout << "3 - Buy Ticket\n";
        cout << "0 - Return to Menu\n";
        cout << endl << "Option : ";
        cin >> userChoice;
        cout << endl;
        if (cin.fail()) {
            cout << "Invalid Input !" << endl;
            Sleep(400);
            cin.clear();
            cin.ignore(9999, '\n');
            userChoice = -1;
        }
        else {
            switch (userChoice) {
                case 1 :
                    cout << "Register Passenger\n\n";
                    addPassenger();
                    Sleep(500);
                    break;
                case 2 :
                    if (checkPassenger())
                        cout << "Welcome to Check-in\n";
                    Sleep(500);
                    break;
                case 3 :
                    if (checkPassenger())
                        cout << "For what country\n";
                    Sleep(500);
                    break;
                case 0 :
                    break;
                default:
                    cout << "Invalid Option! Try Again\n";
                    Sleep(400);
                    break;
            }
        }
    }while (userChoice != 0);
}

void Company::settingsMenu(){
    int setChoice;
    do{
        system("cls");
        cout << "Settings\n\n";
        cout << "1 - Show All Flights\n";
        cout << "2 - Add Flight\n";
        cout << "3 - Remove Flight\n";
        cout << "4 - Show All Passengers\n";
        cout << "5 - Add Passenger\n";
        cout << "6 - Remove Passenger\n";
        cout << "0 - Return to Menu\n";
        cout << endl << "Option : ";
        cin >> setChoice;
        cout << endl;
        if (cin.fail()) {
            cout << "Invalid Input !" << endl;
            Sleep(400);
            cin.clear();
            cin.ignore(9999, '\n');
            setChoice = -1;
        }
        else {
            string name; int ssn;
            switch (setChoice) {        // falta addFlight, removeFlight, showAllPlanes, ...('shows')
                case 1 :
                    cout << "Flights : \n\n";
                    showAllFlights();
                    Sleep(999);
                    break;
                case 2 :
                    cout << "Adding Plane ...\n\n";
                    addPlane();
                    Sleep(500);
                    break;
                case 3 :
                    cout << "Removing Plane ...\n\n";
                    removePlane();
                    Sleep(500);
                    break;
                case 4 :
                    cout << "Passengers : \n\n";
                    showAllPassengers();
                    Sleep(999);
                    break;
                case 5 :
                    cout << "Adding Passenger ...\n\n";
                    addPassenger();
                    Sleep(500);
                    break;
                case 6 :
                    cout << "Removing Passenger ...\n\n";
                    removePassenger();
                    Sleep(500);
                    break;
                case 0 :
                    break;
                default:
                    cout << "Invalid Option! Try Again\n";
                    Sleep(400);
                    break;
            }
        }
    } while (setChoice != 0);
}


void Company::mainMenu(){
    int choice;
    do{
        system("cls");
        cout << "Main Menu\n\n";
        cout << "1 - User HelpDesk\n";
        cout << "2 - App Settings\n";
        cout << "0 - Exit App\n";
        cout << endl << "Option : ";
        cin >> choice;
        cout << endl;
        if (cin.fail()) {
            cout << "Invalid Input !" << endl; Sleep(400);
            cin.clear();
            cin.ignore(9999, '\n');
            choice = -1;
        }else {
            switch (choice) {
                case 1 :
                    userMenu();
                    break;
                case 2 :
                    settingsMenu();
                    break;
                case 0 :
                    break;
                default :
                    cout << "Invalid Option! Try Again\n";
                    Sleep(400);
                    break;
            }
        }
    }while (choice != 0);
}


void Company::showAllFlights() {
    for (auto &k : planes)
        for (auto &i : k.getFlights())
            i.show();
}

void Company::showAllPassengers() {
    for (auto &k : passengers)
        cout << k.getName() << " " << k.getSSN() << endl;
}

void Company::addPassenger() {      //falta ver se a repetidos !!
    int ssn; string name;
    cout << "Passenger SSN to add : "; cin >> ssn;
    cout << "Passenger Name to add : "; cin >> name;
    passengers.push_back(Passenger(name,ssn));
}

void Company::removePassenger() {
    int ssn;
    string name;
    cout << "Passenger SSN to remove : ";
    cin >> ssn;
    cout << "Passenger Name to remove : ";
    cin >> name;
    passengers.remove(Passenger(name,ssn));
}


void Company::record(ofstream &dataPl, ofstream &dataPs) {
    string sep = " - ";

    //recording passengers
    for (auto &p : passengers)
        dataPs << p.getName() << sep << p.getSSN() << endl;

    //recording planes
    dataPl << planes.size() << endl;
    for (auto &p : planes){
        dataPl << p.getPlate() << sep << p.getType() << sep << p.getCapacity() << endl;
        dataPl << p.getFlights().size() << endl;
        for (auto &f : p.getFlights())
            dataPl << f.getFlightNumber() << sep << f.getDepartureDate().getDate() << sep << f.getDuration() << sep << f.getOrigin() << sep << f.getDestination() << endl;
        dataPl << p.getDoneServ().size() << endl;
        for (auto &ds : p.getDoneServ())
            dataPl << ds.getType() << sep << ds.getDate().getDate() << sep << ds.getEmployeeName() << endl;
        dataPl << p.getToDoServ().size() << endl;
        for (int i = 0; i < p.getToDoServ().size(); i++){
            dataPl << p.getToDoServ().front().getType() << sep << p.getToDoServ().front().getDate().getDate() << sep << p.getToDoServ().front().getEmployeeName() << endl;
            p.getToDoServ().pop();
        }
    }
}

void Company::addPlane() {

    //...


}

void Company::removePlane() {
    int plate;
    vector<Flight> f; vector<Service> ds; queue<Service> tds;
    cout << "Plane Plate to remove : ";
    cin >> plate;
    planes.remove(Plane(plate, "", 0, f, ds, tds));
}

void Company::addFlight() {

    //...

}

void Company::removeFlight() {

    //...

}









