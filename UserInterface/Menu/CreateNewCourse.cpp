#include "../App.h"
#include <iostream>
#include <string>
#include "../../School/Course.h"
#include "../../School/Semester.h"
using std::string;
using std::cout;
using std::cin;

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
    if (day == "sat")
        return Day::SAT;
}

Time parseTime(string time) {
    if (time == "s1")
        return Time::S1;
    if (time == "s2")
        return Time::S2;
    if (time == "s3")
        return Time::S3;
    if (time == "s4")
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
    cout << "Enter session day of session 1(mon, tue, wed, thu, fri, sat): ";
    string day;
    getline(cin, day);
    Day d = parseDay(day);
    cout << "Enter session time(s1, s2, s3, s4): ";
    string time;
    getline(cin, time);
    Time t = parseTime(time);
    currentSemester->courses.getTail()->data.addSession(Session(d, t));
}
