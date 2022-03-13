#include "Menu.h"

Menu::Menu() {
    numberOfItems = 0;
}

void Menu::addItem(string itemName) {
    menuItems[numberOfItems] = itemName;
    numberOfItems++;
}

int Menu::getInput() {
    for (int i = 0; i < numberOfItems; i++) {
        cout << i+1 << "/ ";
        cout << menuItems[i] << std::endl;
    }

    cout << "Choose " << 1 << "-" << numberOfItems << std::endl;
    cout << "> ";
    int choice;
    cin >> choice;
    
    return choice;
}

