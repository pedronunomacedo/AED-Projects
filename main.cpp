#include <iostream>
#include <vector>
#include <windows.h>
#include "Tests/Flight.h"


using namespace std;

struct passenger {
    int ssn;
    string name;
};

passenger checkPassenger(int ssn){              // este int depois será substituido pela class passenger
    passenger p1, p2;
    p1.name = "Manuel";
    p1.ssn = 111;
    p2.name = "Ana";
    p2.ssn = 222;
    vector<passenger> pasr {p1, p2};
    for (int i = 0; i < pasr.size();i++)
        if (ssn == pasr[i].ssn)
            return pasr[i];
    string name;
    cout << "What's your Name ?\n";
    cout << "Name : ";
    cin >> name;
    cout << endl;
    passenger p3;                   //cria-se e adiciona-se o novo passenger á lista geral
    p3.name = name;
    p3.ssn = ssn;
    pasr.push_back(p3);
    return p3;                         // return a esse novo passenger

}


void userMenu() {
    int ssn, psg;
    cout << "What's your SSN ?\n";
    cout << "SSN : ";
    cin >> ssn;
    cout << endl;
    passenger p;
    p = checkPassenger(ssn);

    int userChoice;
    do{
        system("cls");
        cout << "Your SSN : " << p.ssn << "Name : " << p.name << "\n\n";
        cout << "1 - Check-in\n";
        cout << "2 - Buy Ticket\n";
        cout << "0 - Return to Menu\n";
        cout << "Option : ";
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
                    cout << "Welcome to Check-in\n";    //passenger p.checkIn
                    Sleep(500);
                    break;
                case 2 :
                    cout << "For what country\n";       // p.buyTicket
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

void settingsMenu(){
    int setChoice;
    do{
        system("cls");
        cout << "Settings\n\n";
        cout << "1 - Show All Flights\n";
        cout << "2 - Add Flight\n";
        cout << "3 - Remove Flight\n";
        cout << "0 - Return to Menu\n";
        cout << "Option : ";
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
            switch (setChoice) {
                case 1 :
                    cout << "Flights : \n";
                    Sleep(500);
                    break;
                case 2 :
                    cout << "Number of Flight to add\n";        //chamar classes e dar add
                    Sleep(500);
                    break;
                case 3 :
                    cout << "Number of Flight to remove\n";
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


void mainMenu(){
    int choice;
    do{
        system("cls");
        cout << "Main Menu\n\n";
        cout << "1 - User HelpDesk\n";
        cout << "2 - App Settings\n";
        cout << "0 - Exit App\n";
        cout << "Option : ";
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

int main() {

    //add a read all files to init the program

    cout << "Welcome to MYFLY Airline !\n\n";
    Sleep(600);

    mainMenu();     //call to mainMenu !

    //add an update/record all modifications before quit the program

    return 0;
}