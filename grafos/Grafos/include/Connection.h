#ifndef CONNECTION_H
#define CONNECTION_H

#include "Node.h"
#include "Edge.h"

class Connection
{
public:
    Connection(Node* o, Node* d, Edge* e);
    ~Connection();

    Node* getOrg() const;
    Node* getDest() const;
    Edge* getEdge() const;

    void setOrg(Node* o);
    void setDest(Node* d);
    void setEdge(Edge* e);
protected:

private:
    Node* org;
    Node* dest;
    Edge* edge;
};

#endif // CONNECTION_H
