#include "../App.h"
#include <iostream>
#include <string>
#include "../../School/Course.h"
#include "../../School/Semester.h"
using std::string;
using std::cout;
using std::cin;

void App::promptCreateCourse() {
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
}
