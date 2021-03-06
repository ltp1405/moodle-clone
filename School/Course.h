#pragma once
#include "../utils/Date.h"
#include "../utils/LinkedList.h"
#include "../Personnel/Student.h"
#include <string>
using std::string;

struct Student;

enum Day {
    MON,
    TUE,
    WED,
    THU,
    FRI,
    SAT,
};

// S1 (07:30), S2 (09:30), S3(13:30), S4 (15:30)
enum Time {
    S1,
    S2,
    S3,
    S4,
};

struct Session {
    Day day;
    Time time;

    Session();
    Session(Day, Time);
    string toString();
};

bool validDay(string);
bool validTime(string);
Day parseDay(string);
Time parseTime(string);

struct Course {
    string id;
    string name;
    string teacherName;
    int credits;
    int maxStudents;
    Session session1;
    Session session2;
    LinkedList<Student*> students;

    Course();
    Course(string courseId, string courseName, int numberOfCredits,
           int maxStudents, string teacher);

    void addSession(Session session, int num);
    void print();
};
