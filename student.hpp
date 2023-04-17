#include "libraries.hpp"

class student
{
    string name, id;       // name and id of student
    Department department; // this is an object of type department as an attribute of student
    float gpa;
    int no_courses;
    map<Course, string> course_grade; // this is a map data structures we use this data structure to access a course grade through the Course object as we use it as an index

    static inline map<string, student> Students; // this is a static map that is common between all student objects and we use inline to initialize it to be empty and its key is a string which is the id of the student and its value is the student object

    student(string name1, string id1, Department department1, int num_coures1, float gpa1) // this is the constructor of student and we make it private to avoid changes that may contradict other attributes for example we may change the number of courses without having the number of couses really as written
    {
        name = name1;
        id = id1;
        department = department1;
        gpa = gpa1;
        no_courses = num_coures1;
    }

    public:
    student() {}        // we use this to avoid error as the map Students takes the key string and the value student and this is a default contructor ,so we need this constructor
    student(string id1) // single argument constructor
    {
        if (!exist(id1)) // here when we initialize an object of our class to operate on this object has to have an id that exists in the database otherise the error message is displayed
        {
            id1 = "Does Not Exist"; // error message
            return;
        }

        id = id1;
    }

    static bool exist(string id1) // A function that checks whether the given id exists on our database or not
    {
        return Students.find(id1) != Students.end();
    }

    static void addstudent(string name1, string id1, Department department1, float gpa1, int num_courses = 0) // This is a function that adds a student to database
    {
        int c = 0; // c is the error counter

        if (!Department::exist(department1.getName())) // this checks whether the department given exists or not
        {
            cout << "department does not exist" << endl; // error message
            c++;
        }

        if (exist(id1)) // this checks if the id already exists to avoid duplication of ids
        {
            cout << "This ID already exists" << endl;
            c++;
        }

        if (c == 0) // if the error counter is zero ie there is no errors the operation will be executed
        {
            Students[id1] = student(name1, id1, department1, num_courses, gpa1);
        }
    }

    friend void enroll(string, string, string); // we use this friend function to modify private attributes in student and Course classes
    friend void drop(string, string);           // we use this friend function to modify private attributes in student and Course classes
    friend void delete_student(string);         // we use this friend function to modify private attributes in student and Course classes
    friend void fileRead();                     // we use this friend function to access all classes and write the data of the file into them
    friend void fileSave();                     // we use this friend function to access all classes and write their data into a file

    static void list_students() // we use this function to list all students in our database
    {
        if (Students.empty()) // this checks whether the map is empty or not
        {
            cout << "There are no students enrolled" << endl;
            return; // cout
        }

        bool deleted = false;    // we use this bool variable to check whether a student is in a department that is deleted
        vector<student> garbage; // this is a garbage vector that collects students that are not enrolled in a department

        for (auto z = Students.begin(); z != Students.end(); z++)
        {
            cout << z->second.name << endl;
            cout << z->second.id << endl;
            string department = z->second.department.getName();

            if (department == "deleted") // we use this case as a student may be enrolled in a department and later on this department is deleted ,so we use this condition to check whether this department is deleted
            {
                garbage.push_back(z->second); // if the department is deleted we add the student to the  garbage vector
                deleted = true;
            }

            cout << department << endl;
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
                    for (auto it : i.course_grade)
                    {
                        Course c(it.first.getName());
                        Course::update_course(c.getName(), c.getCode(), c.getNoCredits(), c.get_no_students() - 1);
                    } // before erasing a student form the map we need to decrement the number of students enrolled in each course the student is enrolled in as this student will be removed

                    Students.erase(i.id); // here we delete students that are not enrolled in a department
                }

                cout << "done!\n";
            }
        }
    }

    static void update_student(string name1, string id1, string department1, float gpa1) // we use this function to update student's information
    {
        int c = 0; // this is an error counter

        if (!Department::exist(department1)) // this checks whether the department that we insert in the update exists or not
        {
            cout << department1 << " "
                 << "department does not exist" << endl;
            c++;
        }

        if (!exist(id1)) // this checks whethter the id of the student whose information will be updated exists or not
        {
            cout << "This ID does not exist" << endl;
            c++;
        }

        if (c == 0) // if the error counter is zero ie there is no errors the operation will be executed
        {
            Students[id1] = student(name1, id1, department1, Students[id1].no_courses, gpa1);
        }
    }

    void listCourses() // this is used to list courses of a student
    {
        if (Students[id].course_grade.empty()) // this checks if the student is enrolled in any course or not
        {
            cout << "this student is not enrolled in any courses yet!\n";
            return;
        }

        bool deleted = false;   // this is a bool variable that checks whether a given course is deleted or not
        vector<Course> garbage; // this is a garbage vector that collects all courses that are deleted

        cout << "Course name - grade:\n";

        for (auto i : Students[id].course_grade)
        {
            string course = i.first.getName();

            if (course == "Deleted")
            {
                garbage.push_back(i.first); // if the course is found to be deleted it will be added to the garbage
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
                for (auto i : garbage) // this loops on the deleted courses of the student(garbage) and erases them
                {
                    Students[id].course_grade.erase(i);
                    Students[id].no_courses--;
                }

                cout << "done!\n";
            }
        }
    }
    // the following functions are getters for the attributes of the object

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