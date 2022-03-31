#include "../School/Course.h"
#include "Menu.hpp"
#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::endl;

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

void updateCourse(Course &crs) {
    Menu<Course> menu(&crs);
    menu.addItem("Id", &promptChangeId);
    menu.addItem("Course Name", &promptChangeName);
    menu.addItem("Teacher", &promptChangeTeacher);

    menu.run();
}
