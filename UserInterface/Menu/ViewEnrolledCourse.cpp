#include "../App.h"
#include "../../utils/LinkedList.h"
#include "../Table.hpp"

void App::studentViewEnrolledCourses() {
    if (!currentStudent) {
        cout << "Failed to load student info. Please login again." << endl;
        return;
    }

    DNode<Course*> *cur = currentStudent->courses.getHead();
    Table tb("Enrolled Course");
    while (cur) {
    }
    tb.addColumn("ID");
    tb.addColumn("Name");
    tb.addColumn(Column("Sessions", 20));
    tb.addColumn(Column("Credits", 7));
    tb.addColumn("Students");
    tb.addColumn("Teacher");
    tb.addColumn("Max Students");

    while (cur) {
        string s;
        DNode<Session*> *ss = cur->data->sessions.getHead();
        while (ss) {
            s += ss->data->toString();
            if (ss != cur->data->sessions.getTail()) {
                s += ", ";
            }
            ss = ss->next;
        }
        tb.addRow(
                cur->data->id,
                cur->data->name,
                s,
                std::to_string(cur->data->credits),
                std::to_string(cur->data->students.getSize()),
                cur->data->teacherName,
                std::to_string(cur->data->maxStudents)
                );

        cur = cur->next;
    }

    tb.display();
}
