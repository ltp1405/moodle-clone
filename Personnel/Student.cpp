#include "Student.h"
#include "../UserInterface/Table.hpp"
#include "../utils/LinkedList.h"

using std::cin;
using std::cout;
using std::endl;

Student addStudent(){
	Student student;
	cout << "Student ID: ";
    getline(cin, student.id);
	cout << "Student First Name: ";
    getline(cin, student.firstname);
	cout << "Student Last Name: ";
    getline(cin, student.lastname);

	cout << "Student Gender (1 for Male, 2 for Female): ";
	int temp;
	cin >> temp;
	if(temp==1) student.gender=MALE;
	if(temp==2) student.gender=FEMALE;
	if(temp!=1&&temp!=2) student.gender=OTHER;

	cout << "Student Day Of Birth (dd mm yyyy): ";
	cin >> student.dateOfBirth.day >> student.dateOfBirth.month >> student.dateOfBirth.year;

	cout << "Student Social ID: ";
	cin >> student.SocialID;

	return student;
}

void importStudentCSV(LinkedList<Student> &student, string filename){
	std::ifstream fin;
	fin.open(filename, std::ios::in);
	DNode<Student>* temp=NULL;
	string line;
	while (getline(fin, line)){
		temp = new DNode<Student>;

		stringstream inputstream;
		inputstream.str(line);

		string No;
		inputstream >> No;

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
		
		inputstream >> temp->data.SocialID;

		student.addTail(temp->data);
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

void displayAllStudent(LinkedList<Student*> &student){
    Table tb("Student List");
    tb.addColumn(Column("ID", 8, Alignment::right));
    tb.addColumn(Column("Firstname", 15, Alignment::left));
    tb.addColumn(Column("Lastname", 15, Alignment::left));
    tb.addColumn(Column("Gender", 7, Alignment::right));
    tb.addColumn(Column("Dob", 12, Alignment::center));
    tb.addColumn(Column("Social ID"));
    for (DNode<Student*> *cur = student.getHead(); cur != nullptr; cur = cur->next) {
        Student* st = cur->data;
        string gender_name;
        if (st->gender == Gender::MALE) {
            gender_name = "Male";
        } else if (st->gender == Gender::FEMALE) {
            gender_name = "Female";
        } else {
            gender_name = "Other";
        }
        tb.addRow(st->id,
                st->firstname,
                st->lastname,
                gender_name,
                st->dateOfBirth.toString(),
                st->SocialID);
    }
    tb.display();
}

void exportStudentCSV(Student student, std::ofstream &fout){
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
	std::ofstream fout;
	fout.open("../data/Student.csv", std::ios::out);
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
