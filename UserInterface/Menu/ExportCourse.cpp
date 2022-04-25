#include "../App.h"
#include "../../utils/CSVParser.h"

void App::promptExportStudent() {
    clearScreen();
    NMenu menu;
    for (DNode<Course*> *cur = currentSemester->courses.getHead(); cur; cur = cur->next) {
        menu.addItem(cur->data->id + " - " + cur->data->name);
    }
    cout << "Select course to export." << endl;
    int sel = menu.run();
    if (sel <= 0) {
        cout << "Press any key to continue..." << endl;
        cin.ignore(100, '\n');
        cin.get();
        return;
    }
    Course *chosen = currentSemester->courses.getNodeAtIndex(sel-1)->data;

    vvs csv;
    csv.push_back({ "student id", "student name", "course id",
            "midterm mark", "final mark", "total mark", "other mark" });
    DNode<Student*> *cur = chosen->students.getHead();
    while (cur) {
        csv.push_back({
                cur->data->id,
                cur->data->lastname + " " + cur->data->firstname,
                chosen->id,
                "", "", "", ""
                });
        cur = cur->next;
    }
    writeCSV("scoreboard.csv", csv);
    cout << "Scoreboard exported to scoreboard.csv" << endl;
    cout << "Press any key to continue..." << endl;
    cin.ignore(100, '\n');
    cin.get();
}
