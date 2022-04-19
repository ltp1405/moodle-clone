#include "../App.h"
#include "../../Personnel/Student.h"
#include "../../Personnel/Class.h"
#include "../Table.hpp"

void App::viewClass(){
    cout << "Enter class name: ";
    string inp;
    std::cin.ignore(100, '\n');
    std::getline(std::cin, inp);
    Class *cls = findClass(classes, inp);
    if (!cls) {
        cout << "Class not found." << endl;
        return;
    }

    Table tb("Class");
    tb.addColumn(Column("ID", 8, Alignment::right));
    tb.addColumn(Column("Firstname", 15, Alignment::left));
    tb.addColumn(Column("Lastname", 15, Alignment::left));
    tb.addColumn(Column("Gender", 7, Alignment::right));
    tb.addColumn(Column("Dob", 12, Alignment::center));
    tb.addColumn(Column("Social ID"));
    tb.addColumn(Column("Class", 7));
    for (DNode<Student*> *cur = cls->listOfStudent.getHead(); cur != nullptr; cur = cur->next) {
        Student* st = cur->data;
        string gender_name;
        if (st->gender == Gender::MALE) {
            gender_name = "Male";
        } else if (st->gender == Gender::FEMALE) {
            gender_name = "Female";
        } else {
            gender_name = "Other";
        }
        tb.addRow(st->id,
                st->firstname,
                st->lastname,
                gender_name,
                st->dateOfBirth.toString(),
                st->SocialID,
                st->cls->classname
        );
    }
    tb.display();
}

