#pragma once
#include "../School/Session.h"
#include "../utils/Date.h"
#include "../utils/LinkedList.h"
#include <string>
using std::string;

struct RegistrationSession {
    bool activated;
    Date start;
    Date end;

    RegistrationSession();
};

struct Course {
    const string id;
    const string name;
    string teacherName;
    const int credits;
    const int maxStudents;
    LinkedList<Session> sessions;
    RegistrationSession regSession;

    Course(string courseId, string courseName, int numberOfCredits,
           int maxStudents, string teacher);

    void addTeacherName(string name);
    void startRegistrationSession();
    void addSession(Session session);
};
