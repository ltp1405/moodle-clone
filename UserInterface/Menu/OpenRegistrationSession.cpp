#include <regex>
#include <string>
#include <sstream>

#include "OpenRegistrationSession.h"
#include "../App.h"
#include "../../School/RegistrationSession.hpp"

using namespace std;

tm getDateTimefromString(string datetime) {
    stringstream ss(datetime);
    tm tm{};
    string str;
    getline(ss, str, '/');
    tm.tm_mday = stoi(str);
    getline(ss, str, '/');
    tm.tm_mon = stoi(str) - 1;
    getline(ss, str, ' ');
    tm.tm_year = stoi(str) - 1900;

    getline(ss, str, ':');
    tm.tm_hour = stoi(str);
    getline(ss, str, ':');
    tm.tm_min = stoi(str);
    getline(ss, str, ':');
    tm.tm_sec = stoi(str);
    return tm;
}

RegistrationSession openRegistrationSession() {
    string start_date, end_date, start_time, end_time;
    cout << "Enter start date for Registration Session(dd/mm/yyyy): ";
    cin.ignore(100, '\n');
    do {
        getline(cin, start_date, '\n');
        cout << (checkDateFormat(start_date) ? "" : "Invalid date! Please try again: ");
    } while (!checkDateFormat(start_date));

    cout << "Enter start time for Registration Session(hh:mm:ss): ";
    do {
        getline(cin, start_time, '\n');
        cout << (checkTimeFormat(start_time) ? "" : "Invalid time! Please try again: ");
    } while (!checkTimeFormat(start_time));

    cout << "Enter end date for Registration Session(dd/mm/yyyy): ";
    do {
        getline(cin, end_date, '\n');
        cout << (checkDateFormat(end_date) ? "" : "Invalid date! Please try again: ");
    } while (!checkDateFormat(end_date));

    cout << "Enter end time for Registration Session(hh:mm:ss): ";
    do {
        getline(cin, end_time, '\n');
        cout << (checkTimeFormat(end_time) ? "" : "Invalid time! Please try again: ");
    } while (!checkTimeFormat(end_time));
    
    tm start{}, end{};
    start = getDateTimefromString(start_date + ' ' + start_time);
    end = getDateTimefromString(end_date + ' ' + end_time);
    return RegistrationSession(start, end);
}

bool checkDateFormat(string date) {
    return regex_match(date, date_expr);
}

bool checkTimeFormat(string time) {
    return regex_match(time, time_expr);
}

void App::promptOpenRegistrationSession() {
    system("cls");
    mktime(&regSession.start);
    mktime(&regSession.end);
    char ans = ' ', start_buf[26], end_buf[26];
    asctime_s(start_buf, sizeof start_buf, &regSession.start);
    asctime_s(end_buf, sizeof end_buf, &regSession.end);
    cout << "The current Registration Session opens from: " << start_buf
        << "to: " << end_buf
        << "Would you like to change the current Registration Session? (y/n): ";
    while (ans != 'y' && ans != 'Y' && ans != 'n' && ans != 'N') {
        cin >> ans;
        cin.ignore(100, '\n');
        if (ans == 'y' || ans == 'Y')
            regSession = openRegistrationSession();
        else if (ans == 'n' || ans == 'N')
            return;
        else 
            cout << "Please enter y or n.\n";
    }
}