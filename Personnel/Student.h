#pragma once
#include <string>
#include "../utils/Date.h"
using std::string;

enum Gender {
	MALE,
	FEMALE,
	OTHER,
};

struct Student {
	string firstname;
	string lastname;
	string id;
	Gender gender;
	Date dateOfBirth;
	int age;

	int courseNumber;
};

void addStudent(string firstname, string lastname, string id, Gender gender, Date dateOfBirth);
void didplayStudent();
