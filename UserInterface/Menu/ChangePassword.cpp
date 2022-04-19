#include "../App.h"
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

void App::memberPromptChangePassword() {
    if (!currentMember) {
        cout << "Profile error. Please login again to continue." << endl;
        return;
    }

    string in;
    cout << "Enter old password: " << endl;
    cout << "old password> ";
    cin.ignore(100, '\n');
    getline(cin, in);
    int count = 1;
    while (in != currentMember->password) {
        if (count > 3) {
            cout << "No attempts left. Exit..." << endl;
            return;
        }
        cout << "Wrong password. Please type again." << endl;
        cout << "old password> ";
        getline(cin, in);
        count++;
    }

    cout << "Enter new password." << endl;
    cout << "new password> ";
    getline(cin, in);
    string in2;
    cout << "Reenter new password." << endl;
    cout << "new password> ";
    getline(cin, in2);
    while (in != in2) {
        cout << "Password not match. Retry..." << endl;
        cout << "Enter new password." << endl;
        cout << "new password> ";
        getline(cin, in);
        cout << "Reenter new password." << endl;
        cout << "new password> ";
        getline(cin, in2);
    }
    currentMember->password = in;
}

void App::studentPromptChangePassword() {
    if (!currentStudent) {
        cout << "Profile error. Please login again to continue." << endl;
        return;
    }

    string in;
    cout << "Enter old password: " << endl;
    cout << "old password> ";
    cin.ignore(100, '\n');
    getline(cin, in);
    int count = 1;
    while (in != currentStudent->password) {
        if (count > 3) {
            cout << "No attempts left. Exit..." << endl;
            return;
        }
        cout << "Wrong password. Please type again." << endl;
        cout << "old password> ";
        getline(cin, in);
        count++;
    }

    cout << "Enter new password." << endl;
    cout << "new password> ";
    getline(cin, in);
    string in2;
    cout << "Reenter new password." << endl;
    cout << "new password> ";
    getline(cin, in2);
    while (in != in2) {
        cout << "Password not match. Retry..." << endl;
        cout << "Enter new password." << endl;
        cout << "new password> ";
        getline(cin, in);
        cout << "Reenter new password." << endl;
        cout << "new password> ";
        getline(cin, in2);
    }
    currentStudent->password = in;
}
