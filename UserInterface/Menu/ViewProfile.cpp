#include "../App.h"
#include "../Table.hpp"

void App::studentPromptViewProfile() {
    Table tb("Student Information");
    tb.addColumn(Column("", 10));
    tb.addColumn(Column("Information", 25, Alignment::center));
    tb.addRow("ID", currentStudent->id);
    tb.addRow("Name", currentStudent->lastname + " " + currentStudent->firstname);
    tb.addRow("Birthday", currentStudent->dateOfBirth.toString());
    tb.display();
    cout << "Press any key to continue..." << endl;
    cin.get();
}
