#include <iostream>
using namespace std;
#include "../School/Semester.h"


void Semester::addCourse(Course course){
    courses.addTail(course);
}

void Semester::viewListOfCourse(){
    printList(courses);
}

bool compareCourse(Course course1, Course course2){
    if(course1.id == course2.id) return true;
    else return false;
}