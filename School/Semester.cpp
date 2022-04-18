#include <iostream>
// using namespace std;
#include "../School/Semester.h"
#include "../utils/LinkedList.h"

using std::cout;
using std::endl;

void Semester::addCourse(Course course){
    Course *crs = new Course(course);
    courses.addTail(crs);
}
void printCourse(Course course){
    cout << course.id << endl;
}
void Semester::viewListOfCourse(){
}

bool compareCourse(Course course1, Course course2){
    if(course1.id == course2.id) return true;
    else return false;
}
void Semester::activateRegistration(Date from, Date to) {
    rgs.from = from;
    rgs.to = to;
}
bool Semester::registratable() {
    Date now = today();
    return now >= rgs.from && now <= rgs.to;
}
