#pragma once
#include "libraries.hpp"

class Faculty
{
    private:
    static inline set<string> faculties; // A static set to store faculties to be accessed only by class and be seen by all objects
    string name;

    public:
    Faculty(string name)
    {
        lower(name);

        if (!exist(name))// check if the faculty the object tries to reach exists in the static set
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
        return faculties.find(name) != faculties.end();// find the faculty name in set of faculties if doesn't exist returns iterator to faculties.end()
    }

    static void addFaculty(string name)
    {
        lower(name);
        faculties.insert(name); // insert new faculty in static set
    }

    static void listFaculties()
    {
        if (faculties.empty())//checks if faculties set is empty
        {
            cout << "No Faculties Available";
            return; // cout
        }

        for (auto it = faculties.begin(); it != faculties.end(); it++)// print faculty names using iterators
        {
            cout << *it << "\n";
        }
    }
    // friend functions are used to access private data in faculty class
    friend void fileRead();
    friend void fileSave();

    string getFacultyName()
    {
        return name;
    }
};