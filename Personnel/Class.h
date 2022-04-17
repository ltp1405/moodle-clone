#pragma once
#include <string>
#include "../utils/LinkedList.h"
#include "../Personnel/Student.h"
#include <string.h>
#include <fstream>
// using namespace std;
using std::string;

struct Student;

struct Class {
	string classname;
	LinkedList<Student *> listOfStudent;
};

void importClassTXT(LinkedList<Class*>& c);
bool findClass(LinkedList<Class*> &c, string find);
