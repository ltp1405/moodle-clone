#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include "Text.hpp"
using namespace std;
using std::string;
using std::tuple;


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

    Column(string name, int width=15, Alignment align=Alignment::left) {
        this->align = align;
        this->name = name;
        this->width = width;
    }
};

struct Row {
    vector<string> data;
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
    vector<Column> cols;
    vector<vector<string>> rows;

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
    void display();
};
