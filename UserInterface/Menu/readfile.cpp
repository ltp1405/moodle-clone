#include "../App.h"
#include <fstream>

void App::readfile(){
    std::ifstream fin;
    fin.open("schoolyear.txt");
    SchoolYear *S = new SchoolYear;
    fin >> S->from.day >> S->from.month >> S->from.year;
    fin >> S->to.day >> S->to.month >> S->to.year;
    int num;
    fin >> num;
    for(int i = 1; i <= num; i++){
        Semester *semester_new = new Semester;
        fin >> semester_new->order;
        fin >> semester_new->start.day >> semester_new->start.month >> semester_new->start.year;
        fin >> semester_new->end.day >> semester_new->end.month >> semester_new->end.year;
        int sizecourses;
        fin >> sizecourses;
        for(int j = 0; j < sizecourses; j++){
            Course *course_new = new Course;
            fin >> course_new->id;
            fin.ignore();
            getline(fin, course_new->name);
            getline(fin, course_new->teacherName);
            fin >> course_new->credits;
            fin >> course_new->maxStudents;
            semester_new->courses.addTail(course_new);
        }
        S->semesters.addTail(semester_new);
    }
    schoolyears.addTail(S);
    currentSchoolyear = schoolyears.getTail()->data;
    fin.close();
}
