#include "App.h"
#include "Table.hpp"
#include "../utils/LinkedList.h"

void App::studentViewEnrolledCourses() {
    if (!currentStudent)
        return;
    Table tb("Enrolled Courses");
    tb.addColumn(Column("ID"));
    tb.addColumn(Column("Name"));
    tb.addColumn(Column("Sessions", 20));
    tb.addColumn(Column("Teacher Name"));
    tb.addColumn(Column("Credits"));
    tb.addColumn(Column("Max Student"));

    DNode<Course> *cur = currentSemester->courses.getHead();
    while (cur) {
        DNode<Student> *curStudent = cur->data.students.getHead();
        while (curStudent) {
            if (curStudent->data.id == currentStudent->id) {
                DNode<Session> *ss = cur->data.sessions.getHead();
                string sessionString;
                while (ss) {
                    sessionString += ss->data.toString();
                    if (ss != cur->data.sessions.getTail()) {
                        sessionString += ", ";
                    }
                    ss = ss->next;
                }
                tb.addRow(
                        cur->data.id,
                        cur->data.name,
                        sessionString,
                        cur->data.teacherName,
                        cur->data.credits,
                        cur->data.maxStudents
                        );
                break;
            }
            curStudent = curStudent->next;
        }
        cur = cur->next;
    }
    tb.display();
}