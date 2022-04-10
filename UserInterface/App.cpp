#include "App.h"
void App::promptAddStudent() {}
void App::studentPromptViewProfile() {}
void App::studentPromptChangePassword() {}
void App::promptExportStudent() {
}

void App::promptUpdateClassScoreboard() {
}

void App::promptUpdateCourseScoreboard() {
}

void App::promptLogin() {
    Menu<App> menu(this);
    menu.addItem("Login as student", &App::promptLoginAsStudent);
    menu.addItem("Login as academic member", &App::promptLoginAsAMember);
    menu.run();
}

void App::run() {
    promptLogin();
    Menu<App> studentMenu(this);
    Menu<App> academicMemberMenu(this);

    studentMenu.addItem("View profile", &App::studentPromptViewProfile);
    studentMenu.addItem("Change password", &App::studentPromptChangePassword);
    studentMenu.addItem("View scoreboard", &App::studentPromptViewScoreboard);

    academicMemberMenu.addItem("Display current schoolyear", &App::displayCurrentSchoolyear);
    academicMemberMenu.addItem("Create new course", &App::promptCreateCourse);
    academicMemberMenu.addItem("Create new school year", &App::promptCreateSchoolYear);
    academicMemberMenu.addItem("Create semester", &App::promptCreateSemester);
    academicMemberMenu.addItem("Add student to class", &App::promptAddStudent);

    // academicMemberMenu.addItem("Add student to class", &App::promptAddStudent);
    academicMemberMenu.addItem("Open Registration Session", &App::promptOpenRegistrationSession);
    academicMemberMenu.addItem("View list of courses", &App::promptViewCoursesList);
    // academicMemberMenu.addItem("Export students", &App::promptExportStudent);
    academicMemberMenu.addItem("Import scoreboard of a course", &App::promptImportCourseScoreboard);
    academicMemberMenu.addItem("View scoreboard of a course", &App::promptViewCourseScoreboard);
    academicMemberMenu.addItem("Update scoreboard of a course", &App::promptUpdateCourseScoreboard);
    academicMemberMenu.addItem("Update scoreboard of a class", &App::promptUpdateClassScoreboard);

    if (!currentStudent)
        while (true)
            academicMemberMenu.run();
    else
        while (true)
            studentMenu.run();
}

void App::init() {
    readfile();
}

App::~App() {
    cout << "DONE" << endl;
    savefile();
    for (auto *sy = schoolyears.getHead(); sy != nullptr; sy = sy->next) {
        for (auto *sm = sy->data->semesters.getHead(); sm != nullptr; sm = sm->next) {
            for (auto *cr = sm->data->courses.getHead(); cr != nullptr; cr = cr->next) {
                delete cr->data;
            }
            delete sm->data;
        }
        delete sy->data;
    }
}

int main() {
    App *app = new App;
    app->init();
    app->run();
    delete app;
	return 0;
}
