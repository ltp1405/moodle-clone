#include "../App.h"
#include <fstream>
void App::savefile(){
    std::ofstream fout;
    fout.open("schoolyear.txt");
    SchoolYear *sc = schoolyears.getTail()->data;
    fout << sc->from.day << " " << sc->from.month << " " << sc->from.year << endl;
    fout << sc->to.day << " " << sc->to.month << " " << sc->to.year << endl;
    fout << sc->semesterNumber << endl;
    for(int i = 1; i <= sc->semesterNumber; i++){
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
        }
    }
    fout.close();

}
