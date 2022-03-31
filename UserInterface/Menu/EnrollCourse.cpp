#include "../../School/Course.h"
#include "../../Personnel/Student.h"
#include "../../utils/LinkedList.h"
#include "../App.h"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

void addStudentToCourse(Course &crs, Student &st) {
    crs.students.addHead(st);
}

bool enrolled(Course &crs, const Student &st) {
    DNode<Student>*cur = crs.students.getHead();
    while (cur) {
        if (cur->data.firstname == st.firstname)
            return true;
        cur = cur->next;
    }
    return false;
}

void enrollCourse(LinkedList<Course> &ls, Student &st) {
    bool cont = true;
    DNode<Course> *curHead = ls.getHead();
    while (cont) {
        cout << "These are course available: " << endl;
        DNode<Course> *cur = curHead;
        if (!cur)
            return;
        while (cur) {
            bool erl = enrolled(cur->data, st);
            if (erl)
                cout << "\x1b[9m";
            cur->data.print();
            if (erl)
                cout << "\x1b[0m";
            cur = cur->next;
        }
        cout << "Choose which course to enroll, type 0 to exit." << endl;
        cout << "[choice]> ";
        int choice;
        cin >> choice;
        if (choice == 0) {
            return;
        }
        DNode<Course> *chosen = ls.getNodeAtIndex(choice-1);
        addStudentToCourse(chosen->data, st);
    }
}

void App::studentPromptEnrollCourse() {
    if (currentStudent)
        enrollCourse(currentSemester->courses, *currentStudent);
    else
        cout << "Nullptr";
}
