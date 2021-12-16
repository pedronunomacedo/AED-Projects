//
// Created by Pedro Macedo on 16/12/2021.
//

#include "Date.h"

Date::Date(string data) {
    date2 = data;

    stringstream ss; ss << date2;
    ss >> day2 >> sep >> month2 >> sep >> year2 >> sep >> hour2 >> sep >> minute2 >> sep >> second2;
}

unsigned int Date::getYear() const {
    return year2;
}

unsigned int Date::getMonth() const {
    return month2;
}

unsigned int Date::getDay() const {
    return day2;
}

string Date::getDate() const {
    cout << day2 << sep << month2 << sep << year2 << " - " << hour2 << ":" << minute2 << ":" << second2;
}

int Date::DaysBetweenDates(string &date2) {
    // First date (d1) -> current date
    // Time on the current system
    time_t now = time(0);

    // Convert now to string form (example: "Thu Dec 16 07:55:32 2021")
    char* date_time = ctime(&now);
    int size_date_time = 24;
    string myString(date_time, size_date_time);

    // Display the current time in *char and in string format
    cout << "The current date and time is " << date_time << endl; // Print the current time
    cout << "My string is " << myString << endl;

    // Extract peaces of the current time string (myString)
    string year, month, day, hour, minute, second;
    year = myString.substr(20,4);
    month = myString.substr(4,3);
    day = myString.substr(8,2);
    hour = myString.substr(11,2);
    minute = myString.substr(14,2);
    second = myString.substr(17,2);

    // Convert the month into numbers
    if (month == "Jan") month = "01";
    else if (month == "Feb" || month == "Fev") month = "02";
    else if (month == "Mar") month = "03";
    else if (month == "Apr" || month == "Abr") month = "04";
    else if (month == "May" || month == "Mai") month = "05";
    else if (month == "Jun") month = "06";
    else if (month == "Jul") month == "07";
    else if (month == "Aug" || month == "Ago") month = "08";
    else if (month == "Sep" || month == "Set") month = "09";
    else if (month == "Oct" || month == "Out") month = "10";
    else if (month == "Nov") month = "11";
    else if (month == "Dec" || month == "Dez") month = "12";

    // Display separately the date (my date d1)
    cout << " day = " << day << endl;
    cout << " month = " << month << endl;
    cout << " year = " << year << endl;
    cout << " hour = " << hour << endl;
    cout << " minute = " << minute << endl;
    cout << " second = " << second << endl;

    // Second date (d2)
    stringstream ss; ss << date2;

    ss >> day2 >> sep >> month2 >> sep >> year2 >> sep >> hour2 >> sep >> minute2 >> sep >> second2;

    // Display the second date in different variables
    cout << " =============================================\n";
    cout << " day2 = " << day2 << endl;
    cout << " month2 = " << month2 << endl;
    cout << " year2 = " << year2 << endl;
    cout << " hour2 = " << hour2 << endl;
    cout << " minute2 = " << minute2 << endl;
    cout << " second2 = " << second2 << endl;

    // Compare the two dates
    vector<int> d1 = {stoi(day), stoi(month), stoi(year), stoi(hour), stoi(minute), stoi(second)}; // current date
    vector<int> d2 = {day2, month2, year2, hour2, minute2, second2}; // second date

    // ============================================================================================================================================================
    // (2)
    vector<int> monthsDays = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; // monthsDays is not a leap year
    int n1, n2; // number of days between 01/01/2020 until d1 and d2, respectively
    int l1 = 0, l2 = 0; // Number of leap year since 2020

    // (2.1) Count the number of days before d1. Every leap year adds one day
    for (unsigned int y = 2020; y < d1[2]; y++) {
        if ( ((y%4 == 0) && (y%100 == 0) && (y%400 == 0)) || ((y%4 == 0) && (y%100 != 0)) ) l1++;
    }
    n1 = (l1*366) + ((d1[2] - 2020 - l1)*365);
    if ( ((d1[2]%4 == 0) && (d1[2]%100 == 0) && (d1[2]%400 == 0)) || ((d1[2]%4 == 0) && (d1[2]%100 != 0)) ) { // The current year is a leap year
        if (d1[0] <= 29 && d1[1] <= 2) { n1 += monthsDays[0] + d1[0]; } // Before or on the day 29 of Feb
        else if (d1[1] > 2) { // After the day 29 of Feb
            n1 += 1; // Add the 29th of Feb day
            for (unsigned int j = 0; j < d1[1]-1; j++) { // Add the days from all the months until it reaches the current month
                n1 += monthsDays[j];
            }
            n1 += d1[0]; // Add the current day of the month
        }
    }
    else { // The current year is not a leap year
        for (unsigned int j = 0; j < d1[1]-1; j++) {
            n1 += monthsDays[j];
        }
        n1 += d1[0]; // Add the current day of the month
    }


    // (2.2) Count the number of days before d2. Every leap year adds one day
    for (unsigned int y = 2020; y < d2[2]; y++) {
        if ( ((y%4 == 0) && (y%100 == 0) && (y%400 == 0)) || ((y%4 == 0) && (y%100 != 0))) l2++;
    }
    n2 = (l2*366) + ((d2[2] - 2020 - l2)*365);
    if ( ((d2[2]%4 == 0) && (d2[2]%100 == 0) && (d2[2]%400 == 0)) || ((d2[2]%4 == 0) && (d2[2]%100 != 0)) ) { // The current year is a leap year
        if (d2[0] <= 29 && d2[1] <= 2) { n2 += monthsDays[0] + d2[0]; } // Before or on the day 29 of Feb
        else if (d2[1] > 2) { // After the day 29 of Feb
            n2 += 1; // Add the 29th of Feb day
            for (unsigned int j = 0; j < d2[1]-1; j++) { // Add the days from all the months until it reaches the current month
                n2 += monthsDays[j];
            }
            n2 += d2[0]; // Add the current day of the month
        }
    }
    else { // The current year is not a leap year
        for (unsigned int j = 0; j < d2[1]-1; j++) {
            n2 += monthsDays[j];
        }
        n2 += d2[0]; // Add the current day of the month
    }
    // =================================================================================================================================================================
    /*
    if ( ((n2-n1) == 1)) { // The client can make the check-in, one day before or on the day of the flight
        cout << " Welcome abroad!\n";
    }
    else if (((n2-n1) == 0 && stoi(hour) < hour2) || ((n2-n1) == 0 && stoi(hour) == hour2 && stoi(minute) < minute2) || ((n2-n1) == 0 && stoi(hour) == hour2 && stoi(minute) == minute2 && stoi(second) <= second2)) {
        cout << " Welcome abroad!\n ";
    }
    else if ((n2-n1) > 1) { // The client cannot make the check-in, because is too early to do that
        cout << " You can't make the check-in because its to early. Come back later!\n";
    }
    else { // The client is too late to do the check-in
        cout << " I'm sorry! You miss your flight.\n";
    }
    */

    return (n2-n1);
}
