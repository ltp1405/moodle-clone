# Requirements
CS162 - Programming Techniques – Final Project – A Course Registration System

There are 2 types of users in the system.
- Academic staff members, for example, Ms. Le Thi Anh Thao, Ms. Nguyen Thi Minh Phuc, Ms. Hoang Thanh Tu…
- Students: in APCS, CLC, VP…

He/she has to log in to the system.
Then, he/she can view his/her profile info, change password, or log out of the system

### At the beginning of a school year (often in September), an academic staff member will:
- Create a school year (2020-2021, for example)
- Create several classes for 1st year students. For example: class 20APCS1,
class 20APCS2, class 20CLC1…, class 20CLC11, class 20VP…
- Add new 1st year students to 1st-year classes.
- For quick input, he/she can import a CSV file containing all students
in a specific class to the system, instead of adding one by one:
No, Student ID, First name, Last name, Gender, Date of Birth, Social ID.
- He/she does not need to add 2nd year, 3rd year, or 4th-year students, because
these students had been added in the previous years.

### There are 3 semesters in a school year:
- Semester 1 (Fall)
- Semester 2 (Summer)
- Semester 3 (Autumn)

### At the beginning of a semester, an academic staff member will:
- Create a semester: 1, 2, or 3, school year, start date, end date. Choose the
school year that the newly created semester belongs to. The created semester will
be the current / the default semester for all the below actions.
- Create a course registration session: start date, end date.
- Add a course to this semester: course id, course name, teacher name,
number of credits, the maximum number of students in the course (default 50),
day of the week, and the session that the course will be performed
(MON / TUE / WED / THU / FRI / SAT, S1 (07:30), S2 (09:30), S3(13:30)
and S4 (15:30)). A course will be taught in 2 sessions in a week.
- View the list of courses.
- Update course information.
- Delete a course.

### When a course registration session is active, a student can:
- Log in to the system, of course.
- Enroll in a course. If 2 sessions of the new course are conflicted with
existing enrolled course sessions, he/she can not enroll in it.
He/she can enroll in at most 5 courses in a semester.
- View a list of enrolled courses.
- Remove a course from the enrolled list.

### When a course registration session is close, a student still can:
- View a list of his/her courses. He/she will study these courses in this semester.

### At any time, an academic staff member can:
- View a list of classes.
- View a list of students in a class (for example, 20APCS1…)
- View a list of courses.
- View a list of students in a course

### At the end of a semester, an academic staff member can:
- Export a list of students in a course to a CSV file
- Import the scoreboard of a course. A scoreboard will have at least
the following columns: No, Student ID, Student Full Name, Total Mark,
Final Mark, Midterm Mark, Other Mark. (An academic staff member will
export the list of students in a course, send the CSV file to the
teacher, the teacher will enter student results in this file,
send it back to the staff, and then the staff will import the
scoreboard to the system)
- View the scoreboard of a course.
<!-- - Update a student result. -->
- View the scoreboard of a class, including final marks of all courses
in the semester, GPA in this semester, and the overall GPA.

### When the scoreboard has been published (by the academic staff member), a student can:
- View his/her scoreboard.

## Technical requirements
- The text files, the binary files are ok. The databases are not allowed.
- C++ language.
- Only linked lists are allowed.
- char[], char*, and string are allowed.
- Use Git to control your source code versions. Each member must have at least 20 commits and
must spread on at least 15 different days. https://youtu.be/cz-ymVblUgM  

## Submission
- Source code.
- User manual videos, uploaded to Youtube as a playlist.
- A list of tasks had been done by each member in the group.
