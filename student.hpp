#include "libraries.hpp"

class student
{
    string name, id;
    Department department;
    float gpa;
    int no_courses;

    map<string, string> course_grade;
    static inline map<string, student> Students;

    student(string name1, string id1, Department department1, int num_coures1, float gpa1)
    {
        name = name1;
        id = id1;
        department = department1;
        gpa = gpa1;
        no_courses = num_coures1;
    }

    public:
    student() {} // we put this because of error
    student(string id1)
    {
        if (!exist(id1))
        {
            id1 = "Does Not Exist";
            return;
        }

        id = id1;
    }

    static bool exist(string id1)
    {
        return Students.find(id1) != Students.end();
    }

    static void addstudent(string name1, string id1, Department department1, int num_courses, float gpa1)
    {
        int c = 0;

        if (!Department::exist(department1.getName()))
        {
            cout << "department does not exist" << endl;
            c++;
        }

        if (exist(id1))
        {
            cout << "This ID already exists" << endl;
            c++;
        }

        if (c == 0)
        {
            Students[id1] = student(name1, id1, department1, num_courses, gpa1);
        }
    }

    friend void enroll(string, string, string);
    friend void drop(string, string);
    friend void delete_student(string);
    friend void fileRead();

    static void list_students()
    {
        if (Students.empty())
        {
            cout << "There is no students enrolled" << endl;
            return; // cout
        }

        for (auto z = Students.begin(); z != Students.end(); z++)
        {
            cout << z->second.name << endl;
            cout << z->second.id << endl;
            cout << z->second.department.getName() << endl;
            cout << z->second.department.getFacultyName() << endl;
            cout << z->second.gpa << endl;
        }
    }

    static void update_student(string name1, string id1, string department1, int num_courses, float gpa1)
    {
        int c = 0;

        if (!Department::exist(department1))
        {
            cout << department1 << " "
                 << "department does not exist" << endl;
            c++;
        }

        if (!exist(id1))
        {
            cout << "This ID does not exist" << endl;
            c++;
        }

        if (c == 0)
        {
            Students[id1] = student(name1, id1, department1, num_courses, gpa1);
        }
    }
};
