#pragma once
#include <libraries.hpp>
void enroll(string studentID, string courseName, string grade)
{
    if (!Course::exist(courseName))
    {
        cout << "This course does not exist;" << endl;
        return;
    }

    Course::Courses[courseName].no_students++;
    student::Students[studentID].course_grade[courseName] = grade;
    student::Students[studentID].no_courses++;
}

void drop(string studentID, string courseName)
{
    if (!Course::exist(courseName))
    {
        cout << "This course does not exist;" << endl;
        return;
    }

    Course::Courses[courseName].no_students--;
    student::Students[studentID].course_grade.erase(courseName);
    student::Students[studentID].no_courses--;
}

void delete_student(string id1)
{
    if (!student::exist(id1))
    {
        cout << "This ID does not exist" << endl;
        return; // cout
    }

    for (auto z = student::Students[id1].course_grade.begin(); z != student::Students[id1].course_grade.end(); z++)
    {
        drop(id1, z->first);
    }

    student::Students.erase(id1);
}