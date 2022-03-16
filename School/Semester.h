#pragma once
#include "../School/Course.h"
#include "../utils/Date.h"

struct Semester {
    int order;
    Date start;
    Date end;
    Course *courses;

    Semester();
    void addSchoolYear();
    void viewListOfCourse();
    void addCourse(Course course);
    Course getCourse();
};
