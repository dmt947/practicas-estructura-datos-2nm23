#include "Connection.h"

Connection::Connection(Node* o, Node* d, Edge* e)
{
    org = o;
    dest = d;
    edge = e;
}

Connection::~Connection() {}

Node* Connection::getOrg() const
{
    return org;
}

Node* Connection::getDest() const
{
    return dest;
}

Edge* Connection::getEdge() const
{
    return edge;
}

void Connection::setOrg(Node* o)
{
    org = o;
}

void Connection::setDest(Node* d)
{
    dest = d;
}

void Connection::setEdge(Edge* e)
{
    edge = e;
}

