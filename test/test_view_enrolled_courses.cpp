#include "App.h"
#include <exception>

void App::run() {
    Semester sm;
    Course c1;
    c1.id = "cs162";
    Course c2;
    c2.id = "mth252";
    Student st1;
    st1.id = "21125098";
    Student st2;
    st2.id = "21125100";
    // c1.students.addTail(Student());
    // c1.students.getTail()->data.id = "21125098";
    sm.addCourse(Course());
    sm.courses.getTail()->data.id = "cs162";
    sm.courses.getTail()->data.students.addTail(Student());
    sm.courses.getTail()->data.students.getTail()->data.id = "21125098";
    sm.courses.getTail()->data.students.addTail(Student());
    sm.courses.getTail()->data.students.getTail()->data.id = "21125100";

    sm.addCourse(Course());
    sm.courses.getTail()->data.id = "mth252";
    sm.courses.getTail()->data.students.addTail(Student());
    sm.courses.getTail()->data.students.getTail()->data.id = "21125098";
    sm.courses.getTail()->data.students.addTail(Student());
    sm.courses.getTail()->data.students.getTail()->data.id = "21125100";

    currentSemester = &sm;
    currentStudent = &st1;
    studentViewEnrolledCourses();
}

int main() {
    App app;
    app.run();
}
