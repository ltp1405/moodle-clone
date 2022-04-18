#include "../../School/Course.h"
#include "../../Personnel/Student.h"
#include "../../utils/LinkedList.h"
#include "../../utils/ClearScreen.h"
#include "../App.h"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

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
        DNode<Session*> *ss = cr->data->sessions.getHead();
        for (;ss != nullptr; ss = ss->next) {
            DNode<Session*> *ss2 = crs->sessions.getHead();
            for (;ss2 != nullptr; ss2 = ss2->next) {
                if (ss->data->toString() == ss2->data->toString()) {
                    cout << "[ERROR] Session occupied. Not enrollable." << endl;
                    return false;
                }
            }
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
            cout << cur->data->id << " [ " << cur->data->sessions.getHead()->data->toString() << " ] " << endl;
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
    else
        cout << "Nullptr";
}
