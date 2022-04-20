#include <iostream>
#include "App.h"
using namespace std;

void App::run() {
    promptImportCourseScoreboard();
    viewScoreboard();
}

int main() {
    App app;
    app.run();
}
