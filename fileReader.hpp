#pragma once
#include "libraries.hpp"

void fileRead()
{
    ifstream file("txts\\faculties.txt");

    if (!file.is_open())
    {
        cout << "Error opening file" << endl;
        return;
    }

    string line;

    while (getline(file, line))
    {
        Faculty::addFaculty(line);
    }

    file.close();

    ifstream file2("txts\\departments.txt");

    if (!file2.is_open())
    {
        cout << "Error opening file" << endl;
        return;
    }

    while (getline(file2, line))
    {
        stringstream lineStream(line);

        string key;
        string value;

        getline(lineStream, key, ',');
        lineStream >> value;
        Department::addDepartment(key, value);
    }

    file2.close();

    ifstream file3("txts\\courses.txt");

    if (!file3.is_open())
    {
        cout << "Error opening file" << endl;
        return;
    }

    while (getline(file3, line))
    {
        stringstream lineStream(line);

        string name;
        string code;
        int noCredits;
        int no_students;

        getline(lineStream, name, ',');
        getline(lineStream, code, ',');
        lineStream >> noCredits;

        Course::addCourse(name, code, noCredits);
    }

    file3.close();

    ifstream file4("txts\\student.txt");

    if (!file4.is_open())
    {
        cout << "Error opening file" << endl;
        return;
    }

    while (getline(file4, line))
    {
        stringstream lineStream(line);

        string name, id, dep;
        Department department;
        float gpa;
        int no_courses;

        getline(lineStream, name, ',');
        getline(lineStream, id, ',');
        getline(lineStream, dep, ',');
        lineStream >> gpa;
        // lower(dep);
        // Department d = Department::Departments[dep];

        student::addstudent(name, id, dep, gpa);
    }
    file4.close();

    ifstream file5("txts\\grades.txt");

    if (!file5.is_open())
    {
        cout << "Error opening file" << endl;
        return;
    }

    while (getline(file5, line))
    {
        stringstream lineStream(line);

        string ID;
        string Course;
        string grade;

        getline(lineStream, ID, ',');
        getline(lineStream, Course, ',');
        lineStream >> grade;

        student x(ID);

        if (x.course_grade.find(Course) == x.course_grade.end())
        {
            enroll(ID, Course, grade);
        }
    }

    file5.close();
}