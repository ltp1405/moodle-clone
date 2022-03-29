#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include "../utils/LinkedList.h"
#include "Text.hpp"
using namespace std;
using std::string;

const string upperRight = "┐";
const string lowerLeft = "└";
const string horizontalDown = "┴";
const string horizontalUp = "┬";
const string verticalLeft = "├";
const string horizontal = "─";
const string horizontalVertical = "┼";
const string lowerRight = "┘";
const string upperLeft = "┌";
const string vertical = "│";
const string verticalRight = "┤";

enum Alignment {
    center,
    left,
    right
};

struct Column {
    int width;
    string name;
    Alignment align;
    Color color;

    Column() {}
    Column(string name, int width=15, Alignment align=Alignment::left) {
        this->align = align;
        this->name = name;
        this->width = width;
    }
};

struct Row {
    LinkedList<string> data;
};

enum BorderStyle {
    Bold,
    Double,
    Normal,
    Shadow,
};

class Table {
    BorderStyle headerBorderStyle;
    BorderStyle borderStyle;
    string title;
    LinkedList<Column> cols;
    LinkedList<LinkedList<string>> rows;

private:
    int getWidth();
    void printTop();
    void printBot();
    void printBotHeader();
    void printLine(const string s, int times);
public:
    Table(string title);
    void addColumn(string name);
    void addColumn(Column col);
    void addRow(vector<string> data);

    void addEach(int count) {
        int diff = count - cols.getSize();
        if (diff < 0) {
            for (int i = 0; i < -diff; i++) {
                rows.getTail()->data.addTail("");
            }
        } else if (diff > 0) {
            for (int i = 0; i < diff; i++) {
                rows.getTail()->data.deleteTail();
            }
        }
    }

    template<typename T, typename... Ts>
    void addEach(int count, T var1, Ts... var2) {
        stringstream sstr;
        sstr << var1;

        rows.getTail()->data.addTail(sstr.str());
        addEach(count+1, var2...);
    }
    
    template<typename... Ts> void addRow(Ts... data) {
        rows.addTail(LinkedList<string>());
        addEach(0, data...);
    }
    void display();
};
