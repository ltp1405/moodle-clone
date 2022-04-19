#include <iostream>
#include <string>
#include "../../School/Semester.h"
#include "../../School/SchoolYear.h"
#include "../../School/Course.h"
#include "../../utils/LinkedList.h"
#include "../../utils/ClearScreen.h"
#include "../App.h"
#include "../Table.hpp"

void App::promptViewCoursesList() {
    clearScreen();
    Table tb("List of Course");
    tb.addColumn("ID");
    tb.addColumn("Name");
    tb.addColumn(Column("Sessions", 20));
    tb.addColumn("No of Credits");
    tb.addColumn("No of Student");
    tb.addColumn("Teacher Name");
    tb.addColumn("Max Student");

    DNode<Course*> *cur = currentSemester->courses.getHead();
    while (cur) {
        tb.addRow(
                cur->data->id,
                cur->data->name,
                cur->data->session1.toString() + " " + cur->data->session2.toString(),
                std::to_string(cur->data->credits),
                std::to_string(cur->data->students.getSize()),
                cur->data->teacherName,
                std::to_string(cur->data->maxStudents)
                );

        cur = cur->next;
    }

    tb.display();
    cout << "Press any key to continue..." << endl;
    cin.ignore(100, '\n');
    cin.get();
}

void App::promptViewStudentOfCourse() {
    string inp;
    cout << "Enter course ID: ";
    cin.ignore(100, '\n');
    std::getline(cin, inp);
    DNode<Course*> *crs = currentSemester->courses.getHead();
    Course *chosen = nullptr;
    while (crs) {
        if (crs->data->id == inp) {
            chosen = crs->data;
            break;
        }
        crs = crs->next;
    }
    if (!chosen) {
        cout << "Course not found." << endl;
        return;
    }

    Table tb("Student List");
    tb.addColumn(Column("ID", 8, Alignment::right));
    tb.addColumn(Column("Firstname", 15, Alignment::left));
    tb.addColumn(Column("Lastname", 15, Alignment::left));
    tb.addColumn(Column("Gender", 7, Alignment::right));
    tb.addColumn(Column("Dob", 12, Alignment::center));
    tb.addColumn(Column("Social ID"));
    for (DNode<Student*> *cur = chosen->students.getHead(); cur != nullptr; cur = cur->next) {
        Student* st = cur->data;
        string gender_name;
        if (st->gender == Gender::MALE) {
            gender_name = "Male";
        } else if (st->gender == Gender::FEMALE) {
            gender_name = "Female";
        } else {
            gender_name = "Other";
        }
        tb.addRow(st->id,
                st->firstname,
                st->lastname,
                gender_name,
                st->dateOfBirth.toString(),
                st->SocialID);
    }
    tb.display();
    cout << "Press any key to continue..." << endl;
    cin.ignore(100, '\n');
    cin.get();
}
