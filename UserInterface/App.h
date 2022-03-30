#include "Menu.hpp"
#include <iostream>
#include <string>
#include "../School/SchoolYear.h"
#include "../utils/LinkedList.h"
#include "../School/Score.h"
#include "../Personnel/Student.h"
#include "../School/Semester.h"
using std::cout;
using std::cin;
using std::string;
using std::endl;

class App {
private:
    // A bunch of linked list
    Student *currentStudent;
    Semester *currentSemester;
    LinkedList<Score> scoreboard;
    LinkedList<SchoolYear> schoolyears;
    void promptLoginAsStudent();
    void promptLoginAsAMember();
    void promptLogin();
    void promptCreateCourse();
    void promptCreateSchoolYear();
    void promptAddStudent();
    void promptCreateSemester();
    void viewScoreboard();
    void promptOpenRegistrationSession();
    void promptViewCoursesList();
    void promptExportStudent();
    void promptImportCourseScoreboard();
    void promptViewCourseScoreboard();
    void promptUpdateClassScoreboard();
    void promptUpdateCourseScoreboard();
    void studentPromptViewProfile();
    void studentPromptChangePassword();
    void studentViewScoreboard();
    void viewScoreboard(const string courseId);
public:
    void load();
    void run();
    void init();
};

