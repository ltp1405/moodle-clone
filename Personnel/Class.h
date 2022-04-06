#pragma once
#include <string>
#include "../utils/LinkedList.h"
#include "../Personnel/Student.h"
#include <string.h>
using namespace std;

struct Class {
	string classname;
	LinkedList<Student> listOfStudent;
};

Class inputClass();