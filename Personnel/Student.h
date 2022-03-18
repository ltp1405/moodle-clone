#pragma once
#include "../School/Course.h"
#include <string>
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

	Course *enrolledCourse;
	int courseNumber;
	const int maxCourses = 5;
};

void addStudent(string firstname, string lastname, string id, Gender gender, Date dateOfBirth);
void didplayStudent();