#include "../Table.hpp"
#include "../App.h"

void App::viewScoreboard() {
    clearScreen();
    DNode<Score> *cur = scoreboard.getHead();
    Table table("Scoreboard");
    table.addColumn(Column("Order", 5));
    table.addColumn("Name");
    table.addColumn(Column("Midterm", 7));
    table.addColumn(Column("Final", 6));
    table.addColumn(Column("Total", 6));
    table.addColumn(Column("Other", 6));
    table.addColumn(Column("Course ID", 9));
    int count = 1;
    while (cur) {
        table.addRow(count ,cur->data.name, cur->data.midtermMark, cur->data.finalMark,
                cur->data.totalMark, cur->data.otherMark, cur->data.courseId);
        cur = cur->next;
        count++;
    }
    table.display();
    cout << "Press any key to continue..." << endl;
    cin.ignore(100, '\n');
    cin.get();
}

bool inSemester(Semester *sm, const string courseID) {
    DNode<Course*> *crs = sm->courses.getHead();
    while (crs) {
        if (crs->data->id == courseID)
            return true;
        crs = crs->next;
    }
    return false;
}

void App::viewClassScoreboard() {
    clearScreen();
    cout << "Enter class name: ";
    string inp;
    std::cin.ignore(100, '\n');
    std::getline(std::cin, inp);
    Class *cls = findClass(classes, inp);
    if (!cls) {
        cout << "Class not found." << endl;
        return;
    }

    DNode<Student*> *st = cls->listOfStudent.getHead();
    while (st) {
        double semesterGPA = 0;
        int inSm = 0;
        int count = 0;
        double totalGPA = 0;
        if (st->data->courses.getSize() == 0) {
            st = st->next;
            continue;
        }
        Table tb(st->data->firstname + "'s Scoreboard");
        tb.addColumn(Column("", 20));
        tb.addColumn(Column("Score", 10));
        DNode<Score> *score = scoreboard.getHead();
        while (score) {
            if (score->data.id == st->data->id) {
                count++;
                totalGPA += score->data.finalMark;
                if (inSemester(currentSemester, score->data.courseId)) {
                    tb.addRow(score->data.courseId, score->data.finalMark);
                    semesterGPA += score->data.finalMark;
                    inSm++;
                }
            }
            score = score->next;
        }
        if (count == 0) {
            st = st->next;
            continue;
        }
        tb.addRow("Semester GPA", semesterGPA/inSm);
        tb.addRow("Total GPA", totalGPA/st->data->courses.getSize());
        st = st->next;
        tb.display();
    }
    cout << "Press any key to continue..." << endl;
    cin.get();
}
