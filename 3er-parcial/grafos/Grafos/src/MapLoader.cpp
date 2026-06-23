#include "MapLoader.h"
#include <iostream>

bool MapLoader::stringsEqual(const char* s1, const char* s2)
{
    if(s1 == nullptr || s2 == nullptr)
    {
        return false;
    }
    int i = 0;
    while(s1[i] != '\0' && s2[i] != '\0')
    {
        if(s1[i] != s2[i])
        {
            return false;
        }
        i++;
    }
    return s1[i] == s2[i];
}

char* MapLoader::dupString(const char* src)
{
    if (src == nullptr) return nullptr;
    int len = 0;
    while (src[len] != '\0') len++;
    char* dest = new char[len + 1];
    for (int i = 0; i < len; i++)
    {
        dest[i] = src[i];
    }
    dest[len] = '\0';
    return dest;
}

MapLoader::MapLoader() {}

MapLoader::~MapLoader() {}
