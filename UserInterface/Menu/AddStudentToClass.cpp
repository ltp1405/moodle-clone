#include "../App.h"
#include "../../utils/LinkedList.h"
#include <string>

void App::promptAddStudent() {
    cout << "Which class do you want to add to?" << endl;
    cout << "classname> ";
    string inp;
    std::getline(std::cin, inp);
    DNode<Class*> *cur = classes.getHead();
    while (cur) {
        if (cur->data->classname == inp) {
            Student *st = new Student;
            *st = addStudent();
            studentList.addHead(st);
            cur->data->listOfStudent.addTail(st);
            cout << "Student added!" << endl;
        }
        cur = cur->next;
    }
}
