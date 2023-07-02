//
// Created by ruben on 18/12/2021.
//

#include "../include/Date.h"
#include <sstream>

Date::Date() {
    monthsDays = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
}

Date::Date(string &d) {
    data = d;

    stringstream ss(d);
    ss >> day >> sep1 >> month >> sep1 >> year >> sep2 >> hour >> sep3 >> minute >> sep3 >> second;
}

void Date::setYear(int y) {
    year = y;
}

void Date::setMonth(int m) {
    month = m;
}

void Date::setDay(int d) {
    day = d;
}

void Date::setHour(int h) {
    hour = h;
}

void Date::setMinute(int min) {
    minute = min;
}

void Date::setSecond(int sec) {
    second = sec;
}

int Date::getYear() const {
    return year;
}

int Date::getMonth() const {
    return month;
}

int Date::getDay() const {
    return day;
}

int Date::getHour() const {
    return hour;
}

int Date::getMinute() const {
    return minute;
}

int Date::getSecond() const {
    return second;
}

/**
 * Puts the date in the format DD/MM/YYYY_HH:MM:SS
 * @return String containing the date in the format referenced above
 */
string Date::show() const {
    stringstream ss;
    ss << setfill('0') << setw(2) << day << sep1 << setfill('0') << setw(2) << month << sep1 << setfill('0') << setw(2) << year << sep2 << setfill('0') << setw(2) << hour << sep3 << setfill('0') << setw(2) << minute << sep3 << setfill('0') << setw(2) << second;
    return ss.str();
}

/**
 * Calculates the time (in days) from the pre-default date (01/01/2020) to the saved date
 * @return Time between two dates in days
 */
int Date::daysSince2020() const {
    // Second date (d2) -> current date
    // Time on the current system
    time_t now = time(0);


    // Convert now to string form (example: "Thu Dec 16 07:55:32 2021")
    char* date_time = ctime(&now);
    int size_date_time = 24;
    string myString(date_time, size_date_time);


    // Extract peaces of the current time string (myString)
    string year2, month2, day2, hour2, minute2, second2;
    year2 = myString.substr(20,4);
    month2 = myString.substr(4,3);
    day2 = myString.substr(8,2);
    hour2 = myString.substr(11,2);
    minute2 = myString.substr(14,2);
    second2 = myString.substr(17,2);


    // Convert the month into numbers
    if (month2 == "Jan") month2 = "01";
    else if (month2 == "Feb" || month2 == "Fev") month2 = "02";
    else if (month2 == "Mar") month2 = "03";
    else if (month2 == "Apr" || month2 == "Abr") month2 = "04";
    else if (month2 == "May" || month2 == "Mai") month2 = "05";
    else if (month2 == "Jun") month2 = "06";
    else if (month2 == "Jul") month2 = "07";
    else if (month2 == "Aug" || month2 == "Ago") month2 = "08";
    else if (month2 == "Sep" || month2 == "Set") month2 = "09";
    else if (month2 == "Oct" || month2 == "Out") month2 = "10";
    else if (month2 == "Nov") month2 = "11";
    else if (month2 == "Dec" || month2 == "Dez") month2 = "12";


    // First date (d1) -> myDate
    // Compare the two dates
    vector<int> d1 = {day, month, year, hour, minute, second}; // my date
    vector<int> d2 = {stoi(day2), stoi(month2), stoi(year2), stoi(hour2), stoi(minute2), stoi(second2)}; // current date


    // (2) =========================================================================================================
    int n1, n2; // number of days between 01/01/2020 until d1 and d2, respectively
    int l1 = 0, l2 = 0; // Number of leap year since 2020


    // (2.1) Count the number of days before d2 (current date). Every leap year adds one day
    for (unsigned int y = 2020; y < d2[2]; y++) {
        if ( ((y%4 == 0) && (y%100 == 0) && (y%400 == 0)) || ((y%4 == 0) && (y%100 != 0)) ) l2++;
    }
    n2 = (l2*366) + ((d2[2] - 2020 - l2) * 365);

    if (((d2[2] % 4 == 0) && (d2[2] % 100 == 0) && (d2[2] % 400 == 0)) || ((d2[2] % 4 == 0) && (d2[2] % 100 != 0)) ) { // The current year is a leap year
        if (d2[0] <= 29 && d2[1] <= 2) { n2 += monthsDays[0] + d2[0]; } // Before or on the day 29 of Feb
        else if (d2[1] > 2) { // After the day 29 of Feb
            n2 += 1; // Add the 29th of Feb day
            for (unsigned int j = 0; j < d2[1] - 1; j++) { // Add the days from all the months until it reaches the current month
                n2 += monthsDays[j];
            }
            n2 += d2[0]; // Add the current day of the month
        }
    }

    else { // The current year is not a leap year
        for (unsigned int j = 0; j < d2[1] - 1; j++) {
            n2 += monthsDays[j];
        }
        n2 += d2[0]; // Add the current day of the month
    }


    // (2.2) Count the number of days before d1 (my Date). Every leap year adds one day
    for (unsigned int y = 2020; y < d1[2]; y++) {
        if ( ((y%4 == 0) && (y%100 == 0) && (y%400 == 0)) || ((y%4 == 0) && (y%100 != 0))) l1++;
    }
    n1 = (l1*366) + ((d1[2] - 2020 - l1) * 365);

    if (((d1[2] % 4 == 0) && (d1[2] % 100 == 0) && (d1[2] % 400 == 0)) || ((d1[2] % 4 == 0) && (d1[2] % 100 != 0)) ) { // The current year is a leap year
        if (d1[0] <= 29 && d1[1] <= 2) { n1 += monthsDays[0] + d1[0]; } // Before or on the day 29 of Feb
        else if (d1[1] > 2) { // After the day 29 of Feb
            n1 += 1; // Add the 29th of Feb day
            for (unsigned int j = 0; j < d1[1] - 1; j++) { // Add the days from all the months until it reaches the current month
                n1 += monthsDays[j];
            }
            n1 += d1[0]; // Add the current day of the month
        }
    }
    else { // The current year is not a leap year
        for (unsigned int j = 0; j < d1[1] - 1; j++) {
            n1 += monthsDays[j];
        }
        n1 += d1[0]; // Add the current day of the month
    }

    return (n1-n2); // (n1-n2) < 0 -> "Missed the flight!" ; 0 <= (n1-n2) <= 1 -> "Welcome abroad!" ; (n1-n2) > 1 -> "Its too early!"
}

/**
 * Calculates the time (in days) between the saved date and a date given
 * @param date2 (Second date)
 * @return Time between two dates (in days)
 */
int Date::daysBetweenDates(Date &date2) {
    // First date (d1) -> Time saved on the object of the class in the variables (year, month, day, hour, minute, second)
    // Second date (d2) -> Given date (date2)


    // Compare the two dates
    vector<int> d1 = {day, month, year, hour, minute, second}; // my date
    vector<int> d2 = {date2.getDay(), date2.getMonth(), date2.getYear(), date2.getHour(), date2.getMinute(), date2.getSecond()}; // second date


    // ============================================================================================================================================================
    // (2)
    int n1, n2; // number of days between 01/01/2020 until d1 and d2, respectively
    int l1 = 0, l2 = 0; // Number of leap year since 2020


    // (2.1) Count the number of days before d1. Every leap year adds one day
    for (unsigned int y = 2020; y < d1[2]; y++) {
        if ( ((y%4 == 0) && (y%100 == 0) && (y%400 == 0)) || ((y%4 == 0) && (y%100 != 0)) ) l1++;
    }
    n1 = (l1*366) + ((d1[2] - 2020 - l1)*365);

    if ( ((d1[2]%4 == 0) && (d1[2]%100 == 0) && (d1[2]%400 == 0)) || ((d1[2]%4 == 0) && (d1[2]%100 != 0)) ) { // My date is a leap year
        if (d1[0] <= 29 && d1[1] <= 2) { n1 += monthsDays[0] + d1[0]; } // Before or on the day 29 of Feb
        else if (d1[1] > 2) { // After the day 29 of Feb
            n1 += 1; // Add the 29th of Feb day
            for (unsigned int j = 0; j < d1[1]-1; j++) { // Add the days from all the months until it reaches the current month
                n1 += monthsDays[j];
            }
            n1 += d1[0]; // Add the current day of the month
        }
    }
    else { // The date year is not a leap year
        for (unsigned int j = 0; j < d1[1]-1; j++) {
            n1 += monthsDays[j];
        }
        n1 += d1[0]; // Add my date day of the month
    }


    // (2.2) Count the number of days before d2. Every leap year adds one day
    for (unsigned int y = 2020; y < d2[2]; y++) {
        if ( ((y%4 == 0) && (y%100 == 0) && (y%400 == 0)) || ((y%4 == 0) && (y%100 != 0))) l2++;
    }
    n2 = (l2*366) + ((d2[2] - 2020 - l2)*365);

    if ( ((d2[2]%4 == 0) && (d2[2]%100 == 0) && (d2[2]%400 == 0)) || ((d2[2]%4 == 0) && (d2[2]%100 != 0)) ) { // The year given is a leap year
        if (d2[0] <= 29 && d2[1] <= 2) { n2 += monthsDays[0] + d2[0]; } // Before or on the day 29 of Feb
        else if (d2[1] > 2) { // After the day 29 of Feb
            n2 += 1; // Add the 29th of Feb day
            for (unsigned int j = 0; j < d2[1]-1; j++) { // Add the days from all the months until it reaches the given month
                n2 += monthsDays[j];
            }
            n2 += d2[0]; // Add the given day of the month
        }
    }
    else { // The given year is not a leap year
        for (unsigned int j = 0; j < d2[1]-1; j++) {
            n2 += monthsDays[j];
        }
        n2 += d2[0]; // Add the given day of the month
    }

    return (n1-n2); // (n1-n2) <= 0 -> "On Time" ; (n1-n2) >= 0 -> "You're too late"
}