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

    static inline map<string, course> Courses; // A static map to store courses to be accessed only by class and be seen by all objects

    public:
    Course() {}

    Course(string name)
    {
        lower(name);

        if (!exist(name)) // check if the course which is  the object tries to reach exists in the static set
        {
            name = "Does Not Exist";
            return;
        }

        this->name = name;
    }

    static bool exist(string name) // find the course name in map of courses if it doesn't exist returns iterator to faculties.end()
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

        Courses[name] = course(name, code, noCredits, no_students); // insert new course in static map
    }

    static void update_course(string name, string code, int noCredits, int no_students = 0)
    {
        Courses[name] = course(name, code, noCredits, no_students); // updates the course details in the static map
    }

    static void listCourses() 
    {
        if (Courses.empty()) //checks if courses map is empty
        {
            cout << "No Courses Available";
            return; // cout
        }

        for (auto z = Courses.begin(); z != Courses.end(); z++) //loop over the static map and cout the contents
        {
            cout << z->first << " " << z->second.code << " " << z->second.noCredits << "\n";
        }
    }

    static void erase(string name)// erase the wanted course from the static map
    {
        lower(name);

        if (!exist(name))
        {
            cout << "Course does not exist";
            return; // cout
        }

        Courses.erase(name);
    }

    string getName() const // const because at some point we had an iterator over a map which led to this iterator being const of our class and const objects require const fucntions
    {
        if (!exist(name))
        {
            return "Deleted";
        }

        return name; 
    }

    string getCode()// simple getter that returns the course code from the static map not from an object of the class
    {
        if (!exist(name))
        {
            return "Deleted";
        }

        return Courses[name].code;
    }

    int getNoCredits() // simple getter that returns the course credits from the static map not from an object of the class
    {
        if (!exist(name))
        {
            return 0;
        }

        return Courses[name].noCredits;
    }

    int get_no_students() // simple getter that returns the number of students in a course from the static map not from an object of the class
    {
        if (!exist(name))
        {
            return 0;
        }

        return Courses[name].no_students;
    }

    bool operator<(const Course x) const // this is mainly useful for map<Course, grade> used inside student class, since maps need to compare between elements (these operations are done in logarithmic time)
    {
        return name < x.name;
    }

    friend void enroll(string, string, string);// enroll, drop, and delete need to access class Student, Course.
    friend void drop(string, string);
    friend void delete_student(string);
    friend void fileRead();// The file functions need to access all classes.
    friend void fileSave();
};