#include "../App.h"
#include "../../School/Semester.h"

void promptViewCoursesList(Semester semester_new){
    semester_new.viewListOfCourse();
    cout << "Press any key to continue..." << endl;
    cin.get();
}
