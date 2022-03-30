#include "Table.hpp"
#include <cstdarg>

int Table::getWidth() {
    int width = 0;
    for (auto col = cols.getHead(); col != nullptr; col = col->next) {
        width += col->data.width;
    }
    width += cols.getSize() + 1;
    return width;
}

void Table::printLine(const string s, int length) {
    for (int i = 0; i < length; i++)
        cout << s;
}

void Table::printTop() {
    cout << upperLeft;
    for (auto col = cols.getHead(); col != nullptr; col = col->next) {
        printLine(horizontal, col->data.width);
        if (col != cols.getTail())
            cout << horizontalUp;
        else
            cout << upperRight;
    }
    cout << endl;
}

void Table::printBot() {
    cout << lowerLeft;
    for (auto col = cols.getHead(); col != nullptr; col = col->next) {
        printLine(horizontal, col->data.width);
        if (col != cols.getTail())
            cout << horizontalDown;
        else
            cout << lowerRight;
    }
    cout << endl;
}

void Table::printBotHeader() {
    cout << verticalLeft;
    for (auto col = cols.getHead(); col; col = col->next) {
        printLine(horizontal, col->data.width);
        if (col != cols.getTail())
            cout << horizontalVertical;
        else
            cout << verticalRight;
    }
    cout << endl;
}

Table::Table(string title) {
    this->title = title;
}

void Table::addColumn(string name) {
    cols.addTail(Column(name));
}

void Table::addColumn(Column col) {
    cols.addTail(col);
}

void Table::addRow(vector<string> data) {
    while (data.size() < cols.getSize()) {
        data.push_back("");
    }

    while (data.size() > cols.getSize()) {
        data.pop_back();
    }
    rows.addTail(LinkedList<string>());
    for (auto d : data) {
        rows.getTail()->data.addTail(d);
    }
}

void Table::display() {
    printTop();

    cout << vertical;
    for (auto col = cols.getHead(); col; col = col->next) {
        if (col->data.align == Alignment::left)
            cout.setf(std::ios::left);
        else if (col->data.align == Alignment::right)
            cout.setf(std::ios::right);
        cout.width(col->data.width);
        cout << col->data.name;
        cout << vertical;
    }

    cout << endl;
    printBotHeader();
    for (auto row = rows.getHead(); row != nullptr; row = row->next) {
        cout << vertical;
        for (int i = 0; i < row->data.getSize(); i++) {
            if (cols[i]->data.align == Alignment::left)
                cout.setf(std::ios::left);
            else if (cols[i]->data.align == Alignment::right)
                cout.setf(std::ios::right);

            cout.width(cols[i]->data.width);
            if (row->data[i]->data.length() > cols[i]->data.width) {
                cout << row->data[i]->data.substr(0, cols[i]->data.width-3) + "...";
            } else
                cout << row->data[i]->data;
            cout << vertical;
        }

        cout << endl;
    }
    printBot();
}
