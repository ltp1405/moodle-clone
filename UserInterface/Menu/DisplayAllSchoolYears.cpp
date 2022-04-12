#include "../App.h"
#include <iostream>
#include "../../School/SchoolYear.h"
#include "../../utils/LinkedList.h"
#include "../../School/Semester.h"

void App::displayAllSchoolYears() {
    if (!currentSchoolyear)
        return;

    for (DNode<SchoolYear *> *cur = schoolyears.getHead(); cur != nullptr; cur = cur->next) {
        currentSchoolyear = cur->data;
        cout << currentSchoolyear->from.toString();
        cout << " - ";
        cout << currentSchoolyear->to.toString();
        cout << endl;

        if (currentSchoolyear->semesters.getSize() == 0) {
            cout << "No semester avaliable." << endl;
            continue;
        }
        cout << "+- [Semesters]" << endl;
        for (DNode<Semester*> *cur = currentSchoolyear->semesters.getHead();
                cur != nullptr;
                cur = cur->next) {
            cout << "| ";
            cout << "Semester " << cur->data->order;
            cout << " : ";
            cout << cur->data->start.toString();
            cout << " - ";
            cout << cur->data->end.toString();
            cout << endl;
        }
    }
}
