#include <string>
#include <fstream>
#include <vector>
#include <iostream>

#include "../App.h"
#include "../../utils/CSVParser.h"

using namespace std;

bool checkLoginInfo(vvs& login_info, string username, string password) {
    for (int i = 1; i < login_info.size(); i++) {
        if (login_info[i][0] == username && login_info[i][1] == password) 
            return true;
    }
    return false;
}

void App::promptLoginAsAMember() {
    vvs login_info = readCSV("data/AcademicMemberLoginInfo.csv");
    string username, password;
    short count_input_time = 0;
    cin.ignore(100, '\n');
    while (count_input_time < 3) {
        system("cls");
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
    vvs login_info = readCSV("data/StudentLoginInfo.csv");
    string username, password;
    short count_input_time = 0;
    cin.ignore(100, '\n');
    while (count_input_time < 3) {
        system("cls");
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
    system("cls");
    exit(0);
}
