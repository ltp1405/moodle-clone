#include <regex>
#include <string>
#include <sstream>

#include "../App.h"
#include "../../School/RegistrationSession.hpp"

using namespace std;

const regex date_expr("(?:(?:31(\\/|-|\\.)(?:0?[13578]|1[02]))\\1|(?:(?:29|30)(\\/|-|\\.)(?:0?[1,3-9]|1[0-2])\\2))(?:(?:1[6-9]|[2-9]\\d)?\\d{2})$|^(?:29(\\/|-|\\.)0?2\\3(?:(?:(?:1[6-9]|[2-9]\\d)?(?:0[48]|[2468][048]|[13579][26])|(?:(?:16|[2468][048]|[3579][26])00))))$|^(?:0?[1-9]|1\\d|2[0-8])(\\/|-|\\.)(?:(?:0?[1-9])|(?:1[0-2]))\\4(?:(?:1[6-9]|[2-9]\\d)?\\d{2})");
const regex time_expr("^(((([0-1][0-9])|(2[0-3])):?[0-5][0-9]:?[0-5][0-9]+$))");

tm getDateTimefromString(string date, string time) {
    stringstream ss(date + ' ' + time);
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

void openRegistrationSession() {
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
    start = getDateTimefromString(start_date, start_time);
    end = getDateTimefromString(end_date, end_time);
    RegistrationSession regSession(start, end);
}

bool checkDateFormat(string date) {
    return regex_match(date, date_expr);
}

bool checkTimeFormat(string time) {
    return regex_match(time, time_expr);
}

void App::promptOpenRegistrationSession() {
    
    openRegistrationSession();
}