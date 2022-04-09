#include "Student.h"
#include "../utils/LinkedList.h"
#include "../utils/Date.h"
#include "../utils/CSVParser.h"
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

void inputStudentCSV(LinkedList<Student*> &student){
	ifstream fin;
	fin.open("Student.csv", ios::in);
	string line;
	while (getline(fin, line)){
		auto *temp = new Student;

		stringstream inputstream;
		inputstream.str(line);


		inputstream >> temp->id;

		getline(inputstream, temp->firstname, ',');
		getline(inputstream, temp->lastname, ',');

		string studentGender;
		inputstream >> studentGender;
		if(studentGender=="1") temp->gender=MALE;
		if(studentGender=="2") temp->gender=FEMALE;
		if(studentGender!="1" && studentGender!="2") temp->gender=OTHER;

		string sDob;
		getline(inputstream, sDob, ',');
		stringstream dobstream;
		dobstream.str(sDob);
		dobstream >> temp->dateOfBirth.day;
		dobstream >> temp->dateOfBirth.month;
		dobstream >> temp->dateOfBirth.year;

		student.addTail(temp);
	}
}

void displayStudent(Student student) {
	cout << endl
		 << "---------------------- Student Details ----------------------\n"
		 << "Student Id      : " << student.id << endl
		 << "Username        : " << student.username << endl
		 << "First Name      : " << student.firstname << endl
		 << "Last Name       : " << student.lastname << endl
		 << "Gender          : " << student.gender << endl
		 << "Date of birth   : " << student.dateOfBirth.toString() << endl
		 << endl;
}

void displayAllStudent(LinkedList<Student*> student){
    DNode<Student*> *st = student.getHead();
    while (st) {
        displayStudent(*st->data);
        st = st->next;
    }
}
