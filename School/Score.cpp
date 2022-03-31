#include "Score.h"

Score::Score(Student student, Course course, double midtermMark,
             double finalMark, double otherMark, double totalMark) {
  this->id = student.id;
  this->courseId = course.id;
  this->name = student.firstname + " " + student.lastname;
  this->midtermMark = midtermMark;
  this->finalMark = finalMark;
  this->otherMark = otherMark;
  this->totalMark = totalMark;
}

Score::Score(string id, string name, string courseId, double midtermMark, double finalMark, double otherMark, double totalMark) {
    this->id = id;
    this->name = name;
    this->courseId = courseId;
    this->midtermMark = midtermMark;
    this->finalMark = finalMark;
    this->otherMark = otherMark;
    this->totalMark = totalMark;
}
