#include "../School/Semester.h"
#include "../School/Course.h"
#include "App.h"

void App::run() {
    Semester sm;
    Course c1 = Course();
    c1.id = "cs162";
    c1.name = "Introduction to Computer Science";
    Course c2 = Course();
    c2.id = "mth252";
    c2.name = "Maths";
    sm.addCourse(c1);
    sm.addCourse(c2);
    currentSemester = &sm;
    promptViewCoursesList();
}

int main() {
    App app;
    app.run();

    return 0;
}
