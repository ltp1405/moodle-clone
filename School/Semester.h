#pragma once
#include "../School/Course.h"
#include "../utils/Date.h"

struct Semester {
    int order;
    Date start;
    Date end;
    LinkedList<Course> courses;

    Semester(int order, Date start, Date end);
    void addtime(int order, Date start, Date end);
    void viewListOfCourse();
    void addCourse(Course course);
    bool compareCourse(Course course1, Course course2);
    Course getCourse();
};

