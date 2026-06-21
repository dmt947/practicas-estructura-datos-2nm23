#include "Edge.h"

Edge::Edge(const char* n, double t, double c)
{
    name = nullptr;
    setName(n);
    setTime(t);
    setCost(c);
}

Edge::~Edge()
{
    if(name != nullptr)
    {
        delete[] name;
    }
}

const char* Edge::getName() const
{
    return name;
}

double Edge::getTime() const
{
    return time;
}

double Edge::getCost() const
{
    return cost;
}

void Edge::setName(const char* n)
{
    if(n == nullptr)
    {
        return;
    }

    if(name != nullptr)
    {
        delete[] name;
    }
    int len;
    for(len = 0; n[len] != '\0'; len++);
    name = new char[len + 1];
    for(int i = 0; i < len; i++)
    {
        name[i] = n[i];
    }
    if(n == nullptr)
    {
        return;
    }
    name[len] = '\0';
}

void Edge::setTime(double t)
{
    time = t;
}

void Edge::setCost(double c)
{
    cost = c;
}
