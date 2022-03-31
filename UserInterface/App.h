#include "Menu.hpp"
#include "../Personnel/Student.h"
#include "../Personnel/AcademicMember.h"
#include "../School/SchoolYear.h"
#include "../School/Semester.h"
#include "../utils/LinkedList.h"
#include <iostream>
#include <string>
#include "../School/SchoolYear.h"
#include "../utils/LinkedList.h"
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
    
private:
    // A bunch of linked list
    LinkedList<SchoolYear> schoolyears;
    void promptLoginAsStudent();
    void promptLoginAsAMember();
    void promptLogin();
    void promptCreateCourse();
    void promptCreateSchoolYear();
    void promptAddStudent();
    void promptCreateSemester();
    void promptViewScoreboard();
    void promptOpenRegistrationSession();
    void promptViewCoursesList();
    void promptExportStudent();
    void promptImportCourseScoreboard();
    void promptViewCourseScoreboard();
    void promptUpdateClassScoreboard();
    void promptUpdateCourseScoreboard();
    void studentPromptViewProfile();
    void studentPromptChangePassword();
    void studentPromptViewScoreboard();
    void studentPromptEnrollCourse();
public:
    void load();
    void run();
    void init();
};

