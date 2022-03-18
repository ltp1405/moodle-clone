#include "Menu.hpp"
#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::string;
using std::endl;

class App {
private:
    // A bunch of linked list
public:
    void load();
};

string getInput();
void run();
void init();
bool process(string input);
void displayUsage();

void promptCreateCourse(App*);
void promptCreateSchoolYear(App*);
void promptAddStudent(App*);
void promptCreateSemester(App*);
void promptViewScoreboard(App*);
void promptOpenRegistrationSession(App*);
void promptViewCoursesList(App*);
void promptExportStudent(App*);
void promptImportCourseScoreboard(App*);
void promptViewCourseScoreboard(App*);
void promptUpdateClassScoreboard(App*);
void promptUpdateCourseScoreboard(App*);
void studentPromptViewProfile(App*);
void studentPromptChangePassword(App*);
void studentPromptViewScoreboard(App*);

int main() {
    App *app = new App;
    Menu<App> studentMenu(app);
    Menu<App> academicMemberMenu(app);

    studentMenu.addItem("View profile", studentPromptViewProfile);
    studentMenu.addItem("Change password", studentPromptChangePassword);
    studentMenu.addItem("View scoreboard", studentPromptViewScoreboard);

    academicMemberMenu.addItem("Create new course", promptCreateCourse);
    academicMemberMenu.addItem("Create new school year", promptCreateSchoolYear);
    academicMemberMenu.addItem("Add student to class", promptAddStudent);
    academicMemberMenu.addItem("Create semester", promptCreateSemester);
    academicMemberMenu.addItem("Open Registration Session", promptOpenRegistrationSession);
    academicMemberMenu.addItem("View list of courses", promptViewCoursesList);
    academicMemberMenu.addItem("Export students", promptExportStudent);
    academicMemberMenu.addItem("Import scoreboard of a course", promptImportCourseScoreboard);
    academicMemberMenu.addItem("View scoreboard of a course", promptViewCourseScoreboard);
    academicMemberMenu.addItem("Update scoreboard of a course", promptUpdateCourseScoreboard);
    academicMemberMenu.addItem("Update scoreboard of a class", promptUpdateClassScoreboard);

    academicMemberMenu.run();
	return 0;
}

void promptCreateCourse(App *app) {
    cout << "Create course" << endl;
}

void promptCreateSchoolYear(App *app) {
    cout << "Create school year" << endl;
}

void promptAddStudent(App *app) {
    cout << "Add student" << endl;
}

void promptCreateSemester(App *app) {
    cout << "Create semester" << endl;
}

void promptViewScoreboard(App *app) {
    cout << "View scoreboard" << endl;
}

void promptOpenRegistrationSession(App *app) {
    cout << "Open registration session" << endl;
}

void studentPromptViewProfile(App *app) {
    cout << "View profile" << endl;
}

void studentPromptChangePassword(App *app) {
    cout << "Change password" << endl;
}

void studentPromptViewScoreboard(App *app) {
    cout << "View scoreboard" << endl;
}
