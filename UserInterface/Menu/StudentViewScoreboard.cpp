#include <iostream>
#include "../App.h"
#include "../Table.hpp"
#include "../../Personnel/Student.h"

void App::studentPromptViewScoreboard() {
    DNode<Score> *cur = scoreboard.getHead();
    Table table("Scoreboard");
    table.addColumn(Column("Order", 5));
    table.addColumn(Column("Midterm", 7, Alignment::center));
    table.addColumn(Column("Final", 6, Alignment::center));
    table.addColumn(Column("Total", 6, Alignment::center));
    table.addColumn(Column("Other", 6, Alignment::center));
    table.addColumn(Column("Course ID", 9));
    int count = 1;
    while (cur) {
        if (cur->data.id == currentStudent->id) {
            table.addRow(count, cur->data.midtermMark, cur->data.finalMark,
                    cur->data.totalMark, cur->data.otherMark, cur->data.courseId);
            count++;
        }
        cur = cur->next;
    }
    table.display();
}
