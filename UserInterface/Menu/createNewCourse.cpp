#include "../App.h"
#include <iostream>
#include <string>
#include "../../School/Course.h"
#include "../../School/Semester.h"
using std::string;
using std::cout;
using std::cin;

void promptAddCourseToSemester(Semester &sm) {
    string id;
    string name;
    string teacherName;
    int credits;
    int maxStudents;

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

    Course crs = Course(id, name, credits, maxStudents, teacherName);
    sm.addCourse(crs);
}

void App::promptCreateCourse() {
    Menu<App> chooseSemesterMenu(this);
}
