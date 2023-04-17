#pragma once
#include "libraries.hpp"

class Department : public Faculty
{
    private:
    string name;
    static inline map<string, Department> Departments;

    Department(string name, string fname) : Faculty(fname) // constructor that calls the constructor of the base class(Faculty)
    {
        lower(name);
        this->name = name;
    }

    public:
    Department(string name) // one argument constructor
    {
        lower(name);

        if (!exist(name)) // if department does not exist
        {
            name = "Department Does Not Exist";
            return;
        }

        this->name = name; // set department name to the passed string
    }

    Department() {} // default constructor

    static bool exist(string name) // checks if the department exists
    {
        lower(name);
        return Departments.find(name) != Departments.end();
    }

    static void addDepartment(string name, string fname) // member to add a department
    {
        lower(name);

        if (exist(name)) // checks if the department exists
        {
            cout << "Department Already Exists" << endl;
            return;
        }

        Departments[name] = Department(name, fname); // if it doesn't exist it gets stored in the map
    }

    static void listDepartments() // member to show the departments
    {
        int i = 1;

        if (Departments.empty()) // checks if the department does not exist
        {
            cout << "There Are No Departments Available At The Moment" << endl; // prints it does not exist
            return;
        }

        cout << "The Available Departments Are:" << endl; // if there exists at least a department

        for (auto it : Departments) // it loops along the map using the iterator
        {
            cout << "# department " << i << " : " << it.first << " from faculty " << it.second.getFacultyName() << endl;
            i += 1;
        }
    }

    string getName() // member to get the department name
    {
        if (!exist(name)) // if that department does not exist
        {
            return "deleted"; // returns deleted
        }

        return name; // if department exists, it returns department
    }

    string getFacultyName() // member to get faculty name
    {
        if (!exist(name)) // if department does not exists
        {
            return "unknown"; // return unknown
        }

        return Departments[name].Faculty::getFacultyName(); // else get the faculty of the department using overriding
    }

    static void deleteDepartment(string name) // member to delete department
    {
        lower(name);

        if (!exist(name)) // if department does not exist
        {
            cout << "Can Not Delete Department As It Does Not Exist" << endl;
            return;
        }

        Departments.erase(name); // else delete the department
    }

    friend void fileRead(); // File Reader to read from the .txt files
    friend void fileSave(); // File Saver to write to the .txt files
};