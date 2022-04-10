#include "Date.h"
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

string Date::toString() {
    if (!day || !month || !year)
        return "";
    string s = to_string(day) + "/" + to_string(month) + "/" + to_string(year);
    return s;
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
    return !(d1 > d2 && d1 == d2);
}

bool operator==(const Date &d1, const Date &d2) {
    return d1.year == d2.year
        && d1.month == d2.month
        && d1.day == d2.day;
}

bool operator>=(const Date &d1, const Date &d2) {
    return d1 > d2 || d1 == d2;
}

bool operator<=(const Date &d1, const Date &d2) {
    return d1 < d2 || d1 == d2;
}
