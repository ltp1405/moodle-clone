#include "Table.hpp"
#include <cstdarg>

using std::cout;
using std::endl;

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

void Table::printTitle() {
    int cellWidth = getWidth();
    int cellDataWidth = title.size();
    int frontPadding = (cellWidth - cellDataWidth) / 2
        + (cellWidth - cellDataWidth) % 2;
    int backPadding = (cellWidth - cellDataWidth) / 2;
    for (int i = 0; i < frontPadding-1; i++) {
        cout << "~";
    }
    cout << " " << title << " ";
    for (int i = 0; i < backPadding-1; i++)
        cout << "~";
    cout << endl;
}

void Table::display() {
    printTitle();
    printTop();

    cout << vertical;
    for (auto col = cols.getHead(); col; col = col->next) {
        if (col->data.align == Alignment::left) {
            cout.setf(std::ios::left);
            cout.width(col->data.width);
        } else if (col->data.align == Alignment::right) {
            cout.setf(std::ios::right);
            cout.width(col->data.width);
        } else if (col->data.align == Alignment::center) {
            int cellWidth = col->data.width;
            int cellDataWidth = col->data.name.size();
            int frontPadding = (cellWidth - cellDataWidth) / 2
                + (cellWidth - cellDataWidth) % 2;
            int backPadding = (cellWidth - cellDataWidth) / 2;
                for (int i = 0; i < frontPadding; i++) {
                    cout << " ";
                }
        }

        cout << col->data.name;

        if (col->data.align == Alignment::center) {
            int cellWidth = col->data.width;
            int cellDataWidth = col->data.name.size();
            int backPadding = (cellWidth - cellDataWidth) / 2;
            for (int i = 0; i < backPadding; i++)
                cout << " ";
        }

        cout << vertical;
    }

    cout << endl;
    printBotHeader();
    for (auto row = rows.getHead(); row != nullptr; row = row->next) {
        cout << vertical;
        for (int i = 0; i < row->data.getSize(); i++) {
            if (cols[i]->data.align == Alignment::left) {
                cout.setf(std::ios::left);
                cout.width(cols[i]->data.width);
            } else if (cols[i]->data.align == Alignment::right) {
                cout.setf(std::ios::right);
                cout.width(cols[i]->data.width);
            } else if (cols[i]->data.align == Alignment::center) {
                int cellWidth = cols[i]->data.width;
                int cellDataWidth = row->data[i]->data.size();
                int frontPadding = (cellWidth - cellDataWidth) / 2
                    + (cellWidth - cellDataWidth) % 2;
                int backPadding = (cellWidth - cellDataWidth) / 2;
                    for (int i = 0; i < frontPadding; i++) {
                        cout << " ";
                    }
            }

            if (row->data[i]->data.length() > cols[i]->data.width) {
                cout << row->data[i]->data.substr(0, cols[i]->data.width-3) + "...";
            } else
                cout << row->data[i]->data;
            if (cols[i]->data.align == Alignment::center) {
                int cellWidth = cols[i]->data.width;
                int cellDataWidth = row->data[i]->data.size();
                int backPadding = (cellWidth - cellDataWidth) / 2;
                for (int i = 0; i < backPadding; i++)
                    cout << " ";
            }
            cout << vertical;
        }

        cout << endl;
    }
    printBot();
}
