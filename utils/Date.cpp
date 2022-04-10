#include "Date.h"
#include <ios>
#include <sstream>
using std::to_string;

Date::Date(int day, int month, int year) {
    this->day = day;
    this->month = month;
    this->year = year;
}

string Date::toString(string delim) {
    if (!day || !month || !year)
        return "";
    std::stringstream ss;
    ss.setf(std::ios::showpoint | std::ios::right);
    ss.width(2);
    ss.fill('0');
    ss << day << delim;
    ss.width(2);
    ss << month << delim;
    ss.width(4);
    ss << year;
    return ss.str();
}

bool Date::valid() {
    if (year < 0)
        return false;
    if (month < 1 || month > 12)
        return false;

    bool isLeap;
    int numberOfDay;
    if (year % 4 != 0 || year % 100 == 0 && year % 400 != 0)
        isLeap = false;
    else 
        isLeap = true;

    if (month == 1 || month == 3 || month == 5 || month == 7 ||
        month == 8 || month == 10 || month == 12)
        numberOfDay = 31;
    else if (month == 2 && isLeap) 
        numberOfDay = 29;
    else if (month == 2 && !isLeap)
        numberOfDay = 28;
    else
        numberOfDay = 30;

    if (day < 1 || day > numberOfDay)
        return false;

    return true;
}
