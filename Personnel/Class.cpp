#include "Class.h"

Class inputClass(){
    Class c;
    cin.ignore(1000,'\n');
    cout << "Input classcode(e.x: 21CTT1): ";
    getline(cin,c.classname);
    return c;
}