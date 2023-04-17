#pragma once
#include "libraries.hpp"

void fileSave()
{
    ofstream filefaculty("txts\\faculties.txt");

    for (auto i : Faculty::faculties)
    {
        filefaculty << i << endl;
    }
    filefaculty.close();

    ofstream filedepartment("txts\\departments.txt");

    for (auto i : Department::Departments)
    {
        filedepartment << i.first << "," << i.second.getFacultyName() << endl;
    }
    filedepartment.close();

    ofstream filecourse("txts\\courses.txt");

    for (auto i : Course::Courses)
    {
        filecourse << i.first << "," << i.second.code << "," << i.second.noCredits << endl;
    }
    filecourse.close();

    ofstream filestudent("txts\\student.txt");

    for (auto i : student::Students)
    {
        filestudent << i.second.name << "," << i.second.id << "," << i.second.department.getName() << "," << i.second.gpa << endl;
    }
    filestudent.close();

    ofstream filesgrades("txts\\grades.txt");

    for (auto i : student::Students)
    {
        for (auto k : i.second.course_grade)
        {
            filesgrades << i.first << "," << k.first.getName() << "," << k.second << endl;
        }
    }
    filesgrades.close();
}