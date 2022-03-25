#pragma once
#include "../School/Session.h"
#include "../utils/Date.h"
#include "../utils/LinkedList.h"
#include "../Personnel/Student.h"
#include <string>
using std::string;

struct Course {
    string id;
    string name;
    string teacherName;
    int credits;
    int maxStudents;
    LinkedList<Session> sessions;
    LinkedList<Student> students;

    Course();
    Course(string courseId, string courseName, int numberOfCredits,
           int maxStudents, string teacher);

    void addSession(Session session);
    void print();
};
