#include "LinkedList.h"
#include <string>
using namespace std;

struct Student {
    string name;
    double mark;

    Student(string name, double mark) {
        this->name = name;
        this->mark= mark;
    }

    Student() {
        name = "";
        mark = 0.f;
    }

    void print() {
        cout << "Name: " << name << endl;
        cout << "Mark: " << mark << endl;
    }
};

void print(const Student &s) {
    cout << "Name: " << s.name << endl;
    cout << "Mark: " << s.mark << endl;
}

int main() {
    auto s = LinkedList<Student>();
    double marks[] = { 4.5, 6.5, 7.9, 4.8, 9.1 };
    string names[] = { "Nguyen Van A", "Nguyen Van B", "Nguyen Van C", "Nguyen Van D", "Nguyen Van E" };
    for (int i = 0; i < 5; i++) {
        auto student = Student(names[i], marks[i]);
        s.addTail(student);
    }
    s.printList(&Student::print);

    return 0;
}
