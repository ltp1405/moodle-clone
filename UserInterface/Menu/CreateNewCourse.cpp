#include "../App.h"
#include <iostream>
#include <string>
#include "../../School/Course.h"
#include "../../School/Semester.h"
using std::string;
using std::cout;
using std::cin;

void App::promptCreateCourse() {
    clearScreen();
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
    currentSemester->courses.getTail()->data->addSession(Session(d, t), 1);

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
    currentSemester->courses.getTail()->data->addSession(Session(d, t), 2);
    cout << "Course added. Press any key to continue..." << endl;
    cin.get();
}
