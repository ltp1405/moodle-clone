#include "Date.h"

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
