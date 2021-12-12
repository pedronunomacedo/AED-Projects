//
// Created by pedro on 01/12/2021.
//

#include "Company.h"
#include <string>
#include <iostream>
#include <iomanip>
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
        list<Flight> fls;
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
            Flight f (numberF,durationF,dateF,origin,dest, capP);
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
    string sep = " - ";
    string nP;
    getline (dataPs, nP); // Number of passengers (first line of the file)
    int nPs = stoi(nP);
    for (int i = 0; i < nPs; i++){
        string line;
        getline(dataPs, line); // Next passenger
        stringstream ss(line);
        vector<Ticket> tickets;
        int ssn, nTickets;
        string name;
        ss >> name >> sep >> ssn >> sep >> nTickets;
        for (int j = 0; j < nTickets; j++){
            int nF;
            int pck;
            string line1;
            getline(dataPs, line1);
            stringstream ss1(line1);
            ss1 >> pck >> sep >> nF;
            tickets.push_back(Ticket(pck, nF));
        }
        Passenger p(name, ssn, tickets);
        passengers.push_back(p);
    }
}

bool Company::checkPassenger(Passenger &p){
    int ssn;
    cout << "Enter your SSN : "; cin >> ssn;
    for (auto &k : passengers)
        if (k.getSSN() == ssn) {
            p = k;
            return true;
        }
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
            Passenger p;
            switch (userChoice) {
                case 1 :
                    cout << "Register Passenger\n\n";
                    addPassenger();
                    Sleep(500);
                    break;
                case 2 :
                    if (checkPassenger(p)) {
                        cout << "Welcome to Check-in\n";
                        checkIn(p);
                    }
                    Sleep(500);
                    break;
                case 3 :
                    if (checkPassenger(p))
                        buyTicket();

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
        cout << "7 - Show All Planes\n";
        cout << "8 - Add Plane\n";
        cout << "9 - Remove Plane\n";
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
                    cout << "Adding Flight ...\n\n";
                    addFlight();
                    Sleep(500);
                    break;
                case 3 :
                    cout << "Removing Flight ...\n\n";
                    removeFlight();
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
                case 7 :
                    cout << "Planes : \n\n";
                    showAllPlanes();
                    Sleep(999);
                    break;
                case 8 :
                    cout << "Adding Plane ...\n\n";
                    addPlane();
                    Sleep(500);
                    break;
                case 9 :
                    cout << "Removing Passenger ...\n\n";
                    removePlane();
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
    cout << "-------------------------------" << endl;
    for (auto &k : planes)
        for (auto &i : k.getFlights())
            i.show();
        cout << "-------------------------------" << endl;
}

void Company::showAllPassengers() {
    cout << "-------------------------------" << endl;
    for (auto &k : passengers) {
        cout << k.getName() << " | " << k.getSSN() << endl;
        for (auto &t : k.getTickets())
            cout << t.getPackage() << " | " << t.getFlightNumber() << endl;
        cout << "-------------------------------" << endl;
    }
}

void Company::showAllPlanes() {
    cout << "     Plate     |     Type     |     Capacity     " << endl;
    for (Plane &p : planes) {
        cout << setw(9) << p.getPlate() << setw(7) << "|" << setw(9) << p.getType() << setw(6) << "|" << setw(10) << p.getCapacity() << endl;
    }
}

void Company::addPassenger() {
    int ssn; string name;
    cout << "Passenger SSN to add : ";cin >> ssn;cin.ignore();
    for (auto &k : passengers)
        if (k.getSSN() == ssn){
            cout << "SSN already in use !\n";
            return;
        }
    cout << "Passenger FirstName to add : "; getline(cin,name);
    vector<Ticket> t{};
    passengers.push_back(Passenger(name,ssn, t));
}

void Company::removePassenger() {
    int ssn;
    string name;
    cout << "Passenger SSN to remove : ";
    cin >> ssn;
    for (auto &k : passengers)
        if (k.getSSN() == ssn) {
            vector<Ticket> t;
            passengers.remove(Passenger(name, ssn, t));
            return;
        }
    cout << "Passenger not found !\n";
}


void Company::record(ofstream &dataPl, ofstream &dataPs) {
    string sep = " - ";

    //recording passengers
    dataPs << passengers.size() << endl;
    for (auto &p : passengers) {
        dataPs << p.getName() << sep << p.getSSN() << sep << p.getTickets().size() << endl;
        for (auto &t : p.getTickets())
            dataPs << int(t.getPackage()) << sep << t.getFlightNumber() << endl;
    }

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
    int plate;
    list<Flight> fl{}; vector<Service> ds{}; queue<Service> tds{};
    cout << "Plane plate to add : "; cin >> plate; cout << endl;
    if (find(planes.begin(), planes.end(), Plane(plate, "", 0,  fl, ds, tds)) == planes.end()) {
        int cap;
        string type;
        cout << "Type : "; cin >> type; cout << endl;
        cout << "Capacity : "; cin >> cap; cout << endl;
        planes.push_back(Plane(plate, type, cap, fl, ds, tds));
        return;
    }
    cout << "Plane already exists !\n\n";
}

void Company::removePlane() {
    int plate;
    list<Flight> f{}; vector<Service> ds{}; queue<Service> tds{};
    cout << "Plane plate to remove : ";
    cin >> plate;
    planes.remove(Plane(plate, "", 0, f, ds, tds));
}

void Company::addFlight() {
    list<Flight> fl{}; vector<Service> ds{}; queue<Service> tds{};
    int number, duration, plate;
    string ori, dest, date;
    Date d;
    cout << "Plate number of the plane you want to add a Flight : "; cin >> plate; cout << endl;
    auto it = find(planes.begin(), planes.end(), Plane(plate, "", 0,  fl, ds, tds));
    if (it == planes.end()){
        cout << "Plane not found !\n\n";
        return;
    }
    cout << "Date (dd/mm/yyyy) of the Flight : "; cin >> date; cout << endl;
    d = Date(date);
    for (auto &f: it->getFlights()) {
        if (f.getDepartureDate() == d) {
            cout << "Date not available !\n\n";
            return;
        }
    }
    int cnt;
    cout << "Flight number : "; cin >> number; cout << endl;
    for (auto &i : planes)
        if (find(i.getFlights().begin(), i.getFlights().end(), Flight(number, 0, Date(), "", "", 0)) != i.getFlights().end()) {
            cnt ++;

        }
    if (cnt > 0) return;
    cout << "Duration : "; cin >> duration; cout << endl;
    cout << "Origin : "; cin >> ori; cout << endl;
    cout << "Destination : "; cin >> dest; cout << endl;
    it->getFlights().push_back(Flight(number, duration, d, ori, dest, it->getCapacity()));
}

void Company::removeFlight() {
    int fNumber;
    cout << "Flight Number to remove : "; cin >> fNumber;
    for (auto &p : planes){
        p.getFlights().remove(Flight(fNumber, 0, Date(), "", "", 0));
    }
}



void Company::checkIn(Passenger &p) {
    // fazer uma binary search para encontrar os voos correspondentes ao nFL do ticket !!
    vector<Flight> fls = getFlightsToCheckIn();
    int nCheckIn = 0;
    for (auto &t : p.getTickets())
        for (auto &f : fls)
            if (t.getFlightNumber() == f.getFlightNumber())
                nCheckIn++;
    cout << "you have " << nCheckIn << " flights available to Check-in !!\n\n";

}

vector<Flight> Company::getFlightsToCheckIn() const {
    vector<Flight> flights;
    Date date = Date();
    for (auto pl : planes)
        for (auto &f : pl.getFlights())     // verificar caso a data seja nos ultimos dias do mes !!!
            if (date.getDay() - f.getDepartureDate().getDay() <= 1 && date.getMonth() == f.getDepartureDate().getMonth() && date.getYear() == f.getDepartureDate().getYear())
                flights.push_back(f);

    sort(flights.begin(), flights.end());       //maybe implement a quicksort !!!
    return flights;
}

void Company::buyTicket() {
    // Reduzir o número de lugares ocupados no flight





    /*
    // Variables
    bool validInput = false, fExist = false;
    int nFlight, planePlate;

    // Print a todos os voos disponiveis
    cout << endl;

    cout << endl;

    // Perguntar qual é o número do voo que deseja
    cout << "What's the name of the flight you want to buy? ";
    while (!validInput || !fExist) {
        if (!(cin >> nFlight) || !fExist) {
            cin.clear(); cin.ignore(1000, '\n');
            cout << "Invalid input! Please input a number: ";
            validInput = false;
        }
        else {
            for (Plane p : planes) {
                for (Flight f : p.getFlights()) {
                    planePlate = p.getPlate();
                    if (f.getFlightNumber() == nFlight) {
                        fExist = true;
                        if (f.getAvailablePlaces(planePlate) > 0) {
                            validInput = true;
                        }
                    }
                }
                if (fExist || validInput) {break; }
            }
        }
        if (!validInput) {
            cout << "The plane you want its fulled! Please choose another flight: ";
        }

    }

    return nFlight;
    */
}









