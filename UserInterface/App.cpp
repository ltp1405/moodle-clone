#include "App.h"
void App::promptExportStudent() {
}

void App::promptImportCourseScoreboard() {
}

void App::promptUpdateClassScoreboard() {
}

void App::promptUpdateCourseScoreboard() {
}

void App::promptViewCourseScoreboard() {
}

void App::promptViewCoursesList() {
}

void App::promptLoginAsStudent() {
    cout << "Login in";
}

void App::promptLoginAsAMember() {
    cout << "Login in";
}

void App::promptLogin() {
    Menu<App> menu(this);
    menu.addItem("Login as student", &App::promptLoginAsStudent);
    menu.addItem("Login as academic member", &App::promptLoginAsAMember);
    menu.run();
}

void App::promptCreateCourse() {
    cout << "Create course" << endl;
}

void App::promptCreateSchoolYear() {
    cout << "Create school year" << endl;
}

void App::promptAddStudent() {
    cout << "Add student" << endl;
}

void App::promptCreateSemester() {
    cout << "Create semester" << endl;
}

void App::promptViewScoreboard() {
    cout << "View scoreboard" << endl;
}

void App::promptOpenRegistrationSession() {
    cout << "Open registration session" << endl;
}

void App::studentPromptViewProfile() {
    cout << "View profile" << endl;
}

void App::studentPromptChangePassword() {
    cout << "Change password" << endl;
}

void App::studentPromptViewScoreboard() {
    cout << "View scoreboard" << endl;
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
