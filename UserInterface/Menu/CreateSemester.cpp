#include "../App.h"
#include "../../School/Semester.h"
#include "../../School/Semester.cpp"

void Semester::addtime(int order, Date start, Date end){
    this->order = order;
    this->start = start;
    this->end = end;
}
void promptCreateSemester(Semester &semester_new){
    int order;
    cout << "Input the order of this semester: ";
    cin >> order;
    Date start;
    cout << "Input the start date of this semester (format dd mm yy): ";
    cin >> start.day >> start.month >> start.year;
    Date end;
    cout << "Input the end date of this semester (format dd mm yy): ";
    cin >> end.day >> end.month >> end.year;
    semester_new.addtime(order, start, end);
    int numCourses;
    cout << "Input the number of courses you want in this semester: ";
    cin >> numCourses;
    for(int i = 0; i < numCourses; i++){
        Course course_new;
        semester_new.addCourse(course_new);
    }
}