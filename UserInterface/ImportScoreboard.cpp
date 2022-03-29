#include "../utils/LinkedList.h"
#include "../School/Score.h"
#include "../utils/CSVParser.h"
#include <iostream>
using namespace std;
using std::stod;

LinkedList<Score> importScoreboard(const string filename="../data/scoreboard.csv") {
    vvs file = readCSV(filename);
    LinkedList<Score> scoreboard;
    for (int i = 1; i < file.size(); i++) {
        Score s;
        for (int j = 0; j < file[i].size(); j++) {
            if (file[0][j] == "midterm mark")
                s.midtermMark = stod(file[i][j]);
            else if (file[0][j] == "final mark")
                s.finalMark = stod(file[i][j]);
            else if (file[0][j] == "total mark")
                s.totalMark = stod(file[i][j]);
            else if (file[0][j] == "other mark")
                s.otherMark = stod(file[i][j]);
            else if (file[0][j] == "student id")
                s.id = file[i][j];
            else if (file[0][j] == "course id")
                s.courseId = file[i][j];
            else if (file[0][j] == "student name")
                s.name = file[i][j];
        }
        scoreboard.addHead(s);
    }

    return scoreboard;
}
