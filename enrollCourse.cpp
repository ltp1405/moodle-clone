#include "School/Course.h"
#include "Personnel/Student.h"
#include "utils/LinkedList.h"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

void addStudentToCourse(Course &crs, const Student &st) {
    crs.students.addHead(st);
}

void enrollCourse(LinkedList<Course> ls, const Student &st) {
    bool cont = true;
    while (cont) {
        cout << "These are course available: " << endl;
        ls.printList(&Course::print);
        cout << "Choose which course to enroll, type 0 to exit." << endl;
        int choice;
        cin >> choice;
        if (choice == 0) {
            break;
        }
        DNode<Course> *chosen = ls.getNodeAtIndex(choice-1);
        addStudentToCourse(chosen->data, st);
    }
}

int main() {
    Student st;
    st.firstname = "Tung";
    Course c = Course();
}
