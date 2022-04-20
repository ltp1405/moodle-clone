#include "../App.h"
#include "../../utils/LinkedList.h"
#include <string>

void App::promptAddStudent() {
    clearScreen();
    cout << "Which class do you want to add to?" << endl;
    cout << "classname> ";
    string inp;
    cin.ignore(100, '\n');
    std::getline(std::cin, inp);
    DNode<Class*> *cur = classes.getHead();
    while (cur) {
        if (cur->data->classname == inp) {
            Student *st = new Student;
            *st = addStudent();
            studentList.addHead(st);
            st->cls = cur->data;
            st->password = "student";
            st->username = st->id;
            cur->data->listOfStudent.addTail(st);
            cout << "Student added!" << endl;
            cout << "Press any key to continue..." << endl;
            cin.get();
            return;
        }
        cur = cur->next;
    }
}
