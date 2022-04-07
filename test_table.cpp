#include "Table.hpp"
#include "Text.hpp"
#include <iostream>
using namespace std;

int main() {
    Table table("Testing table");
    auto idCol = Column("ID", 5);
    table.addColumn(idCol);
    table.addColumn(Column("Name", 20, Alignment::center));
    table.addColumn("Age");
    table.addColumn(Column("Total", 10, Alignment::center));

    table.addRow(123, "Nguyen Van Aebc", 9.8, "1241");
    table.addRow(123, "Nguyen Van Aebc", 9.8, 3.2, 4.2, 7.8);
    table.addRow(vector<string>{"567", "Nguyen Van B", "4.5", "50", "215"});
    table.addRow(125, "Nguyen Van Cajg3kg3g3qkjg", "7.9");
    table.addRow(vector<string>{"125", "Nguyen Van C", "7.9", "12"});
    table.addRow(vector<string>{"125", "Nguyen Van C", "7.9"});

    table.display();
}
