#include "../App.h"
#include <iostream>
#include <fstream>
#include <string>

void App::promptImportStudent() {
    std::cin.ignore(100, '\n');
    cout << "Which class do you want to add to?" << endl;
    cout << "classname> ";
    string inp;
    std::getline(std::cin, inp);
    DNode<Class*> *cur = classes.getHead();
    Class *chosenClass = nullptr;
    while (cur) {
        if (cur->data->classname == inp) {
            chosenClass = cur->data;        
        }
        cur = cur->next;
    }
    if (!chosenClass) {
        cout << "Class not found." << endl;
        return;
    }
    cout << "Enter file path: ";
    std::ifstream fin;
    cin.ignore(100, '\n');
    std::getline(std::cin, inp);
    fin.open(inp);
    while (!fin) {
        cout << "Wrong path. Please type again: ";
        std::getline(std::cin, inp);
        fin.open(inp);
    }
    fin.close();

    vvs file = readCSV(inp);
    for (int i = 1; i < file.size(); i++) {
        Student *st = new Student;
        for (int j = 0; j < file[i].size(); j++) {
            if (file[0][j] == "firstname")
                st->firstname = file[i][j];
            else if (file[0][j] == "lastname")
                st->lastname = file[i][j];
            else if (file[0][j] == "id")
                st->id = file[i][j];
            else if (file[0][j] == "password")
                st->password = file[i][j];
            else if (file[0][j] == "gender") {
                int g = stod(file[i][j]);
                if (g == 1)
                    st->gender = Gender::MALE;
                else if (g == 2)
                    st->gender = Gender::FEMALE;
                else
                    st->gender = Gender::OTHER;
            } else if (file[0][j] == "day")
                st->dateOfBirth.day = stod(file[i][j]);
            else if (file[0][j] == "month")
                st->dateOfBirth.month = stod(file[i][j]);
            else if (file[0][j] == "year")
                st->dateOfBirth.year = stod(file[i][j]);
            else if (file[0][j] == "username")
                st->username = file[i][j];
        }
        chosenClass->listOfStudent.addTail(st);
        st->cls = chosenClass;
        studentList.addTail(st);
    }
}
