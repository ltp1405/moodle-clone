#pragma once
#include "../School/Semester.h"
#include "../utils/Date.h"
#include "../utils/LinkedList.h"
struct SchoolYear {
    Date from;
    Date to;
    LinkedList<Semester> semesters;
    int semesterNumber;

    SchoolYear(){}
    SchoolYear(Date from, Date to, int semesterNumber){
        this->from = from;
        this->to = to;
        this->semesterNumber = semesterNumber;
    }
    void addtime(Date from, Date to, int semesterNumber);
    void addSemester(Semester semester);
    bool compare(Semester semester1, Semester semester2);
};
