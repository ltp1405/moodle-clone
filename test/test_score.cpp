#include "Score.h"
#include "../Personnel/Student.h"
#include "Course.h"
#include <iostream>
using namespace std;

int main() {
    Student s;
    s.firstname = "Tung";
    s.id = "21125098";
    Course c;
    c.id = "cs162";

    Score sc = Score(s, c, 9.8, 5.6, 7.8, 6.9);
    cout << sc.student.firstname << " ";
    cout << sc.midtermMark << " ";
    cout << sc.finalMark << " ";
    cout << sc.otherMark << " ";
    cout << sc.finalMark << " ";
    cout << sc.course.id;
}
