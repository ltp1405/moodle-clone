#pragma once
#include "../School/Course.h"
#include "../utils/Date.h"
#include "../utils/LinkedList.h"
struct Semester {
    int order;
    Date start;
    Date end;
    LinkedList<Course> courses;

    Semester(){}
    Semester(int order, Date start, Date end){
        this->order = order;
        this->start = start;
        this->end = end;
    }
    void addtime(int order, Date start, Date end);
    void viewListOfCourse();
    void addCourse(Course course);
    bool compareCourse(Course course1, Course course2);
    Course getCourse();
};

