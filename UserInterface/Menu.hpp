#pragma once
#include <ios>
#include <iostream>
#include <functional>
#include <iterator>
#include <string>
#include <vector>
#include <fstream>
using std::cout;
using std::cin;
using std::string;

template <typename T>
class Menu {
private:
    T *context;
    std::vector<string> menuItems;
    std::vector<std::function<void(T*)>> callbacks;

public:
    Menu(T*);
    void addItem(string itemName, std::function<void(T*)>);
    int run();
};

template <typename T>
Menu<T>::Menu(T *context) {
    this->context = context;
}

template <typename T>
void Menu<T>::addItem(string itemName, std::function<void(T*)> callback) {
    menuItems.push_back(itemName);
    callbacks.push_back(callback);
}

template <typename T>
int Menu<T>::run() {
    int len = 0;
    for (auto s : menuItems) {
        if (s.length() > len)
            len = s.length();
    }
    len += 11;
    for (int i = 0; i < len; i++) {
        cout << "=";
    }
    cout << std::endl;

    for (int i = 0; i < menuItems.size(); i++) {
        cout << "   " << i+1 << ". " << "\t";
        cout << menuItems[i] << std::endl;
    }

    for (int i = 0; i < len; i++) {
        cout << "=";
    }

    cout << std::endl;
    cout << "Choose " << 1 << "-" << menuItems.size() << std::endl;
    cout << "Choose 0 to cancel" << std::endl;
    cout << "> ";
    int choice;
    while (!(cin >> choice) || choice < 0 || choice > menuItems.size()) {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Invalid choice. Please choose again." << std::endl;
        cout << "> ";
    }
    if (choice == 0)
        return 0;

    callbacks[choice-1](context);
    return choice;
}

class NMenu {
private:
    std::vector<string> menuItems;

public:
    NMenu();
    void addItem(string itemName);
    int run();
};
