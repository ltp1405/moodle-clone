#include "Class.h"
using namespace std;

Class inputClass(){
    Class c;
    cin.ignore(1000,'\n');
    cout << "Input classcode: ";
    getline(cin,c.classname);
    return c;
}