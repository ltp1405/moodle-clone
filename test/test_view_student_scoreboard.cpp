#include "App.h"
#include "../Personnel/Student.h"

void App::run() {
    Student s;
    s.id = "21125098";
    currentStudent = &s;
    promptImportCourseScoreboard();
    studentViewScoreboard();
}

int main() {
    App app;
    app.run();
}
