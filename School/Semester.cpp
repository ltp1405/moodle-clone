#include <iostream>
using namespace std;
#include "../School/Semester.h"


void Semester::addCourse(Course course){
    courses.addTail(course);
}

void Semester::viewListOfCourse(){
    printList(courses);
}
