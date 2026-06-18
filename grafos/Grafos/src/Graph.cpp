#include "Graph.h"

bool Graph::stringsEqual(const char* s1, const char* s2) const
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
Graph::Graph() {}

Graph::~Graph()
{
    while(!connections.vacia())
    {
        Connection* conn = connections.remove(0);
        delete conn;
    }

    while(!edges.vacia())
    {
        Edge* e = edges.remove(0);
        delete e;
    }

    while(!nodes.vacia())
    {
        Node* n = nodes.remove(0);
        delete n;
    }
}

Node* Graph::findNode(const char* name) const
{
    int len = nodes.longitud();
    for(int i = 0; i < len; i++)
    {
        Node* current = nodes.get(i);
        if(stringsEqual(current->getName(), name))
        {
            return current;
        }
    }
    return nullptr;
}

Edge* Graph::findEdge(const char* name) const
{
    int len = edges.longitud();
    for(int i = 0; i < len; i++)
    {
        Edge* current = edges.get(i);
        if(stringsEqual(current->getName(), name))
        {
            return current;
        }
    }
    return nullptr;
}

bool Graph::addNode(const char* name)
{
    if(name == nullptr || findNode(name) != nullptr)
    {
        return false;
    }

    Node* newNode = new Node(name);

    return nodes.add(newNode, nodes.longitud());
}

bool Graph::addEdge(const char* name, double time, double cost)
{
    if(name == nullptr || findEdge(name) != nullptr)
    {
        return false;
    }

    Edge* newEdge = new Edge(name, time, cost);

    return edges.add(newEdge, edges.longitud());
}

bool Graph::connectNodes(const char* from, const char* to, const char* via)
{
    Node* org = findNode(from);
    Node* dest = findNode(to);
    Edge* edge = findEdge(via);

    if(org == nullptr || dest == nullptr || edge == nullptr)
    {
        return false;
    }

    Connection* departure = new Connection(org, dest, edge);
    Connection* back = new Connection(dest, org, edge);
    connections.add(departure, connections.longitud());
    connections.add(back, connections.longitud());

    return true;
}

const Lista<Node*>& Graph::getNodes() const
{
    return nodes;
}

const Lista<Edge*>& Graph::getEdges() const
{
    return edges;
}

const Lista<Connection*>& Graph::getConnections() const
{
    return connections;
}

bool Graph::hasIncomingConnection(const char* nodeName) const
{
    int len = connections.longitud();
    for(int i = 0; i < len; i++)
    {
        if(stringsEqual(connections.get(i)->getDest()->getName(), nodeName))
        {
            return true;
        }
    }
    return false;
}
