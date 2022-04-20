#include "utils/LinkedList.h"
#include "School/Course.h"
#include "Personnel/Student.h"
using namespace std;

int main() {
    Student s1 = Student("A", "Nguyen Van", "21125152", Gender::MALE);
    Student s2 = Student("B", "Phan Thi", "21125185", Gender::FEMALE);
    Student s3 = Student("C", "Nguyen Thi", "21125129", Gender::OTHER);

    LinkedList<Course> courses;
    Course c1 = Course("CS162", "Computer Science", 4, 60, "Tung");
    Course c2 = Course("CS163", "Computer Science", 4, 60, "Tung2");
    Course c3 = Course("CS164", "Computer Science", 4, 60, "Tung3");
    c1.students.addTail(s1);
    c1.students.addTail(s3);
    // c2.students.addHead(s2);
    // c2.students.addHead(s3);
    // c3.students.addHead(s1);
    // c3.students.addHead(s2);

    courses.addTail(c1);
    courses.addTail(c2);
    courses.addTail(c3);

    courses.printList(&Course::print);
}
