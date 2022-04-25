#include "App.h"
#include "Menu.hpp"
#include "../utils/ClearScreen.h"
#include "Greeting.h"
#include "../utils/makeDir.h"

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
    savefile();
    saveClass();
    saveScoreboard();
    currentStudent = nullptr;
    currentMember = nullptr;
    clearScreen();
}

void App::profileGroup() {}
void App::scoreboardGroup() {
    Menu<App> menu(this);

    menu.addItem("Import scoreboard of a course", &App::promptImportCourseScoreboard);
    menu.addItem("View scoreboard of a course", &App::promptViewCourseScoreboard);
    menu.addItem("View scoreboard of a class", &App::viewClassScoreboard);
    menu.addItem("Update scoreboard of a course", &App::promptUpdateScoreboard);
    bool run = true;
    do {
        clearScreen();
        scoreboardGreeting();
        int rs = menu.run();
        if (rs == 0)
            run = false;
    } while (run);
    savefile();
}

void App::semesterGroup() {
    Menu<App> menu(this);
    menu.addItem("Add semester", &App::promptCreateSemester);
    menu.addItem("Open Registration Session", &App::promptOpenRegistrationSession);
    bool run = true;
    do {
        clearScreen();
        semesterGreeting();
        int rs = menu.run();
        if (rs == 0)
            run = false;
    } while (run);
    savefile();
}

void App::schoolyearGroup() {
    Menu<App> menu(this);
    menu.addItem("Display current schoolyear", &App::displayCurrentSchoolyear);
    menu.addItem("Display all schoolyears", &App::displayAllSchoolYears);
    menu.addItem("Add school year", &App::promptCreateSchoolYear);
    bool run = true;
    do {
        clearScreen();
        schoolyearGreeting();
        int rs = menu.run();
        if (rs == 0)
            run = false;
    } while (run);
    savefile();
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
    bool run = true;
    do {
        clearScreen();
        studentGreeting();
        int rs = menu.run();
        if (rs == 0)
            run = false;
    } while (run);
    savefile();
}

void App::courseGroup() {
    Menu<App> menu(this);
    menu.addItem("Create new course", &App::promptCreateCourse);
    menu.addItem("View list of courses", &App::promptViewCoursesList);
    menu.addItem("View course students", &App::promptViewStudentOfCourse);
    menu.addItem("Export student of course", &App::promptExportStudent);
    menu.addItem("Update course", &App::promptUpdateCourse);
    menu.addItem("Delete course", &App::promptDeleteCourse);
    bool run = true;
    do {
        clearScreen();
        courseGreeting();
        int rs = menu.run();
        if (rs == 0)
            run = false;
    } while (run);
    savefile();
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
                saveClass();
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
                saveClass();
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
    makeDir();
    loadClasses();
    loadMemberList();
    loadStudentList();
    readScoreboard();
    readfile();
    loadRegSession();
}

App::~App() {
    cout << "DONE" << endl;
    savefile();
    saveClass();
    saveScoreboard();
    saveMemberList();
    saveStudentList();
}

int main() {

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
    SetConsoleOutputCP(CP_UTF8);
#endif

    App app;
    app.init();
    app.run();
	return 0;
}
