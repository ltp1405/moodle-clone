#include "School/Course.h"
#include "Personnel/Student.h"
#include "utils/LinkedList.h"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

void addStudentToCourse(Course &crs, const Student &st) {
    crs.students.addHead(st);
    cout << "Add " << st.firstname << " to " << crs.id << endl;
}

void enrollCourse(LinkedList<Course> &ls, const Student &st) {
    bool cont = true;
    while (cont) {
        cout << "These are course available: " << endl;
        ls.printList(&Course::print);
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

int main() {
    Student st1;
    st1.firstname = "Tung";
    Course c1 = Course();
    c1.id = "cs162";
    Course c2 = Course();
    c2.id = "mth252";
    LinkedList<Course> courses;
    courses.addHead(c1);
    courses.addHead(c2);

    Student st2;
    st2.firstname = "Han";
    enrollCourse(courses, st1);
    enrollCourse(courses, st2);
    DNode<Course> *curCourse = courses.getHead();
    while (curCourse) {
        DNode<Student> *s = curCourse->data.students.getHead();
        while (s) {
            cout << s->data.firstname << " in " << curCourse->data.id << endl;
            s = s->next;
        }
        curCourse = curCourse->next;
    }
}
