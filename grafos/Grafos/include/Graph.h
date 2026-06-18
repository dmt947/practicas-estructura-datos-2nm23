#ifndef GRAPH_H
#define GRAPH_H

#include "Node.h"
#include "Edge.h"
#include "Connection.h"
#include "../../../adt/punteros/Lista/include/Lista.h"

class Graph
{
public:
    Graph();
    virtual ~Graph();

    bool addNode(const char* name);
    bool addEdge(const char* name, double time, double cost);
    virtual bool connectNodes(const char* from, const char* to, const char* via);

    Node* findNode(const char* name) const;
    Edge* findEdge(const char* name) const;

    const Lista<Node*>& getNodes() const;
    const Lista<Edge*>& getEdges() const;
    const Lista<Connection*>& getConnections() const;

protected:
    Lista<Node*> nodes;
    Lista<Edge*> edges;
    Lista<Connection*> connections;

    bool hasIncomingConnection(const char* nodeName) const;
    bool stringsEqual(const char* s1, const char* s2) const;
private:

};

#endif // GRAPH_H
