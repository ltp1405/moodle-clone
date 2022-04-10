#pragma once
#include <string>
using std::string;

struct Date {
    int day;
    int month;
    int year;
    Date(){}
    Date(int day, int month, int year);
    string toString(const string delim="/");
    bool valid();
};
