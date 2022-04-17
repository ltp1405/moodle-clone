#include "../App.h"
#include <fstream>

bool empty(std::ifstream& file)
{
    return file.peek() == std::ifstream::traits_type::eof();
}

void App::readfile(){
    std::ifstream fin;
    fin.open("schoolyear.txt");
    if(!fin){
        cout << "Can not read file." << endl;
        return;
    }
    if(empty(fin)){
        cout << "Input by hand :)) ." << endl;
        return;
    }
    int sizeschoolyear;
    fin >> sizeschoolyear;
    for(int s = 0; s < sizeschoolyear; s++){
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
                int sizesession;
                fin >> sizesession;
                for(int k = 0; k < sizesession; k++){
                    Session *session_new = new Session;
                    int a, b;
                    fin >> a >> b;
                    session_new->day = (Day)a;
                    session_new->time = (Time)b;
                    course_new->sessions.addTail(session_new);
                }
                int sizestudent;
                fin >> sizestudent;
                for(int k = 0; k < sizestudent; k++){
                    Student *student_new = new Student;
                    string id;
                    fin.ignore();
                    getline(fin, id);
                    for(int i = 0; i < studentList.getSize(); i++){
                        if(studentList[i]->data->id == id){
                            student_new = studentList[i]->data;
                            break;
                        }
                    }
                    course_new->students.addTail(student_new);
                }
                semester_new->courses.addTail(course_new);
            }
            S->semesters.addTail(semester_new);
        }
        schoolyears.addTail(S);
        currentSchoolyear = schoolyears.getTail()->data;
        currentSemester = currentSchoolyear->semesters.getTail()->data;
    }
    fin.close();
}
