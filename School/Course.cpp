#include "Course.h"
#include "iostream"
using std::cout;
using std::endl;

Course::Course() {}
Course::Course(string courseId, string courseName, int numberOfCredits, int maxStudents, string teacher) {
    id = courseId;
    name = courseName;
    credits = numberOfCredits;
    this->maxStudents = maxStudents;
    teacherName = teacher;
}

void Course::addSession(Session session) {
    sessions.addTail(session);
}

void Course::print() {
    cout << "ID: " << id << endl;
    cout << "Course name: " << name << endl;
    cout << "Max number of students: " << maxStudents << endl;
    cout << "Teacher name: " << teacherName << endl;
    cout << "Credits: " << credits << endl;
}
