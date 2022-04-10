#include "App.h"

void App::loadStudentList() {
    vvs file = readCSV("Student.csv");
    for (int i = 1; i < file.size(); i++)
        cout << file[i].size();
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
    vvs file = readCSV("Member.csv");
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

void App::run() {
    promptLogin();
    Menu<App> studentMenu(this);
    Menu<App> academicMemberMenu(this);

    studentMenu.addItem("View profile", &App::studentPromptViewProfile);
    studentMenu.addItem("Change password", &App::studentPromptChangePassword);
    studentMenu.addItem("View scoreboard", &App::studentPromptViewScoreboard);
    studentMenu.addItem("Logout", &App::logout);

    // academicMemberMenu.addItem("Create new class", &App::promptCreateClass);
    academicMemberMenu.addItem("Display current schoolyear", &App::displayCurrentSchoolyear);
    academicMemberMenu.addItem("Create new course", &App::promptCreateCourse);
    academicMemberMenu.addItem("Create new school year", &App::promptCreateSchoolYear);
    academicMemberMenu.addItem("Create semester", &App::promptCreateSemester);
    academicMemberMenu.addItem("View Student List", &App::viewAllStudent);
    academicMemberMenu.addItem("Add student to class", &App::promptAddStudent);
    // academicMemberMenu.addItem("Add student to class", &App::promptAddStudent);
    academicMemberMenu.addItem("Open Registration Session", &App::promptOpenRegistrationSession);
    academicMemberMenu.addItem("View list of courses", &App::promptViewCoursesList);
    // academicMemberMenu.addItem("Export students", &App::promptExportStudent);
    academicMemberMenu.addItem("Import scoreboard of a course", &App::promptImportCourseScoreboard);
    academicMemberMenu.addItem("View scoreboard of a course", &App::promptViewCourseScoreboard);
    academicMemberMenu.addItem("Update scoreboard of a course", &App::promptUpdateCourseScoreboard);
    academicMemberMenu.addItem("Update scoreboard of a class", &App::promptUpdateClassScoreboard);
    academicMemberMenu.addItem("Logout", &App::logout);
    while (currentStudent || currentMember) {
        if (!currentStudent) {
            if (academicMemberMenu.run() == 0){
                savefile();
                return;
            }
        } else {
            if (studentMenu.run() == 0){
                savefile();
                return;
            }
        }
        if (!currentMember && !currentStudent)
            promptLogin();
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
    App *app = new App;
    app->init();
    app->run();
	return 0;
}
