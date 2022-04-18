#include "../App.h"
#include "../../utils/CSVParser.h"

void App::promptExportStudent() {
    promptViewCoursesList();
    int sel;
    cout << "Select course to export." << endl;
    cout << "select> ";
    while (!(cin >> sel) || sel < 1 || sel > currentSemester->courses.getSize()) {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Invalid input. Type again." << endl;
        cout << "select> ";
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
}
