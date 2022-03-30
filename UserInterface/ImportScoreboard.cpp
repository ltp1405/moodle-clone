#include "../utils/LinkedList.h"
#include "../School/Score.h"
#include "../utils/CSVParser.h"
#include "App.h"
#include <iostream>
using namespace std;
using std::stod;

void App::promptImportCourseScoreboard() {
    cout << "Enter filename, (leave empty for default: data/scoreboard.csv) :";
    string ans;
    std::getline(cin, ans);
    cout << "Scoreboard imported" << endl;
    vvs file = readCSV("../data/scoreboard.csv");
    for (int i = 1; i < file.size(); i++) {
        scoreboard.addTail(Score());
        for (int j = 0; j < file[i].size(); j++) {
            if (file[0][j] == "midterm mark")
                scoreboard.getTail()->data.midtermMark = stod(file[i][j]);
            else if (file[0][j] == "final mark")
                scoreboard.getTail()->data.finalMark = stod(file[i][j]);
            else if (file[0][j] == "total mark")
                scoreboard.getTail()->data.totalMark = stod(file[i][j]);
            else if (file[0][j] == "other mark")
                scoreboard.getTail()->data.otherMark = stod(file[i][j]);
            else if (file[0][j] == "student id")
                scoreboard.getTail()->data.id = file[i][j];
            else if (file[0][j] == "course id")
                scoreboard.getTail()->data.courseId = file[i][j];
            else if (file[0][j] == "student name")
                scoreboard.getTail()->data.name = file[i][j];
        }
    }
}

void App::promptViewScoreboard() {
    DNode<Score> *cur = scoreboard.getHead();
    while (cur) {
        cout << cur->data.name << " ";
        cout << cur->data.midtermMark << " ";
        cout << cur->data.finalMark << " ";
        cout << cur->data.totalMark << " ";
        cout << cur->data.otherMark << " ";
        cout << cur->data.courseId << " ";
        cout << endl;
        cur = cur->next;
    }
}

void App::run() {
    promptImportCourseScoreboard();
    promptViewScoreboard();
}

int main() {
    App app;
    app.run();
}
