#include <iostream>
using namespace std;
#include "../School/Semester.h"
#include "../utils/LinkedList.h"

void Semester::addCourse(Course course){
    courses.addTail(course);
}
void printCourse(Course course){
    cout << course.id << endl;
}
void Semester::viewListOfCourse(){
    courses.printList(printCourse);
}

bool compareCourse(Course course1, Course course2){
    if(course1.id == course2.id) return true;
    else return false;
}
