#include <iostream>
#include <string>
#include "../School/Semester.h"
#include "../School/SchoolYear.h"
#include "../School/Course.h"
#include "../utils/LinkedList.h"
#include "App.h"
#include "Table.hpp"
using std::cout;
using std::cin;
using std::endl;

void App::promptViewCoursesList() {
    Table tb("List of Course");
    tb.addColumn("ID");
    tb.addColumn("Name");
    tb.addColumn("No of Credits");
    tb.addColumn("No of Student");
    tb.addColumn("Teacher Name");
    tb.addColumn("Max Student");

    DNode<Course> *cur = currentSemester->courses.getHead();
    while (cur) {
        tb.addRow(vector<string> {
                cur->data.id,
                cur->data.name,
                std::to_string(cur->data.credits),
                std::to_string(cur->data.students.getSize()),
                cur->data.teacherName,
                std::to_string(cur->data.maxStudents),
                });

        cur = cur->next;
    }

    tb.display();
}
