#include "App.h"
#include "Menu/OpenRegistrationSession.h"
#include <fstream>

void App::promptCreateCourse() {}
void App::promptAddStudent() {}
void App::studentPromptViewProfile() {}
void App::studentPromptChangePassword() {}
void App::promptExportStudent() {
}

void App::promptUpdateClassScoreboard() {
}

void App::promptUpdateCourseScoreboard() {
}

void App::promptViewCoursesList() {
}

void App::promptLogin() {
    Menu<App> menu(this);
    menu.addItem("Login as student", &App::promptLoginAsStudent);
    menu.addItem("Login as academic member", &App::promptLoginAsAMember);
    menu.run();
}

void App::init() {
    std::ifstream fin("../data/RegistrationTime.txt");
    string str;
    getline(fin, str, '\n');
    regSession.start = getDateTimefromString(str);
    getline(fin, str, '\n');
    regSession.end = getDateTimefromString(str);
    fin.close();
}

void App::run() {
    promptLogin();
    Menu<App> studentMenu(this);
    Menu<App> academicMemberMenu(this);

    studentMenu.addItem("View profile", &App::studentPromptViewProfile);
    studentMenu.addItem("Change password", &App::studentPromptChangePassword);
    studentMenu.addItem("View scoreboard", &App::studentPromptViewScoreboard);

    academicMemberMenu.addItem("Create new course", &App::promptCreateCourse);
    academicMemberMenu.addItem("Create new school year", &App::promptCreateSchoolYear);
    academicMemberMenu.addItem("Add student to class", &App::promptAddStudent);
    academicMemberMenu.addItem("Create semester", &App::promptCreateSemester);
    academicMemberMenu.addItem("Open Registration Session", &App::promptOpenRegistrationSession);
    academicMemberMenu.addItem("View list of courses", &App::promptViewCoursesList);
    academicMemberMenu.addItem("Export students", &App::promptExportStudent);
    academicMemberMenu.addItem("Import scoreboard of a course", &App::promptImportCourseScoreboard);
    academicMemberMenu.addItem("View scoreboard of a course", &App::promptViewCourseScoreboard);
    academicMemberMenu.addItem("Update scoreboard of a course", &App::promptUpdateCourseScoreboard);
    academicMemberMenu.addItem("Update scoreboard of a class", &App::promptUpdateClassScoreboard);
    academicMemberMenu.run();
}

int main() {
    App *app = new App;
    app->init();
    app->run();
	return 0;
}
