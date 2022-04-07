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

	string firstname;
	string lastname;
	string id;
	Gender gender;
	Date dateOfBirth;
	int SocialID;

	int courseNumber;
};

Student addStudent();
void importStudentCSV(LinkedList<Student> &student);	
void displayStudent(Student student);
void displayAllStudent(LinkedList<Student> student);
void exportStudentCSV(Student student, ofstream& fout);
void exportAllStudentCSV(LinkedList<Student> student);
