#include "../../utils/LinkedList.h"
#include "../../School/Score.h"
#include "../../utils/CSVParser.h"
#include "../Table.hpp"
#include "../App.h"
#include <fstream>
#include <iostream>
#include <stdexcept>
// using namespace std;
using std::stod;
using std::cout;
using std::endl;
using std::string;

void App::promptImportCourseScoreboard() {
    clearScreen();
    cout << "Enter filename: ";
    string ans;
    cin.ignore(100, '\n');
    std::getline(cin, ans);
    std::ifstream fin;
    fin.open(ans);
    if (!fin) {
        cout << "File not found." << endl;
        cout << "Press any key to continue..." << endl;
        fin.close();
        cin.get();
        return;
    }
    fin.close();
    vvs file = readCSV(ans);
    for (int i = 1; i < file.size(); i++) {
        bool skip = false;
        for (int k = 0; k < file[i].size(); k++) {
            if (file[0][k] == "course id") {
                for (int j = 0; j < file[i].size(); j++) {
                    if (file[0][j] == "student id") {
                        for (DNode<Score> *cur = scoreboard.getHead(); cur; cur = cur->next) {
                            if (cur->data.id == file[i][j] && cur->data.courseId == file[i][k]) {
                                cout << "Student " << cur->data.id << " already added." << endl;
                                skip = true;
                                break;
                            }
                        }
                    }
                }
            }
        }

        if (skip)
            continue;
        scoreboard.addTail(Score());
        for (int j = 0; j < file[i].size(); j++) {
            try {
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
            } catch (std::invalid_argument) {
                cout << "Invalid file format. Please check again." << endl;
                scoreboard.deleteAtIndex(scoreboard.getSize()-1);
                cin.get();
                return;
            }
        }
    }
    cout << "Scoreboard imported. Press any key to continue..." << endl;
    cin.get();
}
