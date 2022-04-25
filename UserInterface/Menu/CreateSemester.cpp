#include "../App.h"
#include "../../School/Semester.h"
#include "../../utils/ClearScreen.h"

void Semester::addtime(int order, Date start, Date end){
    this->order = order;
    this->start = start;
    this->end = end;
}

void CreateSemester(Semester &semester_new){
    int order;
    cout << "Input the order of this semester: ";
    cin >> order;
    Date start;
    cout << "Input the start date of this semester (format dd mm yy): ";
    cin >> start.day >> start.month >> start.year;
    Date end;
    cout << "Input the end date of this semester (format dd mm yy): ";
    cin >> end.day >> end.month >> end.year;
    semester_new.addtime(order, start, end);
}

void App::promptCreateSemester(){
    if (!currentSchoolyear) {
        cout << "No schoolyear available. Please create one first." << endl;
        cin.ignore(100, '\n');
        cin.get();
        return;
    }
    clearScreen();
    Semester* semester_new = new Semester;
    currentSchoolyear->semesters.addTail(semester_new);
    CreateSemester(*currentSchoolyear->semesters.getTail()->data);
    cout << "Semester added. Press any key to continue..." << endl;
    cin.ignore(100, '\n');
    cin.get();
    currentSemester = currentSchoolyear->semesters.getTail()->data;
}
