#include "../../utils/LinkedList.h"
#include "../../School/Score.h"
#include "../../utils/CSVParser.h"
#include "../Table.hpp"
#include "../App.h"
#include <fstream>
#include <iostream>
// using namespace std;
using std::stod;
using std::cout;
using std::endl;
using std::string;

void App::promptImportCourseScoreboard() {
    clearScreen();
    cout << "Enter filename:";
    string ans;
    cin.ignore(100, '\n');
    std::getline(cin, ans);
    cout << "Scoreboard imported" << endl;
    std::ifstream fin;
    fin.open(ans);
    if (!fin) {
        cout << "File not found." << endl;
        fin.close();
        return;
    }
    fin.close();
    vvs file = readCSV(ans);
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
    cout << "Scoreboard imported. Press any key to continue..." << endl;
    cin.get();
}
