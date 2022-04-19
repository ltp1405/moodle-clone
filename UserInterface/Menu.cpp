#include "Menu.hpp"

NMenu::NMenu() {
}

void NMenu::addItem(string itemName) {
    menuItems.push_back(itemName);
}

int NMenu::run() {
    for (int i = 0; i < menuItems.size(); i++) {
        cout << i+1 << "/ ";
        cout << menuItems[i] << std::endl;
    }

    cout << "Choose " << 1 << "-" << menuItems.size() << std::endl;
    cout << "Choose 0 to cancel" << std::endl;
    cout << "> ";
    int choice;
    cin >> choice;
    if (choice < 0 || choice > menuItems.size()) {
        cout << "Invalid choice. No action was done.";
        return -1;
    }
    if (choice == 0)
        return 0;

    return choice;
}
