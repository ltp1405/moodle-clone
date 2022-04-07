#include "../App.h"
#include <fstream>
void App::savefile(){
    std::ofstream fout;
    fout.open("schoolyear.txt");
    fout << schoolyears.getTail()->data.from.day << " " << schoolyears.getTail()->data.from.month << " " << schoolyears.getTail()->data.from.year << endl;
    fout << schoolyears.getTail()->data.to.day << " " << schoolyears.getTail()->data.to.month << " " << schoolyears.getTail()->data.to.year << endl;
    fout << schoolyears.getTail()->data.semesterNumber << endl;
    for(int i = 1; i <= schoolyears.getTail()->data.semesterNumber; i++){
        fout << schoolyears.getTail()->data.semesters[i-1]->data.order << endl;
        Date start = schoolyears.getTail()->data.semesters[i-1]->data.start;
        fout << start.day << " " << start.month << " " << start.year << endl;
        Date end = schoolyears.getTail()->data.semesters[i-1]->data.end;
        fout << end.day << " " << end.month << " " << end.year << endl;
        int sizecourses = schoolyears.getTail()->data.semesters[i-1]->data.courses.getSize();
        fout << sizecourses << endl;
        for(int j = 0; j < sizecourses; j++){
            fout << schoolyears.getTail()->data.semesters[i-1]->data.courses[j]->data.id << endl;
            fout << schoolyears.getTail()->data.semesters[i-1]->data.courses[j]->data.name << endl;
            fout << schoolyears.getTail()->data.semesters[i-1]->data.courses[j]->data.teacherName << endl;
            fout << schoolyears.getTail()->data.semesters[i-1]->data.courses[j]->data.credits << endl;
            fout << schoolyears.getTail()->data.semesters[i-1]->data.courses[j]->data.maxStudents << endl;
        }
    }
    fout.close();

}