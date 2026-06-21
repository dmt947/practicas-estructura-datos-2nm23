#include "Tree.h"
#include <iostream>

Tree::Tree() : Graph() {}

Tree::~Tree() {}

bool Tree::connectNodes(const char* from, const char* to, const char* via)
{
    if (stringsEqual(from, to))
    {
        std::cerr << "[TREE ERROR]: Un arbol no permite bucles (" << from << " -> " << to << ")." << std::endl;
        return false;
    }

    Node* org = findNode(from);
    Node* dest = findNode(to);
    Edge* edge = findEdge(via);

    if(org == nullptr || dest == nullptr || edge == nullptr)
    {
        return false;
    }

    if (hasIncomingConnection(to))
    {
        std::cerr << "[TREE ERROR]: El nodo '" << to << "' ya tiene un padre." << std::endl;
        return false;
    }

    Connection* departure = new Connection(org, dest, edge);
    connections.add(departure, connections.longitud());

    return true;
}
