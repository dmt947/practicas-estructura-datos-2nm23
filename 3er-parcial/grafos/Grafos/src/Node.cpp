#include "Node.h"

Node::Node(const char* n)
{
    name = nullptr;
    setName(n);
}

Node::~Node()
{
    if(name != nullptr)
    {
        delete[] name;
    }
}

const char* Node::getName() const
{
    return name;
}

void Node::setName(const char *n)
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
    name[len] = '\0';
}
