#include "Menu.hpp"
#include "../Personnel/Student.h"
#include "../Personnel/AcademicMember.h"
#include "../School/SchoolYear.h"
#include "../School/Semester.h"
#include "../utils/LinkedList.h"
#include <iostream>
#include <fstream>
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
    Student *currentStudent;
    AcademicMember *currentMember;
    LinkedList<SchoolYear> schoolyears;
    Semester *currentSemester;
    SchoolYear *currentSchoolyear;
    LinkedList<Score> scoreboard;
    
private:
    // A bunch of linked list
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
    void studentPromptViewScoreboard();
    void studentViewEnrolledCourses();
    void studentPromptEnrollCourse();
    void savefile();
    void readfile();
public:
    void load();
    void run();
    void init();
};

