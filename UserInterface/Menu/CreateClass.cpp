#include "../App.h"
#include "../../Personnel/Class.h"
#include "../../Personnel/Student.h"
#include <string>

void App::promptAddClass()
{
    clearScreen();
    cout << "Input the class name(0 to stop): ";
    string classname;
    cin.ignore(100, '\n');
    getline(cin, classname);
    while(findClass(classes, classname) && classname!="0")
    {
        cout << "Class name already exists! Try again.\n\n"
             << "Input the class name(0 to stop): ";
        getline(cin, classname);
    }
    if(classname!="0")
    {
        Class *cls = new Class;
        cls->classname = classname;
        classes.addTail(cls);
    }
}
