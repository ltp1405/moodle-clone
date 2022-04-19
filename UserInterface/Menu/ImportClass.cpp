#include "../App.h"
#include <iostream>
#include <fstream>
#include <string>

bool validPath(const std::string path) {
    std::ifstream fin;
    fin.open(path);
    if (!fin) {
        fin.close();
        return false;
    }

    fin.close();
    return true;
}

void App::promptImportStudent() {
    cout << "Choose the class to import." << endl;
    cout << "classname> ";
    string inp;
    cin.ignore(100, '\n');
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

    cout << "File format: " << endl;
    cout << "+ In CSV" << endl;
    cout << "+ The file must have at least 'id', 'firstname', 'lastname', 'gender'," << endl;
    cout << "'day', 'month', 'year'" << endl << endl;
    cout << "Enter file path: ";
    std::getline(cin, inp);
    while (!validPath(inp)) {
        cout << "Invalid path. Please type again." << endl;
        std::getline(cin, inp);
    }

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
        if (st->username == "") {
            st->username = st->id;
        }
        if (st->password == "") {
            st->password = "student";
        }
        chosenClass->listOfStudent.addTail(st);
        st->cls = chosenClass;
        studentList.addTail(st);
    }
}
