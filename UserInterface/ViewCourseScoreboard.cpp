#include "App.h"
#include "../utils/LinkedList.h"
#include "../School/Course.h"
#include "Menu.hpp"
#include "Table.hpp"
#include <string>
using std::string;

void App::viewScoreboard(const string id) {
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
        if (id == cur->data.courseId) {
            table.addRow(count ,cur->data.name, cur->data.midtermMark, cur->data.finalMark,
                    cur->data.totalMark, cur->data.otherMark, cur->data.courseId);
            count++;
        }
        cur = cur->next;
    }
    table.display();
}

void App::promptViewCourseScoreboard() {
    DNode<Course> *cur = currentSemester->courses.getHead();
    cout << "Available Course: " << endl;
    int count = 0;
    int inp;
    while (cur) {
        count++;
        cout << count << " " << cur->data.id << " - " << cur->data.name << endl;
        cur = cur->next;
    }
    cin >> inp;
    viewScoreboard(currentSemester->courses[inp-1]->data.id);
}
