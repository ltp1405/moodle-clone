#pragma once
#include "../utils/LinkedList.h"
#include "../utils/Date.h"
#include <string>
using std::string;

enum Gender {
	MALE,
	FEMALE,
	OTHER,
};

struct Student {
	Student();
	int ordNum;
	string firstname;
	string lastname;
	string id;
	Gender gender;
	Date dateOfBirth;

	int courseNumber;
};

Student addStudent();
void inputStudentCSV(LinkedList<Student> &s);	
void displayStudent(Student s);
