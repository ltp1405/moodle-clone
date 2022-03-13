#pragma once
#include "../School/Session.h"
#include "../utils/Date.h"
#include <string>
using std::string;

struct CourseRegistrationSession {
    bool activated;
    Date start;
    Date end;
};

struct Course {
    const string id;
    const string name;
    string teacherName;
    const int credits;
    const int maxStudents;
    Session *sessions;
    const int sessionNumbers = 2;

    Course(string courseId, string courseName, int numberOfCredits,
           int maxStudents, string teacher);

    void addTeacherName(string name);
    void startRegistrationSession();
    void addSession(Session session);
};
