#pragma once
#include "../School/Semester.h"
#include "../utils/Date.h"

struct SchoolYear {
    Date from;
    Date to;
    Semester *semesters;
    int semesterNumber;

    SchoolYear();
    void addBeginDate();
    void addEndDate();
    void addSemester(Semester semester);
};
