#include "../Personnel/Student.h"
#include "Course.h"

struct Score { 
    double totalMark;
    double finalMark;
    double midtermMark;
    double otherMark;

    string id;
    string name;
    string courseId;

    Score() {}
    Score(Student student, Course course, double midtermMark, double finalMark, double otherMark, double totalMark);
    Score(string id, string name, string courseId, double m, double f, double o, double t);
};
