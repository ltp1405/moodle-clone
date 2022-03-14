#pragma once
#include "../School/Semester.h"
#include "../utils/Date.h"

struct SchoolYear {
    Date from;
    Date to;
    LinkedList<Semester> semesters;
    int semesterNumber;

    SchoolYear(Date from, Date to);
    void addtime(Date from, Date to);
    void addSemester(Semester semester);
    bool compare(Semester semester1, Semester semester2);
};
