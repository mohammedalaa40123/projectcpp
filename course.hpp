#include "libraries.hpp"

class Course
{
    private:
    string name;

    struct course
    {
        string name;
        string code;
        int noCredits;
        int no_students;
        course(){};

        course(string name, string code, int noCredits, int no_students = 0)
        {
            this->name = name;
            this->code = code;
            this->noCredits = noCredits;
            this->no_students = no_students;
        }
    };

    static inline map<string, course> Courses;

    public:
    Course() {}

    Course(string name)
    {
        lower(name);

        if (!exist(name))
        {
            name = "Does Not Exist";
            return;
        }

        this->name = name;
    }

    static bool exist(string name)
    {
        lower(name);
        return Courses.find(name) != Courses.end();
    }

    static void addCourse(string name, string code, int noCredits, int no_students = 0)
    {
        lower(name);

        if (exist(name))
        {
            cout << "Course already exists, cannot add the same course";
            return;
        }

        Courses[name] = course(name, code, noCredits, no_students);
    }

    static void update_course(string name, string code, int noCredits, int no_students = 0)
    {
        lower(name);

        if (!exist(name))
        {
            // print 7aga
            cout << "This course is not available. Please Add the course.";
            return;
        }

        Courses[name] = course(name, code, noCredits, no_students);
    }

    static void list()
    {
        if (Courses.empty())
        {
            cout << "No Courses Available";
            return; // cout
        }

        for (auto z = Courses.begin(); z != Courses.end(); z++)
        {
            cout << z->first << " " << z->second.code << " " << z->second.noCredits << "\n";
        }
    }

    static void erase(string name)
    {
        lower(name);

        if (!exist(name))
        {
            cout << "Course does not exist";
            return; // cout
        }

        Courses.erase(name);
    }

    string getName() const
    {
        if (!exist(name))
        {
            return "Deleted";
        }

        return name;
    }

    string getCode()
    {
        if (!exist(name))
        {
            return "Deleted";
        }

        return Courses[name].code;
    }

    int getNoCredits()
    {
        if (!exist(name))
        {
            return 0;
        }

        return Courses[name].noCredits;
    }

    int get_no_students()
    {
        if (!exist(name))
        {
            return 0;
        }

        return Courses[name].no_students;
    }

    bool operator<(const Course x) const
    {
        return name < x.name;
    }

    friend void enroll(string, string, string);
    friend void drop(string, string);
    friend void delete_student(string);
    friend void fileRead();
    friend void fileSave();
};