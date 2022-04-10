#pragma once
#include <iterator>
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
    friend bool operator>(const Date &d1, const Date &d2);
    friend bool operator<(const Date &d1, const Date &d2);
    friend bool operator==(const Date &d1, const Date &d2);
    friend bool operator>=(const Date &d1, const Date &d2);
    friend bool operator<=(const Date &d1, const Date &d2);
};

Date today();
