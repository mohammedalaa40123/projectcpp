#pragma once
#include "libraries.hpp"

class Faculty
{
    private:
    static inline set<string> f;
    string name;

    public:
    Faculty(string name)
    {
        lower(name);

        if (!exist(name))
        {
            name = "Does Not Exist";
            return;
        }

        this->name = name;
    }

    Faculty() {}

    static bool exist(string name)
    {
        lower(name);
        return f.find(name) != f.end();
    }

    static void addFaculty(string name)
    {
        lower(name);
        f.insert(name);
    }

    static void listFaculties()
    {
        if (f.empty())
        {
            cout << "No Faculties Available";
            return; // cout
        }

        for (auto it = f.begin(); it != f.end(); it++)
        {
            cout << *it << "\n";
        }
    }

    void setFaculty(string f)
    {
        if (!exist(f))
        {
            name = "deleted";
            return;
        }

        name = f;
    }

    friend void fileRead();

    string getFacultyName()
    {
        return name;
    }
};