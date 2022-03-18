#include "Table.hpp"

int Table::getWidth() {
    int width = 0;
    for (auto col = cols.begin(); col != cols.end(); col++) {
        width += col->width;
    }
    width += cols.size() + 1;
    return width;
}

void Table::printLine(const string s, int length) {
    for (int i = 0; i < length; i++)
        cout << s;
}

void Table::printTop() {
    cout << upperLeft;
    for (auto col = cols.begin(); col != cols.end(); col++) {
        printLine(horizontal, col->width);
        if (col != cols.end() - 1)
            cout << horizontalUp;
        else
            cout << upperRight;
    }
    cout << endl;
}

void Table::printBot() {
    cout << lowerLeft;
    for (auto col = cols.begin(); col != cols.end(); col++) {
        printLine(horizontal, col->width);
        if (col != cols.end() - 1)
            cout << horizontalDown;
        else
            cout << lowerRight;
    }
    cout << endl;
}

void Table::printBotHeader() {
    cout << verticalLeft;
    for (auto col = cols.begin(); col != cols.end(); col++) {
        printLine(horizontal, col->width);
        if (col != cols.end() - 1)
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
    cols.push_back(Column(name));
}

void Table::addColumn(Column col) {
    cols.push_back(col);
}

void Table::addRow(vector<string> data) {
    while (data.size() < cols.size()) {
        data.push_back("");
    }

    while (data.size() > cols.size()) {
        data.pop_back();
    }
    rows.push_back(data);
}

void Table::display() {
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
            if ((*row)[i].length() > cols[i].width) {
                cout << (*row)[i].substr(0, cols[i].width-3) + "...";
            } else
                cout << (*row)[i];
            cout << "│";
        }

        cout << endl;
    }
    printBot();
}
