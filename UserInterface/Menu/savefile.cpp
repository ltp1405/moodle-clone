#include "../App.h"
#include <fstream>
void App::savefile(){
    std::ofstream fout;
    fout.open("schoolyear.txt");
    SchoolYear *sc = schoolyears.getTail()->data;
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
            int sizesession = sc->semesters[i-1]->data->courses[j]->data->sessions.getSize();
            fout << sizesession << endl;
            for(int k = 0; k < sizesession; k++){
                fout << sc->semesters[i-1]->data->courses[j]->data->sessions[k]->data->day 
                << " " << sc->semesters[i-1]->data->courses[j]->data->sessions[k]->data->time << endl;
            }
            int sizestudent = sc->semesters[i-1]->data->courses[j]->data->students.getSize();
            fout << sizestudent << endl;
            for(int k = 0; k < sizestudent; k++){
                fout << sc->semesters[i-1]->data->courses[j]->data->students[k]->data->id << endl;
            }
        }
    }
    fout.close();

}
