#pragma once

struct SchoolYear {
	Date from;
	Date to;
	Semester *semesters;
	int semesterNumber;
};
