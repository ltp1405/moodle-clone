#include "../../School/Course.h"
#include "../App.h"
#include "../Menu.hpp"
#include <iostream>
#include <stdexcept>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::getline;

void change_id(Course *crs) {
    string str_inp;
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
}

void change_name(Course *crs) {
    string str_inp;
    cout << "Enter new name (leave empty to skip)." << endl;
    cout << "new name> ";
    while (!getline(cin, str_inp)) {
        cout << "Invalid input. Type again." << endl;
        cout << "new name> ";
    }
    if (!str_inp.empty()) {
        crs->name = str_inp;
    }

}

void change_teacher(Course *crs) {
    string str_inp;
    cout << "Enter new teacher (leave empty to skip)." << endl;
    cout << "new teacher> ";
    while (!getline(cin, str_inp)) {
        cout << "Invalid input. Type again." << endl;
        cout << "new teacher> ";
    }
    if (!str_inp.empty()) {
        crs->teacherName = str_inp;
    }
}

void change_credits(Course *crs) {
    string inp;
    cout << "Enter new number of credits." << endl;
    cout << "credits> ";
    getline(cin, inp);
    if (inp == "")
        return;
    int i;
    try {
        i = std::stoi(inp);
    } catch (std::invalid_argument) {
        cout << "Invalid input. Credits not changed." << endl;
        return;
    }
    crs->credits = i;
}

void change_max_students(Course *crs) {
    string inp;
    cout << "Enter new max number of students." << endl;
    cout << "max students> ";
    getline(cin, inp);
    if (inp == "")
        return;
    int i;
    try {
        i = std::stoi(inp);
    } catch (std::invalid_argument) {
        cout << "Invalid input. Credits not changed." << endl;
        return;
    }
    crs->maxStudents = i;
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

    change_id(crs);
    cout << endl;
    change_name(crs);
    cout << endl;
    change_teacher(crs);
    cout << endl;
    change_credits(crs);
    cout << endl;
    change_max_students(crs);
    NMenu menu;
    cout << "Do you want to update session?" << endl;
    menu.addItem("Yes");
    menu.addItem("No");
    int inp = menu.run();
    if (inp == 1)
        updateSessions(crs);
    else
        cin.ignore(100, '\n');
    return;
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
    cout << "Course updated. Press any key to continue..." << endl;
    cin.get();
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
    cout << "Course deleted. Press any key to continue..." << endl;
    cin.get();
}
