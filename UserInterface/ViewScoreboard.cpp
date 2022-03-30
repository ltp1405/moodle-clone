#include "Table.hpp"
#include "App.h"

void App::promptViewScoreboard() {
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
}

