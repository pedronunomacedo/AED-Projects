#include <iostream>
#include <windows.h>
#include <vector>
#include "Tests/Flight.h"


using namespace std;


void userMenu() {
    int userChoice;
    do{
        system("cls");
        cout << "UserMenu\n\n";
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
                    cout << "Welcome to Check-in\n";
                    Sleep(500);
                    break;
                case 2 :
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
                    cout << "Number of Flight to add\n";
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
                    exit(0);
                default :
                    cout << "Invalid Option! Try Again\n";
                    Sleep(400);
                    break;
            }
        }
    }while (choice != 0);
}

int main() {
    vector<Flight> flights;
    cout << "Welcome to MYFLY Airline !\n\n";
    Sleep(600);

    mainMenu();     //call to mainMenu !

    return 0;
}