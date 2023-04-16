#pragma once
#include "libraries.hpp"

class Faculty
{
    private:
    static inline set<string> faculties;
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
        return faculties.find(name) != faculties.end();
    }

    static void addFaculty(string name)
    {
        lower(name);
        faculties.insert(name);
    }

    static void listFaculties()
    {
        if (faculties.empty())
        {
            cout << "No Faculties Available";
            return; // cout
        }

        for (auto it = faculties.begin(); it != faculties.end(); it++)
        {
            cout << *it << "\n";
        }
    }

    friend void fileRead();
    friend void fileSave();

    string getFacultyName()
    {
        return name;
    }
};