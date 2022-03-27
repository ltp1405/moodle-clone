#pragma once
#include "../School/Course.h"
#include "../utils/LinkedList.h"
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

	Course *enrolledCourse;
	int courseNumber;
	const int maxCourses = 5;
};

Student addStudent();
void inputStudentCSV(LinkedList<Student> &student);	
void displayStudent(Student student);
void displayAllStudent(LinkedList<Student> student);