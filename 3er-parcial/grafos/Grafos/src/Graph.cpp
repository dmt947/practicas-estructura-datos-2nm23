#include "Graph.h"
#include <iostream>

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

    if(stringsEqual(from, to))
    {
        Connection* loop = new Connection(org, dest, edge);
        connections.add(loop, connections.longitud());
    }
    else
    {
        Connection* departure = new Connection(org, dest, edge);
        Connection* back = new Connection(dest, org, edge);
        connections.add(departure, connections.longitud());
        connections.add(back, connections.longitud());
    }

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

bool Graph::removeNode(const char* name)
{
    Node* node = findNode(name);
    if(node == nullptr)
    {
        return false;
    }
    for(int i = 0; i<connections.longitud(); i++)
    {
        Connection* conn = connections.get(i);
        if(conn->getOrg() == node || conn->getDest()==node)
        {
            delete connections.remove(i);
            i--;

        }
    }

    for(int i = 0; i<nodes.longitud(); i++)
    {
        if(nodes.get(i) == node)
        {
            delete nodes.remove(i);
            return true;
        }
    }
}

bool Graph::removeEdge(const char* name)
{
    Edge* edge = nullptr;
    int iE = -1;
    for(int i = 0; i <edges.longitud(); i++)
    {
        if(stringsEqual(edges.get(i)->getName(), name))
        {
            edge = edges.get(i);
            iE = i;
            break;
        }
    }
    if(edge == nullptr)
    {
        return false;
    }

    for(int i = 0; i <connections.longitud(); i++)
{
    Connection* conn = connections.get(i);
        if(conn->getEdge() == edge)
        {
            delete connections.remove(i);
            i--;
        }
    }
    if(iE != -1)
{
    delete edges.remove(iE);
        return true;
    }
}

bool Graph::removeConnection(const char* org, const char* dest, const char* edge)
{
    if(edge == nullptr){
        return false;
    }
    Edge* e = nullptr;
    for(int i = 0; i < edges.longitud(); i++){
        if(stringsEqual(edges.get(i)->getName(),edge)){
            e = edges.get(i);
        }
    }
    Node* orgNode = findNode(org);
    Node* destNode = findNode(dest);
    if(orgNode == nullptr || destNode == nullptr || edge == nullptr)
    {
        return false;
    }

    for(int i = 0; i < connections.longitud(); i++)
    {
        Connection* conn = connections.get(i);
        if(conn->getOrg() == orgNode && conn->getDest() == destNode && conn->getEdge() == e)
        {
            delete connections.remove(i);
            return true;
        }
    }
    return false;
}
