#include "../App.h"
#include "../../Personnel/Class.h"
#include "../../Personnel/Student.h"
#include <string>

void App::promptAddClass()
{
    cout << "Input the class name(e.g: 21CTT1): ";
    string classname;
    cin >> classname;
    while(findClass(classes, classname))
    {
        cout << "Class name already exists! Try again.\n\n"
             << "Input the class name: ";
        cin >> classname;
    }
    Class *cls = new Class;
    cls->classname = classname;
    classes.addTail(cls);
}
