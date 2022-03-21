#include<iostream>
using namespace std;
#include "../School/SchoolYear.h"

void SchoolYear::addSemester(Semester semester){
    semesters.addTail(semester);
}
bool SchoolYear::compare(Semester semester1, Semester semester2){
    if(semester1.order == semester2.order) return true;
    else return false;
}
