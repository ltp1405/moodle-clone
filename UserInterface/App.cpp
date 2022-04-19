#include "App.h"
#include "Menu.hpp"
#include "../utils/ClearScreen.h"
#include "Greeting.h"

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
#   include <Windows.h>
#endif
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
    loginGreeting();
    menu.run();
}

void App::logout() {
    currentStudent = nullptr;
    currentMember = nullptr;
    clearScreen();
}
void App::profileGroup() {}
void App::scoreboardGroup() {
    Menu<App> menu(this);

    menu.addItem("Import scoreboard of a course", &App::promptImportCourseScoreboard);
    menu.addItem("View scoreboard of a course", &App::promptViewCourseScoreboard);
    menu.addItem("Update scoreboard of a course", &App::promptUpdateCourseScoreboard);
    menu.addItem("Update scoreboard of a class", &App::promptUpdateClassScoreboard);
    scoreboardGreeting();
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
    semesterGreeting();
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
    schoolyearGreeting();
    while (true) {
        if (menu.run() == 0) {
            savefile();
            return;
        }
    }
}

void App::studentGroup() {
    Menu<App> menu(this);
    menu.addItem("Add new class", &App::promptAddClass);
    menu.addItem("Add student to class", &App::promptAddStudent);
    menu.addItem("Import student to class", &App::promptImportStudent);
    menu.addItem("View Student List", &App::viewAllStudent);
    menu.addItem("View list of classes", &App::viewListOfClasses);
    menu.addItem("View class", &App::viewClass);
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
    menu.addItem("View course students", &App::promptViewStudentOfCourse);
    menu.addItem("Export student of course", &App::promptExportStudent);
    menu.addItem("Update course", &App::promptUpdateCourse);
    menu.addItem("Delete course", &App::promptDeleteCourse);
    courseGreeting();
    while (true) {
        if (menu.run() == 0) {
            savefile();
            return;
        }
    }
}

void App::run() {
    promptLogin();
    Menu<App> academicMemberMenu(this);

    academicMemberMenu.addItem("School Year", &App::schoolyearGroup);
    academicMemberMenu.addItem("Semester", &App::semesterGroup);
    academicMemberMenu.addItem("Course", &App::courseGroup);
    academicMemberMenu.addItem("Student", &App::studentGroup);
    academicMemberMenu.addItem("Scoreboard", &App::scoreboardGroup);
    academicMemberMenu.addItem("Logout", &App::logout);
    while (currentStudent || currentMember) {
        clearScreen();
        welcomeGreeting();
        if (!currentStudent) {
            if (academicMemberMenu.run() == 0){
                savefile();
                saveMemberList();
                saveStudentList();
                return;
            }
        } else {
            Menu<App> studentMenu(this);
            studentMenu.addItem("View profile", &App::studentPromptViewProfile);
            studentMenu.addItem("Change password", &App::studentPromptChangePassword);
            studentMenu.addItem("View scoreboard", &App::studentPromptViewScoreboard);
            studentMenu.addItem("View enrolled courses", &App::studentViewEnrolledCourses);
            if (currentSemester->registratable()) {
                studentMenu.addItem("Enroll course", &App::studentPromptEnrollCourse);
                studentMenu.addItem("Unenroll course", &App::studentPromptUnenrollCourse);
            }
            studentMenu.addItem("Logout", &App::logout);

            if (studentMenu.run() == 0){
                savefile();
                saveMemberList();
                saveStudentList();
                return;
            }
        }
        if (!currentMember && !currentStudent) {
            promptLogin();
        }
    }
}

void App::loadClasses() {
    importClassTXT(classes);
}

void App::loadRegSession() {
    std::ifstream fin("data/RegistrationSession.txt");
    if (!fin || !currentSchoolyear || !currentSemester)
        return;
    fin >> currentSemester->rgs.from.day 
        >> currentSemester->rgs.from.month 
        >> currentSemester->rgs.from.year
        >> currentSemester->rgs.to.day
        >> currentSemester->rgs.to.month
        >> currentSemester->rgs.to.year;
    fin.close();
}

void App::init() {
    loadClasses();
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
