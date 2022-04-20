#include "../App.h"
#include <fstream>
#include <iostream>
#include <string>

void App::savefile(){
    std::ofstream fout;
    fout.open("data/schoolyear.txt");
    int sizeschoolyear = schoolyears.getSize();
    fout << sizeschoolyear << endl;
    for(int s = 0; s < sizeschoolyear; s++){
        SchoolYear *sc = schoolyears[s]->data;
        fout << sc->from.day << " " << sc->from.month << " " << sc->from.year << endl;
        fout << sc->to.day << " " << sc->to.month << " " << sc->to.year << endl;
        int num = sc->semesters.getSize();
        fout << num << endl;
        for(int i = 1; i <= num; i++){
            fout << sc->semesters[i-1]->data->order << endl;
            Date start = sc->semesters[i-1]->data->start;
            fout << start.day << " " << start.month << " " << start.year << endl;
            Date end = sc->semesters[i-1]->data->end;
            fout << end.day << " " << end.month << " " << end.year << endl;
            int sizecourses = sc->semesters[i-1]->data->courses.getSize();
            fout << sizecourses << endl;
            for(int j = 0; j < sizecourses; j++){
                fout << sc->semesters[i-1]->data->courses[j]->data->id << endl;
                fout << sc->semesters[i-1]->data->courses[j]->data->name << endl;
                fout << sc->semesters[i-1]->data->courses[j]->data->teacherName << endl;
                fout << sc->semesters[i-1]->data->courses[j]->data->credits << endl;
                fout << sc->semesters[i-1]->data->courses[j]->data->maxStudents << endl;
                fout << sc->semesters[i-1]->data->courses[j]->data->session1.day 
                << " " << sc->semesters[i-1]->data->courses[j]->data->session1.time << endl;
                fout << sc->semesters[i-1]->data->courses[j]->data->session2.day 
                << " " << sc->semesters[i-1]->data->courses[j]->data->session2.time << endl;
                int sizestudent = sc->semesters[i-1]->data->courses[j]->data->students.getSize();
                fout << sizestudent << endl;
                for(int k = 0; k < sizestudent; k++){
                    fout << sc->semesters[i-1]->data->courses[j]->data->students[k]->data->id << endl;
                }
            }
        }
    }
    fout.close();

}

void App::saveStudentList() {
    vvs file;
    file.push_back({
            "id",
            "firstname",
            "lastname",
            "username",
            "password",
            "gender",
            "social id",
            "day",
            "month",
            "year",
            "class",
            });
    DNode<Student*> *st = studentList.getHead();
    while (st) {
        file.push_back({
                st->data->id,
                st->data->firstname,
                st->data->lastname,
                st->data->username,
                st->data->password,
                std::to_string(st->data->gender),
                st->data->SocialID,
                std::to_string(st->data->dateOfBirth.day),
                std::to_string(st->data->dateOfBirth.month),
                std::to_string(st->data->dateOfBirth.year),
                st->data->cls->classname,
                });
        st = st->next;
    }
    writeCSV("data/Student.csv", file);
}

void App::saveMemberList() {
    vvs file;
    file.push_back({ "username", "password" });
    int i = 1;
    for (DNode<AcademicMember*> *cur = memberList.getHead(); cur; cur = cur->next, i++) {
        file.push_back({ cur->data->username, cur->data->password });
    }
    writeCSV("data/Member.csv", file);
}

void App::saveClass() {
    std::ofstream fout;
    fout.open("data/Class.txt");
    if (!fout)
        return;
    fout << classes.getSize() << endl;
    DNode<Class*> *cur = classes.getHead();
    while (cur) {
        fout << cur->data->classname << endl;
        cur = cur->next;
    }
    fout.close();
}

void App::saveScoreboard() {
    vvs csv;
    csv.push_back({ "student id", "student name", "course id",
            "midterm mark", "final mark", "total mark", "other mark" });
    DNode<Score> *cur = scoreboard.getHead();
    while (cur) {
        csv.push_back({
                cur->data.id,
                cur->data.name,
                cur->data.courseId,
                std::to_string(cur->data.midtermMark),
                std::to_string(cur->data.finalMark),
                std::to_string(cur->data.totalMark),
                std::to_string(cur->data.otherMark),
                });
        cur = cur->next;
    }
    writeCSV("scoreboard.csv", csv);
}
