#include "App.h"
#include "Menu.hpp"
#include "../utils/ClearScreen.h"

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
#   include <Windows.h>
#endif

void App::loadStudentList() {
    vvs file = readCSV("data/Student.csv");
    for (int i = 1; i < file.size(); i++) {
        Student *st = new Student;
        for (int j = 0; j < file[i].size(); j++) {
            if (file[0][j] == "firstname")
                st->firstname = file[i][j];
            else if (file[0][j] == "lastname")
                st->lastname = file[i][j];
            else if (file[0][j] == "id")
                st->id = file[i][j];
            else if (file[0][j] == "password")
                st->password = file[i][j];
            else if (file[0][j] == "gender") {
                int g = stod(file[i][j]);
                if (g == 1)
                    st->gender = Gender::MALE;
                else if (g == 2)
                    st->gender = Gender::FEMALE;
                else
                    st->gender = Gender::OTHER;
            } else if (file[0][j] == "day")
                st->dateOfBirth.day = stod(file[i][j]);
            else if (file[0][j] == "month")
                st->dateOfBirth.month = stod(file[i][j]);
            else if (file[0][j] == "year")
                st->dateOfBirth.year = stod(file[i][j]);
            else if (file[0][j] == "username")
                st->username = file[i][j];
        }
        studentList.addTail(st);
    }
}

void App::loadMemberList() {
    vvs file = readCSV("data/Member.csv");
    for (int i = 1; i < file.size(); i++)
        cout << file[i].size();
    for (int i = 1; i < file.size(); i++) {
        auto *mem = new AcademicMember;
        for (int j = 0; j < file[i].size(); j++) {
            if (file[0][j] == "username")
                mem->username = file[i][j];
            else if (file[0][j] == "password")
                mem->password = file[i][j];
        }
        memberList.addTail(mem);
    }
}
void App::promptAddStudent() {}
void App::studentPromptViewProfile() {}
void App::studentPromptChangePassword() {}
void App::promptExportStudent() {
}

void App::promptUpdateClassScoreboard() {
}

void App::promptUpdateCourseScoreboard() {
}

void App::viewAllStudent() {
    displayAllStudent(studentList);
}
void App::promptLogin() {
    Menu<App> menu(this);
    menu.addItem("Login as student", &App::promptLoginAsStudent);
    menu.addItem("Login as academic member", &App::promptLoginAsAMember);
    menu.run();
}

void App::logout() {
    currentStudent = nullptr;
    currentMember = nullptr;
}
void App::profileGroup() {}
void App::scoreboardGroup() {
    Menu<App> menu(this);

    menu.addItem("Import scoreboard of a course", &App::promptImportCourseScoreboard);
    menu.addItem("View scoreboard of a course", &App::promptViewCourseScoreboard);
    menu.addItem("Update scoreboard of a course", &App::promptUpdateCourseScoreboard);
    menu.addItem("Update scoreboard of a class", &App::promptUpdateClassScoreboard);
    while (true) {
        if (menu.run() == 0) {
            savefile();
            return;
        }
    }
}

void App::semesterGroup() {
    Menu<App> menu(this);
    menu.addItem("Add semester", &App::promptCreateSemester);
    menu.addItem("Open Registration Session", &App::promptOpenRegistrationSession);
    while (true) {
        if (menu.run() == 0) {
            savefile();
            return;
        }
    }
}

void App::schoolyearGroup() {
    Menu<App> menu(this);
    menu.addItem("Display current schoolyear", &App::displayCurrentSchoolyear);
    menu.addItem("Display all schoolyears", &App::displayAllSchoolYears);
    menu.addItem("Add school year", &App::promptCreateSchoolYear);
    while (true) {
        if (menu.run() == 0) {
            savefile();
            return;
        }
    }
}

void App::studentGroup() {
    Menu<App> menu(this);
    menu.addItem("View Student List", &App::viewAllStudent);
    menu.addItem("Add student to class", &App::promptAddStudent);
    // academicMemberMenu.addItem("Create new class", &App::promptCreateClass);
    // academicMemberMenu.addItem("Add student to class", &App::promptAddStudent);
    // academicMemberMenu.addItem("Export students", &App::promptExportStudent);
    while (true) {
        if (menu.run() == 0) {
            savefile();
            return;
        }
    }
}

void App::courseGroup() {
    Menu<App> menu(this);
    menu.addItem("Create new course", &App::promptCreateCourse);
    menu.addItem("View list of courses", &App::promptViewCoursesList);
    while (true) {
        if (menu.run() == 0) {
            savefile();
            return;
        }
    }
}

void App::run() {
    promptLogin();
    Menu<App> studentMenu(this);
    Menu<App> academicMemberMenu(this);

    studentMenu.addItem("View profile", &App::studentPromptViewProfile);
    studentMenu.addItem("Change password", &App::studentPromptChangePassword);
    studentMenu.addItem("View scoreboard", &App::studentPromptViewScoreboard);
    studentMenu.addItem("Logout", &App::logout);

    academicMemberMenu.addItem("School Year", &App::schoolyearGroup);
    academicMemberMenu.addItem("Semester", &App::semesterGroup);
    academicMemberMenu.addItem("Course", &App::courseGroup);
    academicMemberMenu.addItem("Student", &App::studentGroup);
    academicMemberMenu.addItem("Scoreboard", &App::scoreboardGroup);
    academicMemberMenu.addItem("Logout", &App::logout);
    while (currentStudent || currentMember) {
        clearScreen();
        if (!currentStudent) {
            if (academicMemberMenu.run() == 0){
                savefile();
                return;
            }
        } else if (!currentMember) {
            if (studentMenu.run() == 0){
                savefile();
                return;
            }
        }
        if (!currentMember && !currentStudent) {
            promptLogin();
        }
    }
}

void App::init() {
    loadMemberList();
    loadStudentList();
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
    for (auto *st = schoolyears.getHead(); st != nullptr; st = st->next) {
        delete st->data;
    }
}

int main() {

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
    SetConsoleOutputCP(CP_UTF8);
#endif

    App *app = new App;
    app->init();
    app->run();
	return 0;
}
