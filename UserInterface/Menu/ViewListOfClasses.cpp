#include "../App.h"
#include <iostream>
#include <string>
#include "../../utils/LinkedList.h"
#include "../../Personnel/Class.h"
#include "../Table.hpp"


void App::viewListOfClasses() {
    clearScreen();
    Table tb("List of Classes");
    tb.addColumn("Name");
    tb.addColumn("No of Student");

    DNode<Class*> *cur = classes.getHead();
    while (cur) {
        tb.addRow(
                cur->data->classname,
                cur->data->listOfStudent.getSize()
                );

        cur = cur->next;
    }

    tb.display();
    cout << "Press any key to continue..." << endl;
    cin.ignore(100, '\n');
    cin.get();
}
