#pragma once
#include <string>
using std::string;
using std::to_string;

struct Date {
    int day;
    int month;
    int year;
    Date(){}
    Date(int day, int month, int year);
    string toString();
};
