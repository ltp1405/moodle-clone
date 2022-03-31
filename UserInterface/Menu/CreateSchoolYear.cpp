#include "../App.h"
#include "../../School/SchoolYear.h"
#include "../../School/SchoolYear.cpp"
#include "../../utils/Date.h"

void SchoolYear::addtime(Date from, Date to, int semesterNumber ){
    this->from = from;
    this->to = to;
    this->semesterNumber = semesterNumber;
}
void promptCreateSchoolYear(SchoolYear &S){

    Date from;
    cout << "This school year start from (input with format dd mm yy: ";
    cin >> from.day >> from.month >> from.year;
    Date to;
    cout << "This school year end at (input with format dd mm yy: ";
    cin >> to.day >> to.month >> to.year;
    int semesterNumber;
    cout << "Input the number of semester in this year: ";
    cin >> semesterNumber;
    S.addtime(from, to, semesterNumber);
    for(int i = 0; i < S.semesterNumber; i++){
        Semester semester_new;
        S.addSemester(semester_new);
    }
}
