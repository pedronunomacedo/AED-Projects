//
// Created by pedro on 01/12/2021.
//

#include "Company.h"

Company::Company() {
    vector<Passenger> ps;
    ps.push_back(Passenger("Manuel",111));
    ps.push_back(Passenger("Ana",222));
    passengers = ps;
    //read files ... e inicializar vetores

}

Passenger Company::checkPassenger(int ssn){
    for (auto &k : passengers)
        if (k.getSSN() == ssn)
            return k;
    string name;
    cout << "What's your Name ?\n";
    cout << "Name : ";
    cin >> name;
    cout << endl;
    Passenger p3(name, ssn);
    passengers.push_back(p3);
    return p3;
}

