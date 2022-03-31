#include "Student.h"
#include "../utils/LinkedList.h"
#include "../utils/Date.h"
#include <fstream>
#include <string.h>
#include <sstream>
using namespace std;

Student addStudent(){
	Student student;
	cout << "Student ID: ";
	cin >> student.id;
	cout << "Student First Name: ";
	cin >> student.firstname;
	cout << "Student Last Name: ";
	cin >> student.lastname;

	cout << "Student Gender (1 for Male, 2 for Female): ";
	int temp;
	cin >> temp;
	if(temp==1) student.gender=MALE;
	if(temp==2) student.gender=FEMALE;
	if(temp!=1&&temp!=2) student.gender=OTHER;

	cout << "Student Day Of Birth (DD/MM/YYYY): ";
	cin >> student.dateOfBirth.day >> student.dateOfBirth.month >> student.dateOfBirth.year;

	return student;
}

void inputStudentCSV(LinkedList<Student> &student){
	ifstream fin;
	fin.open("Student.csv", ios::in);
	DNode<Student>* temp=NULL;
	string line;
	while (getline(fin, line)){
		temp = new DNode<Student>;

		stringstream inputstream;
		inputstream.str(line);

		inputstream >> temp->data.ordNum;

		inputstream >> temp->data.id;

		getline(inputstream, temp->data.firstname, ',');
		getline(inputstream, temp->data.lastname, ',');

		string studentGender;
		inputstream >> studentGender;
		if(studentGender=="1") temp->data.gender=MALE;
		if(studentGender=="2") temp->data.gender=FEMALE;
		if(studentGender!="1" && studentGender!="2") temp->data.gender=OTHER;

		string sDob;
		getline(inputstream, sDob, ',');
		stringstream dobstream;
		dobstream.str(sDob);
		dobstream >> temp->data.dateOfBirth.day;
		dobstream >> temp->data.dateOfBirth.month;
		dobstream >> temp->data.dateOfBirth.year;

		student.addTail(temp->data);
	}
}

void displayStudent(Student student) {
	cout << endl
		 << "---------------------- Student Details ----------------------\n"
		 << "Ordinary Number : " << student.ordNum << endl
		 << "Student Id      : " << student.id << endl
		 << "First Name      : " << student.firstname << endl
		 << "Last Name       : " << student.lastname << endl
		 << "Gender          : " << student.gender << endl
		 << "Date of birth   : " << student.dateOfBirth.toString() << endl
		 << endl;
}

void displayAllStudent(LinkedList<Student> student){
	cout << "---------------------- Student Details ----------------------\n"
		 << endl
		 << "Ordinary Number : " << endl
		 << "Student Id      : " << endl
		 << "First Name      : " << endl
		 << "Last Name       : " << endl
		 << "Gender          : " << endl
		 << "Date of birth   : " << endl
		 << endl;
}
