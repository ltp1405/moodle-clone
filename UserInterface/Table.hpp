#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include "Text.hpp"
using namespace std;
using std::string;
using std::tuple;


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
    int getWidth() {
        int width = 0;
        for (auto col = cols.begin(); col != cols.end(); col++) {
            width += col->width;
        }
        width += cols.size() + 1;
        return width;
    }

    void printTop() {
        cout << "┌";
        for (auto col = cols.begin(); col != cols.end(); col++) {
            for (int i = 0; i < col->width; i++)
                cout << "─";
            if (col != cols.end() - 1)
                cout << "┬";
            else
                cout << "┐";
        }
        cout << endl;
    }

    void printBot() {
        cout << "└";
        for (auto col = cols.begin(); col != cols.end(); col++) {
            for (int i = 0; i < col->width; i++)
                cout << "─";
            if (col != cols.end() - 1)
                cout << "┴";
            else
                cout << "┘";
        }
        cout << endl;
    }

    void printBotHeader() {
        cout << "├";
        for (auto col = cols.begin(); col != cols.end(); col++) {
            for (int i = 0; i < col->width; i++)
                cout << "─";
            if (col != cols.end() - 1)
                cout << "┼";
            else
                cout << "┤";
        }
        cout << endl;
    }

public:
    Table(string title) {
        this->title = title;
    }

    void addColumn(string name) {
        cols.push_back(Column(name));
    }

    void addColumn(Column col) {
        cols.push_back(col);
    }

    void addRow(vector<string> data) {
        while (data.size() < cols.size()) {
            data.push_back("");
        }

        while (data.size() > cols.size()) {
            data.pop_back();
        }
        rows.push_back(data);
    }

    void display() {
        printTop();

        cout << "│";
        for (auto col = cols.begin(); col != cols.end(); col++) {
            if (col->align == Alignment::left)
                cout.setf(std::ios::left);
            else if (col->align == Alignment::right)
                cout.setf(std::ios::right);
            cout.width(col->width);
            cout << col->name;
            cout << "│";
        }

        cout << endl;
        printBotHeader();
        for (auto row = rows.begin(); row != rows.end(); row++) {
            cout << "│";
            for (int i = 0; i < row->size(); i++) {
                if (cols[i].align == Alignment::left)
                    cout.setf(std::ios::left);
                else if (cols[i].align == Alignment::right)
                    cout.setf(std::ios::right);

                cout.width(cols[i].width);
                cout << (*row)[i];
                cout << "│";
            }

            cout << endl;
        }
        printBot();
    }
};
