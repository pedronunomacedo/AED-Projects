//
// Created by pedro on 01/12
#include "Company.h"
#include <string>
#include <iostream>
#include <sstream>
#include <queue>
#include <algorithm>

void waitEnter(){
    cin.clear();cin.ignore();
    std::cout << std::endl << "Press enter to continue..." << std::endl;
    std::string str;
    std::getline(std::cin, str);
}

/**
 * Search for a specific flight in the flights BST
 * @param v (vector of flights)
 * @param el (number of the flight to search)
 * @return Returns the middle if it exists, or 0 otherwise
 */
int BinarySearch(vector<Flight> v, int el){
    int left = 0, right = v.size() - 1;
    while (left <= right)
    {
        int middle = (left + right) / 2;
        if (v[middle].getFlightNumber() < el) {
            left = middle + 1;
        }
        else if (el < v[middle].getFlightNumber()) {
            right = middle -1;
        }
        else{
            return middle;
        } // found
    }
    return 0;
}

/**
 * Swap to flights
 * @param a (flight number 1)
 * @param b (flight number 2)
 */
void swap(Flight* a, Flight* b)
{
    Flight t = *a;
    *a = *b;
    *b = t;
}

// partition the array using last element as pivot
int partition (vector<Flight> &v, int low, int high)
{
    int pivot = v[high].getFlightNumber();    // pivot
    int i = (low - 1);

    for (int j = low; j <= high - 1 ; j++)
    {
        //if current element is smaller than pivot, increment the low element
        //swap elements at i and j
        if (v[j].getFlightNumber() <= pivot)
        {
            i++;    // increment index of smaller element
            swap(&v[i], &v[j]);
        }
    }
    swap(&v[i + 1], &v[high]);
    return (i + 1);
}

void sort(vector<Flight> &v, int low, int high)
{
    if (low < high)
    {
        //partition the array
        int pivot = partition(v, low, high);

        //sort the sub arrays independently
        sort(v, low , pivot - 1);
        sort(v, pivot + 1, high);
    }
}

/**
 * Update the vector of flights, toDoServices and DoneServices in order not to have flights
 * with an expired date
 */
void Company::update() {
    for (auto &p : planes) {
        for (auto f = p.getFlights().begin(); f != p.getFlights().end(); f++) {
            if (f->getDepartureDate().daysSince2020() < 0) {
                p.getFlights().remove(*f--);
            }
        }
        for (int i = 0; i < p.getToDoServ().size(); i++){
            if (p.getToDoServ().front().getDate().daysSince2020() < 0){
                p.getDoneServ().push_back(p.getToDoServ().front());
                p.getToDoServ().pop();
            }
        }
    }
}

/**
 * Initializes the company, reading the information from the PASSENGERS.txt, PLANES.txt and AIRPORT.txt
 * and saving the airports, the planes, the servicesDone and the toDoServices.
 * @param dataPl (text file which contains all the planes information and the respective services)
 * @param dataPs (text file witch contains all the information about the passengers and the respective flights)
 * @param dataAir (text file witch contains all the information about the nearest transports to the airport and the respective distance)
 */
Company::Company(ifstream &dataPl, ifstream &dataPs, ifstream &dataAir) {
    //read airports !
    int nAirports;
    string nAir;
    getline(dataAir, nAir);
    nAirports = stoi(nAir);
    for (int i = 0; i < nAirports; i++){
        Airport a;
        a.readFile(dataAir);
        airports.push_back(a);
    }

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
            string l, origin, dest, date;
            int numberF, durationF, ocPlaces;
            getline(dataPl,l);
            stringstream ss1(l);
            ss1 >> numberF >> sep >> date >> sep >> durationF >> sep >> origin >> sep >> dest >> sep >> ocPlaces;
            Date dateF(date);
            Flight f (numberF,durationF,dateF,origin,dest, capP, ocPlaces);
            fls.push_back(f);
        }

        getline(dataPl,nDS);
        int nDoneServ = stoi(nDS);
        for (int j = 0; j < nDoneServ; j++){
            string l, typeS, nameS, date;
            getline(dataPl,l);
            stringstream ss1(l);
            ss1 >> typeS >> sep >> date >> sep >> nameS;
            Date dateS(date);
            Service sv(typeS, dateS, nameS);
            doneServ.push_back(sv);
        }

        getline(dataPl,nTDS);
        int nToDoServ = stoi(nTDS);
        for (int j = 0; j < nToDoServ; j++){
            string l, typeS, nameS, date;
            getline(dataPl,l);
            stringstream ss1(l);
            ss1 >> typeS >> sep >> date >> sep >> nameS;
            Date dateS(date);
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

    update();
}

/**
 * Checks if the passenger is already registered in the system
 * @param p (passenger to verified)
 * @return (true if is registed, or false otherwise)
 */
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

/**
 * Displays the menu options (User Menu)
 */
void Company::userMenu() {
    int userChoice;
    do{
        CLEAR_MACRO();
        cout << "\tUser Menu\n\n";
        cout << "1 - Register\n";
        cout << "2 - Check-in\n";
        cout << "3 - Buy Ticket\n";
        cout << "0 - Return to Menu\n";
        cout << endl << "Option : ";
        cin >> userChoice;
        cout << endl;
        if (cin.fail()) {
            cout << "Invalid Input !" << endl;
            cin.clear();
            cin.ignore(9999, '\n');
            userChoice = -1;
        }
        else {
            CLEAR_MACRO();
            Passenger p;
            switch (userChoice) {
                case 1 :
                    cout << "Register Passenger\n\n";
                    addPassenger();
                    break;
                case 2 :
                    if (checkPassenger(p)) {
                        cout << "Welcome to Check-in\n\n";
                        checkIn(p);
                    }
                    waitEnter();
                    break;
                case 3 :
                    if (checkPassenger(p)) {
                        cout << "Buying Ticket \n\n";
                        buyTicket(p);
                    }
                    waitEnter();
                    break;
                case 0 :
                    break;
                default:
                    cout << "Invalid Option! Try Again\n";
                    break;
            }
        }
    }while (userChoice != 0);
}

/**
 * Displays the settings Menu (menu to manage the airport)
 */
void Company::settingsMenu(){
    int setChoice;
    do{
        CLEAR_MACRO();
        cout << "\tSettings\n\n";
        cout << "1 - Show All Flights\n";
        cout << "2 - Add Flight\n";
        cout << "3 - Remove Flight\n";
        cout << "4 - Show All Passengers\n";
        cout << "5 - Add Passenger\n";
        cout << "6 - Remove Passenger\n";
        cout << "7 - Show All Planes\n";
        cout << "8 - Add Plane\n";
        cout << "9 - Remove Plane\n";
        cout << "10 - Show All Services\n";
        cout << "11 - Add Service\n";
        cout << "12 - Remove Service\n";
        cout << "0 - Return to Menu\n";
        cout << endl << "Option : ";
        cin >> setChoice;
        cout << endl;
        if (cin.fail()) {
            cout << "Invalid Input !" << endl;
            cin.clear();
            cin.ignore(9999, '\n');
            setChoice = -1;
        }
        else {
            CLEAR_MACRO();
            string name; int ssn;
            switch (setChoice) {        // falta addFlight, removeFlight, showAllPlanes, ...('shows')
                case 1 :
                    cout << "Flights : \n\n";
                    showAllFlights();
                    waitEnter();
                    break;
                case 2 :
                    cout << "Adding Flight ...\n\n";
                    addFlight();
                    break;
                case 3 :
                    cout << "Removing Flight ...\n\n";
                    removeFlight();
                    break;
                case 4 :
                    cout << "Passengers : \n\n";
                    showAllPassengers();
                    waitEnter();
                    break;
                case 5 :
                    cout << "Adding Passenger ...\n\n";
                    addPassenger();
                    break;
                case 6 :
                    cout << "Removing Passenger ...\n\n";
                    removePassenger();
                    break;
                case 7 :
                    cout << "Planes : \n\n";
                    showAllPlanes();
                    waitEnter();
                    break;
                case 8 :
                    cout << "Adding Plane ...\n\n";
                    addPlane();
                    break;
                case 9 :
                    cout << "Removing Passenger ...\n\n";
                    removePlane();
                    break;
                case 10 :
                    cout << "Services : \n\n";
                    showAllServices();
                    waitEnter();
                    break;
                case 11 :
                    cout << "Adding Service ...\n\n";
                    addService();
                    break;
                case 12 :
                    cout << "Removing Service ...\n\n";
                    removeService();
                    break;
                case 0 :
                    break;
                default:
                    cout << "Invalid Option! Try Again\n";
                    break;
            }
        }
    } while (setChoice != 0);
}

/**
 * Displays the main Menu of the program where you choose to use it as a client or as
 * a manager of the airport
 */
void Company::mainMenu(){
    int choice;
    do{
        CLEAR_MACRO();
        cout << "\tMain Menu\n\n";
        cout << "1 - User HelpDesk\n";
        cout << "2 - App Settings\n";
        cout << "0 - Exit App\n";
        cout << endl << "Option : ";
        cin >> choice;
        cout << endl;
        if (cin.fail()) {
            cout << "Invalid Input !" << endl;
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
                    break;
            }
        }
    }while (choice != 0);
}

/**
 * Shows all the flights of the airport
 */
void Company::showAllFlights() {
    cout << "     Flight Number     |     Flight Date     |     Flight Time     |     Origin     |     Destination     |     Avaiable Places" << endl;
    cout << "====================================================================================================================================" << endl;
    vector<Flight> fls;
    for (auto &k : planes)
        for (auto &i : k.getFlights())
            fls.push_back(i);

    sort(fls,0,fls.size() - 1);
    for (auto &k: fls)
        k.show();

}

/**
 * Shows all the passengers registered in the company system
 */
void Company::showAllPassengers() {
    cout << "     Name     |     SSN     |      Package     |      Flight Number" << endl;
    cout << "======================================================================" << endl;
    for (auto &k : passengers) {
        k.show();
    }
}

/**
 * Shows all the available planes with the respective type and capacity
 */
void Company::showAllPlanes() {
    cout << "     Plate     |     Type     |     Capacity     " << endl;
    cout << "================================================" << endl;
    for (Plane &p : planes) {
        p.show();
    }
}

/**
 * Registers a passenger to the company system saving the respective name and SSN (Social Security Number)
 */
void Company::addPassenger() {
    int ssn; string name;
    do {
        cout << "Passenger SSN to add (xxxxxxxxx) : ";
        cin >> ssn;
        cin.ignore();
    }while (to_string(ssn).size() != 9);
    for (auto &k : passengers)
        if (k.getSSN() == ssn){
            cout << "SSN already in use !\n";
            return;
        }
    cout << "Passenger FirstName to add : "; getline(cin,name);
    vector<Ticket> t{};
    passengers.push_back(Passenger(name,ssn, t));
}

/**
 * Removes the register of a specific passenger from the company system
 */
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

/**
 * Save the updated information and all changes made to the respective file
 * @param dataPl
 * @param dataPs
 * @param dataAir
 */
void Company::record(ofstream &dataPl, ofstream &dataPs, ofstream &dataAir) {
    string sep = " - ";

    //recording airports
    dataAir << airports.size() << endl;
    for (auto &a : airports) {
        dataAir << a.getName() << sep << a.getTransportsSize() << endl;
        for(auto &t : a.getTransports())
            dataAir << t.getType() << sep << t.getDistance() << endl;
    }

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
            dataPl << f.getFlightNumber() << sep << f.getDepartureDate().show() << sep << f.getDuration() << sep << f.getOrigin() << sep << f.getDestination() << sep << f.getOccupiedPlaces() << endl;
        dataPl << p.getDoneServ().size() << endl;
        for (auto &ds : p.getDoneServ())
            dataPl << ds.getType() << sep << ds.getDate().show() << sep << ds.getEmployeeName() << endl;
        dataPl << p.getToDoServ().size() << endl;
        while(!p.getToDoServ().empty()){
            dataPl << p.getToDoServ().front().getType() << sep << p.getToDoServ().front().getDate().show() << sep << p.getToDoServ().front().getEmployeeName() << endl;
            p.getToDoServ().pop();
        }
    }
}

/**
 * Adds a plane to the list of planes belonging to the company
 */
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

/**
 * Removes a specific plane from the list of planes
 */
void Company::removePlane() {
    int plate;
    list<Flight> f{}; vector<Service> ds{}; queue<Service> tds{};
    cout << "Plane plate to remove : ";
    cin >> plate;
    planes.remove(Plane(plate, "", 0, f, ds, tds));
}

/**
 * Adds a flight to a specific plane, asking for the respective plan number and the departure date and
 * adds it to the the respective flight plan
 */
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
    cout << "Date (dd/mm/yyyy_hh:mm:ss) of the Flight : "; cin >> date; cout << endl;
    d = Date(date);
    for (auto &f: it->getFlights()) {
        if (f.getDepartureDate().daysBetweenDates(d) == 0) {
            cout << "Date not available !\n\n";
            return;
        }
    }
    int cnt;
    cout << "Flight number : "; cin >> number; cout << endl;
    for (auto &i : planes)
        if (find(i.getFlights().begin(), i.getFlights().end(), Flight(number, 0, Date(), "", "", 0, 0)) != i.getFlights().end()) {
            cnt ++;
        }
    if (cnt > 0) { cout << "Flight number already in use\n "; return; }
    cout << "Duration : "; cin >> duration; cout << endl;
    cout << "Origin : "; cin >> ori; cout << endl;
    cout << "Destination : "; cin >> dest; cout << endl;
    it->getFlights().push_back(Flight(number, duration, d, ori, dest, it->getCapacity(), 0));
}

/**
 * Removes a flight
 */
void Company::removeFlight() {
    int fNumber;
    cout << "Flight Number to remove : "; cin >> fNumber;
    for (auto &p : planes){
        p.getFlights().remove(Flight(fNumber, 0, Date(), "", "", 0, 0));
    }
}

/**
 * Process the passenger's check-in, showing the flights that he can make the check-in.
 * A passenger can only make the check-in before the flight leaves, within ne day f the departure date.
 * @param p
 */
void Company::checkIn(Passenger &p) {
    vector<Flight> fls = getFlightsToCheckIn();
    vector <Ticket> readyCk;
    for (auto &t : p.getTickets())
        if(BinarySearch(fls,t.getFlightNumber()))
            readyCk.push_back(t);

    if (readyCk.size() > 0) {
        cout << endl;
        cout << "    Flight Number    " << endl;
        cout << "=====================" << endl;
        for (auto &t: readyCk) {
            cout << t.getFlightNumber() << endl;
            cout << "---------------------" << endl;
        }
        cout << endl;
        char opt;
        cout << "Yes (Y) to confirm CheckIn\nNO (N) to cancel CheckIn\n( Y / N ) : ";cin >> opt;
        cout << endl;
        if (toupper(opt) == 'Y'){
            readyCk.erase(readyCk.begin());
            list<Flight>::iterator it;
            for (auto &pl : planes) {
                it = find(pl.getFlights().begin(), pl.getFlights().end(), Flight(readyCk[0].getFlightNumber(),0,Date(), "", "", 0, 0));
            }
            cout << "Additional information about destination airport : \n";
            for (auto &a : airports) {
                if (a.getName() == it->getDestination()){
                    a.showTransports();
                    break;
                }
            }
            cout << endl << "Have a nice flight !\n\nEnter any char to continue!\n";
            char i; cin >> i;
        }
        // selecionar opçao do ticket , retira lo ao passenger e perguntar sobre bagage !
    }
    else {cout << "you have " << readyCk.size() << " flights available to Check-in !!\n\n";}


}

/**
 * Calculates the flights hat are ready to check-in comparing the departure date with the current date
 * @return Flights that are ready to check-in
 */
vector<Flight> Company::getFlightsToCheckIn() const {
    vector<Flight> flights;
    Date date = Date();
    for (auto pl : planes)
        for (auto &f : pl.getFlights())
            if (f.getDepartureDate().daysSince2020() <= 1 && f.getDepartureDate().daysSince2020() >= 0)
                flights.push_back(f);

    sort(flights,0,flights.size() - 1);
    return flights;
}

/**
 * Manages the process of buying the passenger a ticket, showing all the flights available.
 * Also checking if the desired flight as available seats.
 * @param p (passenger that wants to buy a ticket)
 */
void Company::buyTicket(Passenger &p) {
    // Variables
    string numFlight, pack;
    bool validInput = true, avaiablePlaces = false, ynPackage;

    // Print a todos os voos disponiveis
    cout << endl;
    showAllFlights();
    cout << endl;

    // Asks for the number of the flight desired
    cout << "What's the number of the flight you want to buy? ";
    do {
        cin >> numFlight; validInput = true;
        for (unsigned l : numFlight) {
            if (!isdigit(l)) { validInput = false; break;}
        }
        if (validInput) {
            validInput = false;
            for (auto &pl: planes) {
                auto f = find(pl.getFlights().begin(), pl.getFlights().end(), Flight(stoi(numFlight), 0, Date(), "", "", 0, 0));
                if (f != pl.getFlights().end() && f->getAvailablePlaces() > 0){
                    validInput = true; avaiablePlaces = true;
                    f->setOccupiedPlaces();
                    cout << "Do you want to take package ";
                    do {
                        cout << "(y or n) : ";
                        cin >> pack;
                    }while (pack != "y" && pack != "Y" && pack != "n" && pack != "N" && !(cin.fail()));
                    if (pack == "y" || pack == "Y") { ynPackage = true; }
                    else { ynPackage = false; }

                    // Create and setup the ticket
                    auto it = find(passengers.begin(), passengers.end(), p);
                    it->getTickets().push_back(Ticket(ynPackage, stoi(numFlight)));
                    return;
                }
            }
        }
        if (!validInput) { cout << "Invalid input! Please input another number for the flight: "; }
        else if (!avaiablePlaces) { cout << "The flight is full! Please choose another flight: "; }        //atençao aquiii !!
    } while (!validInput);


}

/**
 * Adds a service (maintenance or cleaning) to a specific plane, asking for the type,
 * date and the responsible for the service
 */
void Company::addService() {
    string nameService, dateService, employeeService;
    int plateNumber;
    list<Flight> fl{}; vector<Service> ds{}; queue<Service> tds{};
    cout << "Say the plate of the plane you wish to stop for maintenance or cleaning:" << endl; cin >> plateNumber;
    auto it = find(planes.begin(), planes.end(), Plane(plateNumber, "", 0,  fl, ds, tds));
    if (it == planes.end()){
        cout << "Plane not found !\n\n";
        return;
    }
    cout << "What's the type of service you want to add (maintenance or cleaning)? "<< endl; cin >> nameService;
    cout << "In which date you want to add that service? format(dd/mm/yyyy_hh:mm:ss)"<< endl; cin >> dateService;
    cout << "What's the name of the responsible employee ?" << endl; cin >> employeeService;
    Date b = Date(dateService);
    Service p = Service(nameService,b,employeeService);
    it->setToDoServ(p);
}

/**
 * Removes a service of a specific plane
 */
void Company::removeService() {
    int plateNumber, opt;
    list<Flight> fl{}; vector<Service> ds{}; queue<Service> tds{};
    cout << "Say the plate of the plane you wish to remove a service:" << endl; cin >> plateNumber;
    auto it = find(planes.begin(), planes.end(), Plane(plateNumber, "", 0,  fl, ds, tds));
    if (it == planes.end()){
        cout << "Plane not found !\n\n";
        return;

    }
    vector<Service> helper = {};
    while(!it->getToDoServ().empty()){
        helper.push_back(it->getToDoServ().front());
        it->getToDoServ().pop();
    }
    int m = 0;
    for(auto &i: helper){
        cout << m << " : " << i.getType() << " " << i.getDate().show() << " " << i.getEmployeeName() << endl;
        m++;
    }
    cout << "Which service number you want to remove?" << endl;cin >> opt;
    helper.erase(helper.begin()+opt);
    for (auto &h: helper){
        it->setToDoServ(h);
    }
}

/**
 * Displays all the services and the respective plane
 */
void Company::showAllServices() {
    cout << "     Type     |        Date        |     Employee Name     |     Plane plate     " << endl;
    cout << "=================================================================================" << endl;
    for (auto p : planes)
        while(!p.getToDoServ().empty()){
            p.getToDoServ().front().show();
            p.getToDoServ().pop(); //21
            cout << setw(floor((21-to_string(p.getPlate()).size())/2)+to_string(p.getPlate()).size()) << p.getPlate() << endl;
            cout << "---------------------------------------------------------------------------------" << endl;
        }
}










