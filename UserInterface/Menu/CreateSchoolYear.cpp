#include "../App.h"
#include "../../School/SchoolYear.h"
#include "../../utils/Date.h"
#include "../../utils/ClearScreen.h"

void SchoolYear::addtime(Date from, Date to ){
    this->from = from;
    this->to = to;
}

SchoolYear *CreateSchoolYear(){
    SchoolYear *S = new SchoolYear;
    Date from;
    cout << "This school year start from (input with format dd mm yy): ";
    cin >> from.day >> from.month >> from.year;
    Date to;
    cout << "This school year end at (input with format dd mm yy): ";
    cin >> to.day >> to.month >> to.year;
    
    S->addtime(from, to);
    
    return S;
}

void App::promptCreateSchoolYear(){
    clearScreen();
    SchoolYear *sc = CreateSchoolYear();
    cout << "School Year added. Press any key to continue..." << endl;
    cin.ignore(100, '\n');
    cin.get();
    schoolyears.addTail(sc);
    currentSchoolyear = sc;
}
