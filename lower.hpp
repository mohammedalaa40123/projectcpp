#pragma once
#include "libraries.hpp"

void lower(string &name)
{
    for (int i = 0; i < name.size(); i++)
    {
        if (isalpha(name[i]) && isupper(name[i]))
            name[i] = tolower(name[i]);
    }
}