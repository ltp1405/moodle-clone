#include "Course.h"
#include <iostream>
using std::cout;
using std::endl;

Course::Course(string courseId, string courseName, int numberOfCredits, int maxStudents, string teacher) {
    id = courseId;
    name = courseName;
    credits = numberOfCredits;
    this->maxStudents = maxStudents;
    teacherName = teacher;
}

Course::Course() {}

void Course::addSession(Session session, int num) {
    if (num == 1) {
        session1 = session;
    } else if (num == 2) {
        session2 = session;
    }
}

void Course::print() {
    cout << "ID: " << id << endl;
    cout << "Course name: " << name << endl;
    cout << "Max number of students: " << maxStudents << endl;
    cout << "Teacher name: " << teacherName << endl;
    cout << "Credits: " << credits << endl;
}

Session::Session() {
    day = Day::MON;
    time = Time::S1;
}

Session::Session(Day day, Time time) {
    this->day = day;
    this->time = time;
}

string Session::toString() {
    string s;
    switch (day) {
        case Day::MON:
            s += "Mon";
            break;
        case Day::TUE:
            s += "Tue";
            break;
        case Day::WED:
            s += "Wed";
            break;
        case Day::THU:
            s += "Thu";
            break;
        case Day::FRI:
            s += "Fri";
            break;
        case Day::SAT:
            s += "Sat";
            break;
    }

    s += " ";

    switch (time) {
        case S1:
            s += "7:30 - 9:00";
            break;
        case S2:
            s += "9:30 - 11:00";
            break;
        case S3:
            s += "1:30 - 3:00";
            break;
        case S4:
            s += "3:30 - 5:00";
            break;
    }

    return s;
}

bool validDay(string day) {
    return day == "mon"
        || day == "tue"
        || day == "wed"
        || day == "thu"
        || day == "fri"
        || day == "sat";
}

bool validTime(string time) {
    return time == "s1"
        || time == "s2"
        || time == "s3"
        || time == "s4";
}

Day parseDay(string day) {
    if (day == "mon")
        return Day::MON;
    if (day == "tue")
        return Day::TUE;
    if (day == "wed")
        return Day::WED;
    if (day == "thu")
        return Day::THU;
    if (day == "fri")
        return Day::FRI;
    return Day::SAT;
}

Time parseTime(string time) {
    if (time == "s1")
        return Time::S1;
    if (time == "s2")
        return Time::S2;
    if (time == "s3")
        return Time::S3;
    return Time::S4;
}

