#include "Menu.hpp"
#include <iostream>
#include <string>
#include "../School/SchoolYear.h"
#include "../utils/LinkedList.h"
using std::cout;
using std::cin;
using std::string;
using std::endl;

class App {
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
public:
    void load();
    void run();
    void init();
};

