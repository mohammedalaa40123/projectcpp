#include "libraries.hpp"

// 21-101108 Abdelrahman Ahmed Safwat
// 21-101051 Omar Ahmed Rushdy
// 21-101142 Mohammed Alaa
// 21-101015 Karim Abdelhameed
// 21-101147 Bola Yosry

int main()
{
    fileRead();

    string num;
    string in;
    string Eui[] = {
        " _       _       _                                   _             ___   _   _ _     _ \n",
        "( )  _  ( )     (_ )                                ( )_          (  _`\\( ) ( (_)   ( )\n",
        "| | ( ) | |  __  | |   ___   _    ___ ___    __     | ,_)  _      | (_(_| | | | |   | |\n",
        "| | | | | |/'__`\\| | /'___)/'_`\\/' _ ` _ `\\/'__`\\   | |  /'_`\\    |  _)_| | | | |   | |\n",
        "| (_/ \\_) (  ___/| |( (___( (_) | ( ) ( ) (  ___/   | |_( (_) )   | (_( | (_) | |   | |\n",
        "`\\___x___/`\\____(___`\\____`\\___/(_) (_) (_`\\____)   `\\__`\\___/'   (____/(_____(_)   (_)\n",
        "                                                                                    (_)\n"};
    for (auto i : Eui)
    {
        cout << i;
    }

    while (true)
    {
        cout << "Students (press 1)\nFaculties (press 2)\nDepartments (press 3)\nCourses (press 4)\nExit (press 5)" << endl;
        cout << "Which Entity would you like to Access: ";
        cin >> num;

        if (num == "1") // Students
        {
            cout << "\n---------------------------------STUDENTS-------------------------------------\n";
            cout << "1. List all students" << endl;
            cout << "2. Add student" << endl;
            cout << "3. Update student Details" << endl;
            cout << "4. Delete student" << endl;
            cout << "5. List Student Information" << endl;
            cout << "6. Enroll in course" << endl;
            cout << "7. Drop course" << endl;
            cout << "\nChose From the options Above: ";

            string Studentpointer;
            cin >> Studentpointer;

            if (Studentpointer == "1") // Show Students
            {
                cout << "----------------------------Showing Students---------------------------" << endl;
                student::list_students();
            }

            else if (Studentpointer == "2") // Add Student
            {
                cout << "----------------------------Adding Student---------------------------" << endl;
                cout << "please enter student ID: ";
                string ID;
                cin >> ID;

                if (!(student::exist(ID)))
                {
                    cout << "please enter student name: ";
                    string name;
                    scanf(" ");
                    getline(cin, name);
                    cout << "please enter student department: ";
                    string dname;
                    scanf(" ");
                    getline(cin, dname);
                    cout << "please enter student GPA: ";
                    float GPA;
                    cin >> GPA;
                    student::addstudent(name, ID, dname, GPA);
                }

                else
                    cout << "Student Already Exists" << endl;
            }

            else if (Studentpointer == "3") // Update Student
            {
                cout << "----------------------------Updating Student---------------------------" << endl;
                cout << "please enter student ID: ";

                string ID;
                cin >> ID;
                student s(ID);
                string name = s.getName();
                float GPA = s.getGPA();
                string dname = s.getDepartment();

                cout << "Would you like to update the student's name? (y/n): ";
                string ans;
                cin >> ans;

                if (ans == "y" || ans == "Y")
                {
                    cout << "New student name: ";
                    scanf(" ");
                    getline(cin, name);
                }

                cout << "Would you like to update the student's GPA? (y/n): ";
                cin >> ans;

                if (ans == "y" || ans == "Y")
                {
                    cout << "New student GPA: ";
                    cin >> GPA;
                }

                cout << "Would you like to update the student's Department? (y/n): ";
                cin >> ans;

                if (ans == "y" || ans == "Y")
                {
                    cout << "New student Department: ";
                    scanf(" ");
                    getline(cin, dname);
                }

                student::update_student(name, ID, dname, GPA);
            }

            else if (Studentpointer == "4") // Delete Student
            {
                cout << "----------------------------Deleting Student---------------------------" << endl;
                cout << "please enter student ID: ";
                string ID;
                cin >> ID;

                if (!(student::exist(ID)))
                {
                    cout << "Student Does Not Exist" << endl;
                }

                else
                    delete_student(ID);
            }

            else if (Studentpointer == "5") // List Student information
            {
                cout << "----------------------------Listing Student Information---------------------------" << endl;
                cout << "please enter student ID: ";
                string ID;
                cin >> ID;

                if ((student::exist(ID)))
                {
                    cout << "\n------------------------------Student(" << ID << ")---------------------------------\n"
                         << endl;
                    cout << "1. Show Students Name" << endl;
                    cout << "2. Show Students GPA" << endl;
                    cout << "3. Show Students Department" << endl;
                    cout << "4. Show Students no. of Courses" << endl;
                    cout << "5. Show Students List of Courses" << endl;
                    cout << "\nChose From the options Above: ";

                    int ans;
                    cin >> ans;
                    student id(ID);

                    if (ans == 1)
                    {
                        cout << id.getName() << endl;
                    }

                    else if (ans == 2)
                    {
                        cout << id.getGPA() << endl;
                    }

                    else if (ans == 3)
                    {
                        cout << id.getDepartment() << endl;
                    }

                    else if (ans == 4)
                    {
                        cout << id.getNo_courses() << endl;
                    }

                    else if (ans == 5)
                    {
                        id.listCourses();
                    }

                    else cout << "\nInvalid option" << endl;
                }

                else cout << "Student Doesn't exist";
            }

            else if (Studentpointer == "6") // Enrolling in a course
            {
                cout << "----------------------------Enrolling A Course---------------------------" << endl;
                cout << "please enter student ID: ";
                string ID;
                string Course;
                string grade;
                cin >> ID;

                if ((student::exist(ID)))
                {
                    cout << "Enter the course you want to enroll in: ";
                    scanf(" ");
                    getline(cin, Course);
                    cout << "Enter the Grade of the Course: ";
                    cin >> grade;
                    enroll(ID, Course, grade);
                }
                else
                    cout << "Student does not exist" << endl;
            }

            else if (Studentpointer == "7") // Dropping a course
            {
                cout << "----------------------------Dropping A Course---------------------------" << endl;
                cout << "please enter student ID: ";
                string ID;
                string Course;
                cin >> ID;

                if ((student::exist(ID)))
                {
                    cout << "Enter the course you want to Drop: ";
                    scanf(" ");
                    getline(cin, Course);
                    drop(ID, Course);
                }

                else
                    cout << "Student does not exist" << endl;
            }

            else
                cout << "\nInvalid option" << endl;
        }

        else if (num == "2") // Faculties
        {
            cout << "\n---------------------------------FACULTIES-------------------------------------\n";
            cout << "1. Add faculty" << endl;
            cout << "2. List faculties" << endl;
            cout << "\nChose From the options Above: ";

            string Facultypointer;
            cin >> Facultypointer;

            if (Facultypointer == "1")
            {
                cout << "----------------------------Adding Faculty---------------------------" << endl;
                string Fac;
                cout << "Please Enter Faculty Name: ";
                scanf(" ");
                getline(cin, Fac);
                Faculty::addFaculty(Fac);
            }

            else if (Facultypointer == "2")
            {
                cout << "----------------------------Listing Faculties---------------------------" << endl;
                Faculty::listFaculties();
            }
            else
                cout << "\nInvalid option" << endl;
        }

        else if (num == "3") // Departments
        {
            cout << "\n---------------------------------DEPARTMENTS-------------------------------------\n";
            cout << "1. Add department" << endl;
            cout << "2. Delete department" << endl;
            cout << "3. List departments" << endl;
            cout << "\nChose From the options Above: ";

            string Departmentpointer;
            cin >> Departmentpointer;

            if (Departmentpointer == "1")
            {
                cout << "----------------------------Adding Department---------------------------" << endl;
                string Dep, Fac;
                cout << "Please Enter Department Name: ";
                scanf(" ");
                getline(cin, Dep);
                if (!Department::exist(Dep))
                {
                    cout << "Please Enter The Faculty of the Department: ";
                    scanf(" ");
                    getline(cin, Fac);
                    Department::addDepartment(Dep, Fac);
                }
                else cout << "Department already exist" << endl;
            }
            else if (Departmentpointer == "2")
            {
                cout << "----------------------------Deleting Department---------------------------" << endl;
                string Dep;
                cout << "Please Enter Department Name: ";
                scanf(" ");
                getline(cin, Dep);
                Department::deleteDepartment(Dep);
            }
            else if (Departmentpointer == "3")
            {
                cout << "----------------------------Listing Departments---------------------------" << endl;
                Department::listDepartments();
            }

            else cout << "\nInvalid option" << endl;
        }

        else if (num == "4") // Courses
        {
            cout << "\n---------------------------------COURSES-------------------------------------\n";
            cout << "1. Add course" << endl;
            cout << "2. Update course" << endl;
            cout << "3. Delete course" << endl;
            cout << "4. List courses" << endl;
            cout << "5. Get total enrollment" << endl;
            cout << "\nChoose From the options Above: ";

            string Coursepointer;
            cin >> Coursepointer;

            if (Coursepointer == "1") // add course
            {
                string Course, code;
                int no_credits;

                cout << "----------------------------Adding Course---------------------------" << endl;
                cout << "Please Enter Course name You Would Like To Add: ";
                scanf(" ");
                getline(cin, Course);
                cout << "Please Enter Course Code You Would Like To Add: ";
                scanf(" ");
                getline(cin, code);
                cout << "Please Enter The Course's You Would Like To Add no. of credits: ";
                cin >> no_credits;
                Course::addCourse(Course, code, no_credits);
            }

            else if (Coursepointer == "2") // update course
            {
                string course_name;

                cout << "----------------------------Updating Course---------------------------" << endl;
                cout << "please enter the course name you want to update: ";
                scanf(" ");
                getline(cin, course_name);

                if (!Course::exist(course_name))
                {
                    cout << "This course is not available. Please Add the course.";
                }

                else
                {
                    Course c(course_name);
                    string course_code = c.getCode();
                    int num_credits = c.getNoCredits();
                    int num_students = c.get_no_students();
                    string ans;

                    cout << "Would you like to update the course's code? (y/n): ";
                    cin >> ans;

                    if (ans == "y" || ans == "Y")
                    {
                        cout << "please write the new course code: ";
                        cin >> course_code;
                    }

                    cout << "Would you like to update the course's number of credits? (y/n): ";
                    cin >> ans;

                    if (ans == "y" || ans == "Y")
                    {
                        cout << "please write the new course's number of credits: ";
                        cin >> num_credits;
                    }

                    Course::update_course(course_name, course_code, num_credits, num_students);
                }
            }

            else if (Coursepointer == "3") // delete course
            {
                string Course;
                cout << "----------------------------Deleting Course---------------------------" << endl;
                cout << "Please Enter Coure name You Would Like To Delete: ";
                scanf(" ");
                getline(cin, Course);
                Course::erase(Course);
            }

            else if (Coursepointer == "4") // list courses
            {
                cout << "----------------------------Listing Courses---------------------------" << endl;
                Course::listCourses();
            }

            else if (Coursepointer == "5") // Get total enrollment
            {
                string course;
                cout << "----------------------------Total Enrollment ---------------------------" << endl;
                cout << "Please Enter The Course Name: ";
                scanf(" ");
                getline(cin, course);
                Course c(course);
                cout << c.get_no_students() << endl;
            }
            else
                cout << "\nInvalid option" << endl;
        }

        else if (num == "5") // Exit
        {
            cout << "\nThank You For Visiting EUI\n";
            break;
        }

        else // entered an Invalid option
        {
            cout << "\nInvalid Option";
        }

        cout << "Would You Like To Contiue? (y/n): ";
        cin >> in;

        if (in != "y" && in != "Y")
        {
            cout << "\nThank You For Visiting EUI\n";
            break;
        }
    }

    fileSave();
}