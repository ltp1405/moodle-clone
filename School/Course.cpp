#include "Course.h"

RegistrationSession::RegistrationSession() : start(Date(0, 0, 0)), end(Date(0, 0, 0)) {
    activated = false;
}

Course::Course(string courseId, string courseName, int numberOfCredits, int maxStudents, string teacher)
    : id(courseId)
    , name(courseName)
    , credits(numberOfCredits)
    , maxStudents(maxStudents)
    , teacherName(teacher) {
    regSession = RegistrationSession();
}

