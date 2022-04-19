#include "../../School/Course.h"
#include "../App.h"
#include "../Menu.hpp"
#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::getline;

void promptChangeId(Course *crs) {
    cout << "Current ID: " << crs->id << endl;
    cout << "Please enter new ID: ";
    string id;
    cin.ignore(1000, '\n');
    std::getline(cin, id);
    crs->id = id;
}

void promptChangeName(Course *crs) {
    cout << "Current Name: " << crs->name << endl;
    cout << "Please enter new course name: ";
    string name;
    cin.ignore(1000, '\n');
    std::getline(cin, name);
    crs->name = name;
}

void promptChangeTeacher(Course *crs) {
    cout << "Current Teacher: " << crs->teacherName << endl;
    cout << "Please enter new teacher: ";
    string name;
    cin.ignore(1000, '\n');
    std::getline(cin, name);
    crs->teacherName = name;
}

void updateSessions(Course *course) {
    cin.ignore(100, '\n');
    cout << "Enter session 1 day (mon, tue, wed, thu, fri, sat): ";
    string day;
    while (!getline(cin, day) || !validDay(day)) {
        cin.clear();
        cout << "Invalid input. Please type again(mon, tue, wed, thu, fri, sat): ";
    }
    Day d = parseDay(day);

    cout << "Enter session 1 time (s1, s2, s3, s4): ";
    string time;
    while (!getline(cin, time) || !validTime(time)) {
        cin.clear();
        cout << "Invalid input. Please type again(s1, s2, s3, s4): ";
    }
    Time t = parseTime(time);
    course->session1.day = d;
    course->session1.time = t;

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
    course->session2.day = d;
    course->session2.time = t;
}

void updateCourse(Course *crs) {
    string str_inp;
    int int_inp;
    
    cout << "Enter new ID (leave empty to skip)." << endl;
    cout << "new id> ";
    cin.ignore(100, '\n');
    while (!getline(cin, str_inp)) {
        cin.ignore(100, '\n');
        cout << "Invalid input. Type again." << endl;
        cout << "new id> ";
    }
    if (!str_inp.empty()) {
        crs->id = str_inp;
    }

    cout << "Enter new name (leave empty to skip)." << endl;
    cout << "new name> ";
    while (!getline(cin, str_inp)) {
        cout << "Invalid input. Type again." << endl;
        cout << "new name> ";
    }
    if (!str_inp.empty()) {
        crs->name = str_inp;
    }

    cout << "Enter new teacher (leave empty to skip): ";
    cout << "new teacher> ";
    while (!getline(cin, str_inp)) {
        cout << "Invalid input. Type again." << endl;
        cout << "new teacher> ";
    }
    if (!str_inp.empty()) {
        crs->teacherName = str_inp;
    }

    cout << "Enter new number of credits: ";
    cout << "credits> ";
    while (!(cin >> int_inp)) {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Invalid input. Type again." << endl;
        cout << "credits> ";
    }
    crs->credits = int_inp;

    cout << "Enter new max number of students: ";
    while (!(cin >> int_inp)) {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Invalid input. Type again." << endl;
        cout << "max students> ";
    }
    crs->maxStudents = int_inp;
    updateSessions(crs);
}

void App::promptUpdateCourse() {
    promptViewCoursesList();
    int sel;
    cout << "Select course to update." << endl;
    cout << "select> ";
    while (!(cin >> sel) || sel < 1 || sel > currentSemester->courses.getSize()) {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Invalid input. Type again." << endl;
        cout << "select> ";
    }

    updateCourse(currentSemester->courses[sel-1]->data);
}

void App::promptDeleteCourse() {
    promptViewCoursesList();
    int sel;
    cout << "Select course to update." << endl;
    cout << "select> ";
    while (!(cin >> sel) || sel < 1 || sel > currentSemester->courses.getSize()) {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Invalid input. Type again." << endl;
        cout << "select> ";
    }

    currentSemester->courses.deleteAtIndex(sel-1);
}
