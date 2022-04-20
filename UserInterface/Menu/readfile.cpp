#include "../App.h"
#include <fstream>

bool empty(std::ifstream& file)
{
    return file.peek() == std::ifstream::traits_type::eof();
}

void App::readfile(){
    std::ifstream fin;
    fin.open("data/schoolyear.txt");
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
                fin.ignore();
                getline(fin, course_new->id);
                getline(fin, course_new->name);
                getline(fin, course_new->teacherName);
                fin >> course_new->credits;
                fin >> course_new->maxStudents;

                Session session_new;
                int a, b;
                fin >> a >> b;
                session_new.day = (Day)a;
                session_new.time = (Time)b;
                course_new->session1 = session_new;
                fin >> a >> b;
                session_new.day = (Day)a;
                session_new.time = (Time)b;
                course_new->session2 = session_new;

                int sizestudent;
                fin >> sizestudent;
                for(int k = 0; k < sizestudent; k++){
                    string id;
                    fin.ignore();
                    getline(fin, id);
                    for(DNode<Student*> *cur = studentList.getHead(); cur; cur = cur->next){
                        if(cur->data->id == id){
                            course_new->students.addTail(cur->data);
                            cur->data->courses.addTail(course_new);
                            break;
                        }
                    }
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

void App::loadStudentList() {
    std::ifstream fin;
    fin.open("data/Student.csv");
    if (!fin) {
        return;
        fin.close();
    }
    fin.close();
    vvs file = readCSV("data/Student.csv");
    for (int i = 1; i < file.size(); i++) {
        Student *st = new Student;
        for (int j = 0; j < file[i].size(); j++) {
            if (file[0][j] == "firstname")
                st->firstname = file[i][j];
            else if (file[0][j] == "lastname")
                st->lastname = file[i][j];
            else if (file[0][j] == "id")
                st->id = file[i][j];
            else if (file[0][j] == "password")
                st->password = file[i][j];
            else if (file[0][j] == "gender") {
                int g = stod(file[i][j]);
                if (g == 1)
                    st->gender = Gender::MALE;
                else if (g == 2)
                    st->gender = Gender::FEMALE;
                else
                    st->gender = Gender::OTHER;
            } else if (file[0][j] == "day")
                st->dateOfBirth.day = stod(file[i][j]);
            else if (file[0][j] == "month")
                st->dateOfBirth.month = stod(file[i][j]);
            else if (file[0][j] == "year")
                st->dateOfBirth.year = stod(file[i][j]);
            else if (file[0][j] == "username")
                st->username = file[i][j];
            else if (file[0][j] == "social id")
                st->SocialID = file[i][j];
            else if (file[0][j] == "class") {
                Class *cls = findClass(classes, file[i][j]);
                st->cls = cls;
                cls->listOfStudent.addTail(st);
            }
        }
        studentList.addTail(st);
    }
}

void App::loadMemberList() {
    vvs file = readCSV("data/Member.csv");
    for (int i = 1; i < file.size(); i++) {
        auto *mem = new AcademicMember;
        for (int j = 0; j < file[i].size(); j++) {
            if (file[0][j] == "username")
                mem->username = file[i][j];
            else if (file[0][j] == "password")
                mem->password = file[i][j];
        }
        memberList.addTail(mem);
    }
}

void App::readScoreboard() {
    std::ifstream fin;
    fin.open("data/scoreboard.csv");
    if (!fin) {
        fin.close();
        return;
    }
    fin.close();
    vvs file = readCSV("data/scoreboard.csv");
    for (int i = 1; i < file.size(); i++) {
        scoreboard.addTail(Score());
        for (int j = 0; j < file[i].size(); j++) {
            if (file[0][j] == "midterm mark")
                scoreboard.getTail()->data.midtermMark = stod(file[i][j]);
            else if (file[0][j] == "final mark")
                scoreboard.getTail()->data.finalMark = stod(file[i][j]);
            else if (file[0][j] == "total mark")
                scoreboard.getTail()->data.totalMark = stod(file[i][j]);
            else if (file[0][j] == "other mark")
                scoreboard.getTail()->data.otherMark = stod(file[i][j]);
            else if (file[0][j] == "student id")
                scoreboard.getTail()->data.id = file[i][j];
            else if (file[0][j] == "course id")
                scoreboard.getTail()->data.courseId = file[i][j];
            else if (file[0][j] == "student name")
                scoreboard.getTail()->data.name = file[i][j];
        }
    }
}
