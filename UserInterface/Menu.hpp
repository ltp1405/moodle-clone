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
    void run();
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
void Menu<T>::run() {
    for (int i = 0; i < menuItems.size(); i++) {
        cout << i+1 << "/ ";
        cout << menuItems[i] << std::endl;
    }

    cout << "Choose " << 1 << "-" << menuItems.size() << std::endl;
    cout << "Choose 0 to cancel" << std::endl;
    cout << "> ";
    int choice;
    cin >> choice;
    if (choice == 0)
        return;

    callbacks[choice-1](context);
}
