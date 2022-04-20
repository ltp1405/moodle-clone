#include "App.h"
#include "../School/Semester.h"
#include "../School/Course.h"

void App::run() {
    Semester sm;
    Course c1;
    c1.id = "cs162";
    Course c2;
    c2.id = "mth252";
    sm.addCourse(c1);
    sm.addCourse(c2);
    promptImportCourseScoreboard();

    currentSemester = &sm;
    promptViewCourseScoreboard();
}

int main() {
    App app;
    app.run();
}
