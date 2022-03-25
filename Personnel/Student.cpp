#include "Student.h"
#include "../utils/LinkedList.h"
#include "../utils/Date.h"
#include <fstream>
using namespace std;

Student addStudent(){
	Student s;
	cout << "Student ID: ";
	cin >> s.id;
	cout << "Student First Name: ";
	cin >> s.firstname;
	cout << "Student Last Name: ";
	cin >> s.lastname;

	cout << "Student Gender (1 for Male, 2 for Female): ";
	int temp;
	cin >> temp;
	if(temp==1) s.gender=MALE;
	if(temp==2) s.gender=FEMALE;

	cout << "Student Day Of Birth (DD/MM/YYYY): ";
	cin >> s.dateOfBirth.day >> s.dateOfBirth.month >> s.dateOfBirth.year;

	return s;
}

void inputStudentCSV(LinkedList<Student> &s){
	ifstream fin;
	fin.open("Student.csv");
	
}

void displayStudent(Student s) {
	cout << endl
		 << "---------------------- Student Details ----------------------\n"
		 << "Ordinary Number : " << s.ordNum << endl
		 << "Student Id      : " << s.id << endl
		 << "First Name      : " << s.firstname << endl
		 << "Last Name       : " << s.lastname << endl
		 << "Gender          : " << s.gender << endl
		 << "Date of birth   : " << s.dateOfBirth.toString() << endl
		 << endl;
}

void displayAllStudent(LinkedList<Student> s){
	cout << "---------------------- Student Details ----------------------\n";
	cout << endl
		 << "Ordinary Number : " << endl
		 << "Student Id      : " << endl
		 << "First Name      : " << endl
		 << "Last Name       : " << endl
		 << "Gender          : " << endl
		 << "Date of birth   : " << endl
		 << endl;
}