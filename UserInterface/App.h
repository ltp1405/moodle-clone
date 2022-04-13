#include "Menu.hpp"
#include "../Personnel/Student.h"
#include "../Personnel/AcademicMember.h"
#include "../School/SchoolYear.h"
#include "../School/Semester.h"
#include "../utils/LinkedList.h"
#include "../utils/CSVParser.h"
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
    Student *currentStudent = nullptr;
    AcademicMember *currentMember = nullptr;
    Semester *currentSemester;
    SchoolYear *currentSchoolyear;
    LinkedList<Score> scoreboard;
    LinkedList<SchoolYear *> schoolyears;
    LinkedList<AcademicMember *> memberList;
    LinkedList<Student*> studentList;
    
private:
    // A bunch of linked list
    void logout();
    void loadStudentList();
    void loadMemberList();
    void promptLoginAsStudent();
    void promptLoginAsAMember();
    void promptLogin();
    void promptCreateClass();
    void promptCreateCourse();
    void promptUpdateCourse();
    void promptCreateSchoolYear();
    void promptAddStudent();
    void promptCreateSemester();
    void viewScoreboard();
    void viewAllStudent();
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
    void displayCurrentSchoolyear();
    void displayAllSchoolYears();
    void savefile();
    void readfile();
public:
    ~App();
    void load();
    void run();
    void init();
    void close();
};

