#include "Menu.h"
#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::string;

string getInput();
void run();
void init();
bool process(string input);
void displayUsage();

int main() {
    Menu studentMenu;
    Menu academicMemberMenu;

    studentMenu.addItem("View profile");
    studentMenu.addItem("Change password");
    studentMenu.addItem("View scoreboard");

    academicMemberMenu.addItem("Create new course");
    academicMemberMenu.addItem("Create new school year");
    academicMemberMenu.addItem("Add student to class");
    academicMemberMenu.addItem("Create semester");
    academicMemberMenu.addItem("Open Registration Session");
    academicMemberMenu.addItem("View list of courses");
    academicMemberMenu.addItem("Export students");
    academicMemberMenu.addItem("Import scoreboard of a course");
    academicMemberMenu.addItem("View scoreboard of a course");
    academicMemberMenu.addItem("Update scoreboard of a course");
    academicMemberMenu.addItem("Update scoreboard of a class");

    cout << academicMemberMenu.getInput();
	return 0;
}

void promptCreateCourse() {
}

void promptCreateSchoolYear() {
}

void promptAddStudent() {
}

void promptCreateSemester() {
}

void promptViewScoreboard() {
}

void promptOpenRegistrationSession() {
}

void studentPromptViewProfile() {
}

void studentPromptChangePassword() {
}

void studentPromptViewScoreboard() {
}
