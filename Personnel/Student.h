#pragma once
#include "../utils/LinkedList.h"
#include <string>
#include "../utils/Date.h"
using std::string;

enum Gender {
	MALE,
	FEMALE,
	OTHER,
};

struct Student {
	Student() {}
	string id;
    string username;
	string firstname;
	string lastname;
    string password;
	Gender gender;
	Date dateOfBirth;
};

Student addStudent();
void inputStudentCSV(LinkedList<Student*> &student);
void displayStudent(Student student);
void displayAllStudent(LinkedList<Student*> student);
