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

	cout << "Student Social ID: ";
	cin >> student.SocialID;

	return student;
}

void importStudentCSV(LinkedList<Student *> &student, string filename){
	ifstream fin;
	fin.open(filename, ios::in);
	DNode<Student*>* temp=NULL;
	string line;
	while (getline(fin, line)){
		auto *temp = new Student;

		stringstream inputstream;
		inputstream.str(line);

		string No;
		inputstream >> No;

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

		inputstream >> temp->SocialID;

		student.addTail(temp);
		delete temp;
	}
	fin.close();
}

void displayStudent(Student student) {
	system("cls");
	cout << endl
		 << "---------------------- Student Details ----------------------\n"
		 << "Student ID     : " << student.id << endl
		 << "First Name     : " << student.firstname << endl
		 << "Last Name      : " << student.lastname << endl
		 << "Gender         : " << student.gender << endl
		 << "Date of birth  : " << student.dateOfBirth.toString() << endl
		 << "Social ID      : " << endl
		 << endl;
}

void displayAllStudent(LinkedList<Student*> student){
	cout << "---------------------- Student Details ----------------------\n"
		 << endl
		 << "Student ID     : " << endl
		 << "First Name     : " << endl
		 << "Last Name      : " << endl
		 << "Gender         : " << endl
		 << "Date of birth  : " << endl
		 << "Social ID      : " << endl
		 << endl;
}
void exportStudentCSV(Student student, ofstream &fout){
	fout << student.id << ","
		 << student.firstname << ","
		 << student.lastname << ",";
	if(student.gender==MALE) fout << "1,";
	if(student.gender==FEMALE) fout << "2,"; 
	if(student.gender==OTHER) fout << "3,";
	fout << student.dateOfBirth.toString() << ","
		 << student.SocialID;
}

void exportAllStudentCSV(LinkedList<Student> student){
	ofstream fout;
	fout.open("../data/Student.csv",ios::out);
	DNode<Student>* temp = student.getHead();
	int count = 0;
	while(!temp){
		++count;
		fout << count << ",";
		exportStudentCSV(temp->data, fout);
		fout << endl;
		temp=temp->next;
	}
	fout.close();
}
