#include "../App.h"
#include <iostream>
#include "../../School/SchoolYear.h"
#include "../../utils/LinkedList.h"
#include "../../School/Semester.h"

void App::displayCurrentSchoolyear() {
    if (!currentSchoolyear)
        return;

    cout << currentSchoolyear->from.toString();
    cout << " - ";
    cout << currentSchoolyear->to.toString();
    cout << endl;

    cout << "Semesters" << endl;
    for (DNode<Semester*> *cur = currentSchoolyear->semesters.getHead();
            cur != nullptr;
            cur = cur->next) {
        cout << "\t| ";
        cout << cur->data->order;
        cout << " : ";
        cout << cur->data->start.toString();
        cout << " - ";
        cout << cur->data->end.toString();
        cout << endl;
    }
}
