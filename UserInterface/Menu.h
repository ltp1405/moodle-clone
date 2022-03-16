#pragma once
#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::string;

class Menu {
private:
    string menuItems[20];
    int numberOfItems;

public:
    Menu();
    void addItem(string itemName);
    int getInput();
};
