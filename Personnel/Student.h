#pragma once
#include "../utils/LinkedList.h"
#include "../utils/Date.h"
#include "../School/Course.h"
#include "Class.h"
#include <fstream>
#include <string.h>
#include <sstream>
// using namespace std;
using std::string;

struct Course;
struct Class;

enum Gender {
	MALE=1,
	FEMALE=2,
	OTHER=3,
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
	string SocialID;

    Class *cls = nullptr;
    LinkedList<Course*> courses;
};

Student addStudent();
void importStudentCSV(LinkedList<Student> &student, string filename);	
void displayStudent(Student student);
void displayAllStudent(LinkedList<Student*> &student);
void exportStudentCSV(Student student, std::ofstream& fout);
void exportAllStudentCSV(LinkedList<Student> student);
