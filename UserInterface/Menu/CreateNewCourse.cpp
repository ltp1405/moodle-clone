#include "../App.h"
#include <iostream>
#include <string>
#include "../../School/Course.h"
#include "../../School/Semester.h"
using std::string;
using std::cout;
using std::cin;

bool validDay(string day) {
    return day == "mon"
        || day == "tue"
        || day == "wed"
        || day == "thu"
        || day == "fri"
        || day == "sat";
}

bool validTime(string time) {
    return time == "s1"
        || time == "s2"
        || time == "s3"
        || time == "s4";
}

Day parseDay(string day) {
    if (day == "mon")
        return Day::MON;
    if (day == "tue")
        return Day::TUE;
    if (day == "wed")
        return Day::WED;
    if (day == "thu")
        return Day::THU;
    if (day == "fri")
        return Day::FRI;
    return Day::SAT;
}

Time parseTime(string time) {
    if (time == "s1")
        return Time::S1;
    if (time == "s2")
        return Time::S2;
    if (time == "s3")
        return Time::S3;
    return Time::S4;
}

void App::promptCreateCourse() {
    if (!currentSemester) {
        cout << "No semester available" << endl;
        return;
    }
    string id;
    string name;
    string teacherName;
    int credits;
    int maxStudents;

    cin.ignore(1000, '\n');
    cout << "Enter course id: ";
    getline(cin, id);
    cout << "Enter course name: ";
    getline(cin, name);
    cout << "Enter course credits: ";
    cin >> credits;
    cout << "Enter max students: ";
    cin >> maxStudents;
    cout << "Enter teacher name: ";
    cin.ignore(1000, '\n');
    getline(cin, teacherName);

    currentSemester->addCourse(Course(id, name, credits, maxStudents, teacherName));
    cout << "Enter session 1 day (mon, tue, wed, thu, fri, sat): ";
    string day;
    while (!getline(cin, day) || !validDay(day)) {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Invalid input. Please type again(mon, tue, wed, thu, fri, sat): ";
    }
    Day d = parseDay(day);

    cout << "Enter session 1 time (s1, s2, s3, s4): ";
    string time;
    while (!getline(cin, time) || !validTime(time)) {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Invalid input. Please type again(s1, s2, s3, s4): ";
    }
    Time t = parseTime(time);
    currentSemester->courses.getTail()->data->addSession(Session(d, t));

    cout << "Enter session 2 day (mon, tue, wed, thu, fri, sat): ";
    while (!getline(cin, day) || !validDay(day)) {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Invalid input. Please type again(mon, tue, wed, thu, fri, sat): ";
    }
    d = parseDay(day);

    cout << "Enter session 2 time (s1, s2, s3, s4): ";
    while (!getline(cin, time) || !validTime(time)) {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Invalid input. Please type again(s1, s2, s3, s4): ";
    }
    t = parseTime(time);
    currentSemester->courses.getTail()->data->addSession(Session(d, t));
}
