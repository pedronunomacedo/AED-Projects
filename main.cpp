#include <iostream>
#include <windows.h>
#include "Tests/Flight.h"


using namespace std;


void userMenu() {
    int userChoice;
    do{
        cout << "UserMenu\n\n";
        cout << "1 - Check-in\n";
        cout << "2 - Buy Ticket\n";
        cout << "0 - Return to Menu\n";
        cin >> userChoice;
        if (cin.eof())
            break;
        system("cls");
        switch (userChoice) {
            case 1 : cout << "Welcome to Check-in\n"; Sleep(500); break;
            case 2 : cout << "For what country\n"; Sleep(500); break;
            case 0 : break;
            default: break;
        }
        system("cls");
    }while (userChoice != 0);
}

void settingsMenu(){
    int setChoice;
    do{
        cout << "Settings\n\n";
        cout << "1 - Show All Flights\n";
        cout << "2 - Add Flight\n";
        cout << "3 - Remove Flight\n";
        cout << "0 - Return to Menu\n";
        cin >> setChoice;
        if (cin.eof())
            break;
        system("cls");
        switch (setChoice) {
            case 1 : cout << "Flights : \n"; Sleep(500); break;
            case 2 : cout << "Number of Flight to add\n"; Sleep(500); break;
            case 3 : cout << "Number of Flight to remove\n"; Sleep(500); break;
            case 0 : break;
            default: break;
        }
        system("cls");
    }while (setChoice != 0);
}

int main() {
    cout << "Welcome to MYFLY Airline !" << endl << endl ;
    int choice;
    do{
        cout << "Menu\n\n";
        cout << "1 - User HelpDesk\n";
        cout << "2 - App Settings\n";
        cout << "0 - Exit App\n";
        cin >> choice;
        cout << endl;
        if (!cin.good() || cin.eof())
            break;
        system("cls");
        switch (choice) {
            case 1 : userMenu(); break;
            case 2 : settingsMenu(); break;
            case 3 : exit(0);
            default : break;
        }
        system("cls");
    }while (choice != 0);

    return 0;
}
