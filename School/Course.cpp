#include "Course.h"

Course::Course(string courseId, string courseName, int numberOfCredits, int maxStudents, string teacher)
    : id(courseId)
    , name(courseName)
    , credits(numberOfCredits)
    , maxStudents(maxStudents)
    , teacherName(teacher) {
    regSession = RegistrationSession();
}

