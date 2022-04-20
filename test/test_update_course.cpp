#include <iostream>
#include "School/Course.h"
using namespace std;

void updateCourse(Course &crs);

int main() {
    Course crs = Course();
    crs.id = "cs162";
    crs.maxStudents = 40;
    crs.teacherName = "Tung";
    crs.name = "Computer Science";

    updateCourse(crs);
    cout << crs.id << endl;
    cout << crs.name << endl;
    cout << crs.teacherName << endl;

    return 0;
}
