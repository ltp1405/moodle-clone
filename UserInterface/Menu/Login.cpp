#include <string>
#include <fstream>
#include <vector>
#include <iostream>

#include "../App.h"
#include "../../Personnel/Student.h"
#include "../../utils/LinkedList.h"
#include "../../utils/CSVParser.h"
#include "../../utils/ClearScreen.h"

// using namespace std;
using std::string;
using std::cin;
using std::cout;

void App::promptLoginAsAMember() {
    string username, password;
    short count_input_time = 0;
    cin.ignore(100, '\n');
    while (count_input_time < 3) {
        clearScreen();
        cout << (count_input_time ? "Invalid username or password. Try again\n" : ""); 
        count_input_time++;
        cout << "Enter username: ";
        getline(cin, username);
        cout << "\nEnter password: ";
        getline(cin, password);
        for (auto *st = memberList.getHead(); st != nullptr; st = st->next) {
            if (st->data->username == username && st->data->password == password) {
                cout << "Login successful";
                currentMember = st->data;
                cin.ignore(100, '\n');
                return;
            }
        }
    }
    exit(0);
}

void App::promptLoginAsStudent() {
    string username, password;
    short count_input_time = 0;
    cin.ignore(100, '\n');
    while (count_input_time < 3) {
        clearScreen();
        cout << (count_input_time ? "Invalid username or password. Try again\n" : ""); 
        count_input_time++;
        cout << "Enter username: ";
        getline(cin, username);
        cout << "\nEnter password: ";
        getline(cin, password);
        for (auto *st = studentList.getHead(); st != nullptr; st = st->next) {
            if (st->data->username == username && st->data->password == password) {
                cout << "Login successful";
                currentStudent = st->data;
                cin.ignore(100, '\n');
                return;
            }
        }
    }
    clearScreen();
    exit(0);
}
