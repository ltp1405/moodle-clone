#include "../App.h"
#include <iostream>
#include <string>
#include "../../utils/LinkedList.h"
#include "../../Personnel/Class.h"
#include "../Table.hpp"


void App::viewListOfClasses() {
    Table tb("List of Course");
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
}
