#ifndef PATH_H
#define PATH_H

#include "Node.h"
#include "Edge.h"
#include "../../../adt/punteros/Lista/include/Lista.h"

class Path
{
public:
    Path(Node* n, double totalC, double totalD, Lista<Node*>* travN, Lista<Edge*>* travE);
    ~Path();

    Node* getOrgNode() const;
    double getTotalCost() const;
    double getTotalDistance() const;
    const Lista<Edge*>& getTravelledEdges() const;
    const Lista<Node*>& getTravelledNodes() const;

protected:

private:
    Node* orgNode;

    double totalCost, totalDistance;

    Lista<Node*>* travelledNodes;
    Lista<Edge*>* travelledEdges;
};

#endif // PATH_H
