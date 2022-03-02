#pragma once

struct CourseRegistrationSession {
	bool activated;
	Date start;
	Date end;
};

struct Course {
	string id;
	string name;
	string teacherName;
	int numberOfCredits;
	int maxStudents;
	Session *sessions;
	const int sessionNumbers = 2;
};
