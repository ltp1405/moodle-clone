#pragma once

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

	Course *enrolledCourse;
	int courseNumber;
	const int maxCourses = 5;
};
