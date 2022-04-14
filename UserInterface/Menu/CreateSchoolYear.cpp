#include "../App.h"
#include "../../School/SchoolYear.h"
#include "../../utils/Date.h"

void SchoolYear::addtime(Date from, Date to ){
    this->from = from;
    this->to = to;
}

SchoolYear *CreateSchoolYear(){
    SchoolYear *S = new SchoolYear;
    Date from;
    cout << "This school year start from (input with format dd mm yy: ";
    cin >> from.day >> from.month >> from.year;
    Date to;
    cout << "This school year end at (input with format dd mm yy: ";
    cin >> to.day >> to.month >> to.year;
    
    S->addtime(from, to);
    
    return S;
}

void App::promptCreateSchoolYear(){
    cout << "Create new school year." << endl;
    SchoolYear *sc = CreateSchoolYear();
    schoolyears.addTail(sc);
    currentSchoolyear = sc;
}
