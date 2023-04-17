#include "libraries.hpp"

class student
{
    string name, id;//name and id of student
    Department department;//this is an object of type department as an attribute of student
    float gpa;
    int no_courses;
    map<Course, string> course_grade;//this is a map data structures we use this data structure to access a course grade through the Course object as we use it as an index 

    static inline map<string, student> Students;

    student(string name1, string id1, Department department1, int num_coures1, float gpa1)//this is the constructor of student and we make it private to avoid changes that may contradict other attributes for example we may change the number of courses without having the number of couses really as written
    {
        name = name1;
        id = id1;
        department = department1;
        gpa = gpa1;
        no_courses = num_coures1;
    }

    public:
    student() {}//we use this to avoid error as the map Students takes the key string and the value student and this is a default contructor ,so we need this constructor 
    student(string id1)//single argument constructor
    {
        if (!exist(id1))//here when we initialize an object of our class to operate on this object has to have an id that exists in the database otherise the error message is displayed 
        {
            id1 = "Does Not Exist";//error message
            return;
        }

        id = id1;
    }

    static bool exist(string id1)//A function that checks whether the given id exists on our database or not
    {
        return Students.find(id1) != Students.end();
    }

    static void addstudent(string name1, string id1, Department department1, float gpa1, int num_courses = 0)//This is a function that adds a student 
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
    friend void fileSave();

    static void list_students()
    {
        if (Students.empty())
        {
            cout << "There are no students enrolled" << endl;
            return; // cout
        }

        bool deleted = false;
        vector<student> garbage;

        for (auto z = Students.begin(); z != Students.end(); z++)
        {
            cout << z->second.name << endl;
            cout << z->second.id << endl;
            string department = z->second.department.getName();

            if (department == "deleted")
            {
                garbage.push_back(z->second);
                deleted = true;
            }

            cout << z->second.department.getFacultyName() << endl;
            cout << z->second.gpa << endl;
        }

        if (deleted)
        {
            cout << "some students are a part of departments that no longer exist, ";
            cout << "would you like to delete them ? (y/n): ";
            string ans;
            cin >> ans;

            if (ans == "y")
            {
                for (auto i : garbage)
                {
                    Students.erase(i.id);
                }

                cout << "done!\n";
            }
        }
    }

    static void update_student(string name1, string id1, string department1, float gpa1)
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
            Students[id1] = student(name1, id1, department1, Students[id1].no_courses, gpa1);
        }
    }

    void listCourses()
    {
        if (Students[id].course_grade.empty())
        {
            cout << "this student is not enrolled in any courses yet!\n";
            return;
        }

        bool deleted = false;
        vector<Course> garbage;

        cout << "Course name - grade:\n";

        for (auto i : Students[id].course_grade)
        {
            string course = i.first.getName();

            if (course == "Deleted")
            {
                garbage.push_back(i.first);
                deleted = true;
            }

            cout << course << " - " << i.second << "\n";
        }

        if (deleted)
        {
            cout << "this student is enrolled in some deleted courses, ";
            cout << "would you like to delete them ? (y/n): ";
            string ans;
            cin >> ans;

            if (ans == "y")
            {
                for (auto i : garbage)
                {
                    Students[id].course_grade.erase(i);
                    Students[id].no_courses--;
                }

                cout << "done!\n";
            }
        }
    }

    string getName()
    {
        if (!exist(id))
        {
            return "deleted";
        }

        return Students[id].name;
    }

    string getDepartment()
    {
        if (!exist(id))
        {
            return "unknown";
        }

        return Students[id].department.getName();
    }

    string getFaculty()
    {
        if (!exist(id))
        {
            return "unknown";
        }

        return Students[id].department.getFacultyName();
    }

    int getNo_courses()
    {
        if (!exist(id))
        {
            return 0;
        }

        return Students[id].no_courses;
    }

    float getGPA()
    {
        if (!exist(id))
        {
            return 0.00;
        }

        return Students[id].gpa;
    }
};