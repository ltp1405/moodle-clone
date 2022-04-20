#include "../../School/Course.h"
#include "../../Personnel/Student.h"
#include "../../utils/LinkedList.h"
#include "../../utils/ClearScreen.h"
#include "../Menu.hpp"
#include "../Table.hpp"
#include "../App.h"
#include <cstdio>
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

void displayCourses(LinkedList<Course*> &courses) {
    Table tb("Enrolled Courses");
    tb.addColumn(Column("ID"));
    tb.addColumn(Column("Name"));
    tb.addColumn(Column("Sessions", 20));
    tb.addColumn(Column("Teacher Name"));
    tb.addColumn(Column("Credits"));
    tb.addColumn(Column("Max Student"));

    DNode<Course*> *cur = courses.getHead();
    while (cur) {
        tb.addRow(
                cur->data->id,
                cur->data->name,
                cur->data->session1.toString() + " " + cur->data->session2.toString(),
                cur->data->teacherName,
                cur->data->credits,
                cur->data->maxStudents
        );
        cur = cur->next;
    }
    tb.display();
}

void App::studentViewEnrolledCourses() {
    clearScreen();
    if (!currentStudent)
        return;
    displayCourses(currentStudent->courses);
    cout << "Press any key to continue..." << endl;
    cin.ignore(100, '\n');
    cin.get();
}

void addStudentToCourse(Course *crs, Student *st) {
    crs->students.addHead(st);
    st->courses.addTail(crs);
}

bool enrolled(Course *crs, Student *st) {
    DNode<Course *> *cur = st->courses.getHead();
    while (cur) {
        if (cur->data->id == crs->id)
            return true;
        cur = cur->next;
    }
    return false;
}

bool enrollable(Course *crs, Student *student) {
    if (student->courses.getSize() >= 5) {
        cout << "You can only enroll at most 5 courses." << endl;
        cout << "If you still want to enroll this course, " << endl;
        cout << "Consider unenroll other courses." << endl;
        return false;
    }
    DNode<Course*> *cr = student->courses.getHead();
    for (; cr != nullptr; cr = cr->next) {

        if (cr->data->session1.toString() == crs->session1.toString()
                || cr->data->session1.toString() == crs->session2.toString()
                || cr->data->session2.toString() == crs->session1.toString()
                || cr->data->session2.toString() == crs->session2.toString()) {
            cout << "[ERROR] Session occupied. Not enrollable." << endl;
            return false;
        }
    }
    return true;
}

void enrollCourse(LinkedList<Course *> &ls, Student *st) {
    bool cont = true;
    DNode<Course*> *curHead = ls.getHead();
    while (cont) {
        cout << "These are course available: " << endl;
        DNode<Course*> *cur = curHead;
        if (!cur)
            return;
        while (cur) {
            bool erl = enrolled(cur->data, st);
            if (erl)
                cout << "\x1b[9m";
            cout << cur->data->id << " [ " << cur->data->session1.toString() << " ] " << ", ";
            cout << cur->data->id << " [ " << cur->data->session2.toString() << " ] " << endl;
            if (erl)
                cout << "\x1b[0m";
            cur = cur->next;
        }
        cout << "Choose which course to enroll, type 0 to exit." << endl;
        cout << "[choice]> ";
        int choice;
        while (!(cin >> choice)) {
            cin.clear();
            cin.ignore(100, '\n');
            cout << "Not a choice. Please choose again." << endl;
            cout << "[choice]> ";
        }
        clearScreen();
        if (choice == 0) {
            return;
        }
        DNode<Course*> *chosen = ls.getNodeAtIndex(choice-1);
        if (!enrollable(chosen->data, st)) {
            continue;
        }
        addStudentToCourse(chosen->data, st);
    }
}

void App::studentPromptEnrollCourse() {
    if (currentStudent)
        enrollCourse(currentSemester->courses, currentStudent);
    cout << "Course enrolled. Press any key to continue..." << endl;
    cin.get();
}

bool studentCompare(Student *&st1, Student *&st2) {
    return st1->id == st2->id;
}

void App::studentPromptUnenrollCourse() {
    clearScreen();
    if (!currentStudent)
        return;
    displayCourses(currentStudent->courses);
    NMenu menu;
    DNode<Course*> *cur = currentStudent->courses.getHead();
    while (cur) {
        menu.addItem(cur->data->id + " - " + cur->data->name);
        cur = cur->next;
    }
    int inp = menu.run();
    Course *crs = currentStudent->courses.getNodeAtIndex(inp-1)->data;
    currentStudent->courses.deleteAtIndex(inp-1);
    int count = 0;
    for (DNode<Student*> *cur = crs->students.getHead(); cur; cur = cur->next) {
        if (cur->data->id == currentStudent->id) {
            break;
        }
        count++;
    }
    crs->students.deleteAtIndex(count);
}
