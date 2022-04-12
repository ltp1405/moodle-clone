#pragma once
#include <iostream>
#include <functional>
#include <string>
#include <vector>
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

    callbacks[choice-1](context);
    return choice;
}

template <typename T>
class NMenu {
private:
    std::vector<string> menuItems;

public:
    NMenu();
    void addItem(string itemName);
    int run();
};

template <typename T>
NMenu<T>::NMenu() {
}

template <typename T>
void NMenu<T>::addItem(string itemName) {
    menuItems.push_back(itemName);
}

template <typename T>
int NMenu<T>::run() {
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
