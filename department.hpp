#pragma once
#include "libraries.hpp"

class Department : public Faculty
{
    private:
    string name;
    static inline map<string, Department> Departments;

    Department(string name, string fname) : Faculty(fname)
    {
        lower(name);
        this->name = name;
    }

    public:
    Department(string name)
    {
        lower(name);

        if (!exist(name))
        {
            name = "Department Does Not Exist";
            return;
        }

        this->name = name;
        string f = Departments[name].getFacultyName();
        setFaculty(f);
    }

    Department() {}

    static bool exist(string name)
    {
        lower(name);
        return Departments.find(name) != Departments.end();
    }

    static void addDepartment(string name, string fname)
    {
        lower(name);

        if (exist(name))
        {
            cout << "Department Already Exists" << endl;
            return;
        }

        Departments[name] = Department(name, fname);
    }

    static void listDepartments()
    {
        int i = 1;

        if (Departments.empty())
        {
            cout << "There Are No Departments Available At The Moment" << endl;
            return;
        }

        cout << "The Available Departments Are:" << endl;

        for (auto it : Departments)
        {
            cout << "# department " << i << " : " << it.second.getName() << "from faculty " << it.second.getFacultyName() << endl;
            i += 1;
        }
    }

    string getName()
    {
        if (!exist(name))
        {
            return {"Deleted", "Deleted"};
        }

        return name;
    }

    static void deleteDepartment(string name)
    {
        lower(name);

        if (!exist(name))
        {
            cout << "Can Not Delete Department As It Does Not Exist" << endl;
            return;
        }

        Departments.erase(name);
    }
    
    friend void fileRead();
};