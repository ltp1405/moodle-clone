#include "../App.h"
#include "../../Personnel/Class.h"

void promptCreateClass()
{
    LinkedList<Class> CLASS;
    importClassTXT(CLASS);
    cout << "Input the class name(e.g: 21CTT1): ";
    string classname;
    cin >> classname;
    while(findClass(CLASS,classname))
    {
        cout << "Class name already exists! Try again.\n\n"
             << "Input the class name: ";
        cin >> classname;
    }
    
    ofstream fout;
    fout.open("../../data/Class.txt",ios::app);
    fout << endl << classname;
    fout.close();
}