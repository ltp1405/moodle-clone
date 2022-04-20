#include "../utils/LinkedList.h"
#include "../School/Score.h"
#include "../utils/CSVParser.h"
#include "App.h"
#include <iostream>
using namespace std;

LinkedList<Score> importScoreboard(const string filename="../data/scoreboard.csv");

int main() {
    LinkedList<Score> scb = importScoreboard();
    DNode<Score> *cur = scb.getHead();
    while (cur) {
        cout << cur->data.name << " " << cur->data.totalMark << endl;
        cur = cur->next;
    }
}
