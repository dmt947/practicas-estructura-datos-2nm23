#include "Digraph.h"

Digraph::Digraph() : Graph() {}

Digraph::~Digraph() {}

bool Digraph::connectNodes(const char* from, const char* to, const char* via)
{
    Node* org = findNode(from);
    Node* dest = findNode(to);
    Edge* edge = findEdge(via);

    if(org == nullptr || dest == nullptr || edge == nullptr)
    {
        return false;
    }

    Connection* departure = new Connection(org, dest, edge);
    connections.add(departure, connections.longitud());

    return true;
}
