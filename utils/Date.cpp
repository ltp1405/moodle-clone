#include "Date.h"
#include <ios>
#include <sstream>
using std::to_string;
#include <iostream>
#include <chrono>
#include <ctime>    

Date today() {
    std::time_t t = std::time(0);
    std::tm *now = std::localtime(&t);
    return Date(now->tm_mday+1, now->tm_mon+1, now->tm_year+1900);
}

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

bool operator>(const Date &d1, const Date &d2) {
    if (d1.year < d2.year)
        return false;
    else if (d1.year > d2.year)
        return true;

    if (d1.month < d2.month)
        return false;
    else if (d1.month > d2.month)
        return true;

    if (d1.day < d2.day)
        return false;
    else if (d1.day > d2.day)
        return true;

    return false;
}

bool operator<(const Date &d1, const Date &d2) {
    return !(d1 > d2 || d1 == d2);
}

bool operator==(const Date &d1, const Date &d2) {
    return (d1.year == d2.year
        && d1.month == d2.month
        && d1.day == d2.day);
}

bool operator>=(const Date &d1, const Date &d2) {
    return (d1 > d2 || d1 == d2);
}

bool operator<=(const Date &d1, const Date &d2) {
    return (d1 < d2 || d1 == d2);
}
