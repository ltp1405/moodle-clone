#pragma once
#include <string>
#include "../utils/LinkedList.h"
#include "../Personnel/Student.h"
using std::string;

struct Class {
	string classname;
	LinkedList<Student> listOfStudent;
};

Class inputClass();