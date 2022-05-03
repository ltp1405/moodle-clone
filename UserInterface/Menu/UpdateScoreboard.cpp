#include "../App.h"
#include "../Table.hpp"

void change_midterm(Score *score) {
    string inp;
    cout << "Enter new midterm mark. Leave empty to skip." << endl;
    cout << "input> ";
    getline(cin, inp);
    if (inp == "")
        return;
    double i;
    try {
        i = std::stof(inp);
    } catch (std::invalid_argument) {
        cout << "Invalid input. Credits not changed." << endl;
        return;
    }
    score->midtermMark = i;
}

void change_final(Score *score) {
    string inp;
    cout << "Enter new final mark. Leave empty to skip." << endl;
    cout << "input> ";
    getline(cin, inp);
    if (inp == "")
        return;
    double i;
    try {
        i = std::stof(inp);
    } catch (std::invalid_argument) {
        cout << "Invalid input. Credits not changed." << endl;
        return;
    }
    score->finalMark = i;
}

void change_total(Score *score) {
    string inp;
    cout << "Enter new total mark. Leave empty to skip." << endl;
    cout << "input> ";
    getline(cin, inp);
    if (inp == "")
        return;
    double i;
    try {
        i = std::stof(inp);
    } catch (std::invalid_argument) {
        cout << "Invalid input. Credits not changed." << endl;
        return;
    }
    score->totalMark = i;
}

void change_other(Score *score) {
    string inp;
    cout << "Enter new other mark. Leave empty to skip." << endl;
    cout << "input> ";
    getline(cin, inp);
    if (inp == "")
        return;
    double i;
    try {
        i = std::stof(inp);
    } catch (std::invalid_argument) {
        cout << "Invalid input. Credits not changed." << endl;
        return;
    }
    score->otherMark = i;
}

void App::editScoreboard(int row_id) {
    Score *score = &scoreboard.getNodeAtIndex(row_id)->data;
    change_midterm(score);
    change_final(score);
    change_other(score);
    change_total(score);
}

void App::promptUpdateScoreboard() {
    clearScreen();
    NMenu menu;
    DNode<Course*> *crs = currentSemester->courses.getHead();
    while (crs) {
        menu.addItem(crs->data->id + " - " + crs->data->name);
        crs = crs->next;
    }
    cout << "Select course to edit." << endl;
    int sel = menu.run();
    if (sel == 0)
        return;

    DNode<Course*> *chosen = currentSemester->courses.getNodeAtIndex(sel-1);
    Table score_table("Scoreboard");
    score_table.addColumn(Column("Order", 5));
    score_table.addColumn(Column("ID", 9));
    score_table.addColumn("Name");
    score_table.addColumn(Column("Midterm", 7));
    score_table.addColumn(Column("Final", 6));
    score_table.addColumn(Column("Other", 6));
    score_table.addColumn(Column("Total", 6));

    DNode<Score> *cur_s = scoreboard.getHead();
    LinkedList<int> score_i;
    LinkedList<Score*> score_s;
    int count = 1;

    while (cur_s) {
        if (cur_s->data.courseId == chosen->data->id) {
            score_i.addTail(count);
            score_table.addRow(
                    count,
                    cur_s->data.id,
                    cur_s->data.name,
                    cur_s->data.midtermMark,
                    cur_s->data.finalMark,
                    cur_s->data.otherMark,
                    cur_s->data.totalMark
            );
        }
        count++;
        cur_s = cur_s->next;
    }

    int inp;
    cout << score_i.getSize();
    bool editing = true;
    while (editing) {
        clearScreen();
        Table score_table("Scoreboard");
        score_table.addColumn(Column("Order", 5));
        score_table.addColumn(Column("ID", 9));
        score_table.addColumn("Name");
        score_table.addColumn(Column("Midterm", 7));
        score_table.addColumn(Column("Final", 6));
        score_table.addColumn(Column("Other", 6));
        score_table.addColumn(Column("Total", 6));
        DNode<Score> *cur_s = scoreboard.getHead();

        int count = 1;
        while (cur_s) {
            if (cur_s->data.courseId == chosen->data->id) {
                score_table.addRow(
                        count,
                        cur_s->data.id,
                        cur_s->data.name,
                        cur_s->data.midtermMark,
                        cur_s->data.finalMark,
                        cur_s->data.otherMark,
                        cur_s->data.totalMark
                );
            }
            count++;
            cur_s = cur_s->next;
        }
        score_table.display();

        cout << "Select a row to edit. Select 0 to exit" << endl;
        cout << "select> ";
        while (!(cin >> inp) && inp < 0 && inp < score_i.getSize()) {
            cout << "Wrong input. Please type again or type 0 to exit." << endl;
        }
        cin.ignore(100, '\n');
        if (inp == 0)
            return;
        editScoreboard(inp-1);
    }
}
