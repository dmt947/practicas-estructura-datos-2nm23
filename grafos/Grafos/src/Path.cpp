#include "Path.h"

Path::Path(Node* n, double totalC, double totalD, Lista<Node*>* travN, Lista<Edge*>* travE)
{
    orgNode = n;
    totalCost = totalC;
    totalDistance = totalD;
    travelledNodes = travN;
    travelledEdges = travE;
}

Path::~Path()
{
    delete travelledEdges;
    delete travelledNodes;
}

Node* Path::getOrgNode() const
{
    return orgNode;
}

double Path::getTotalCost() const
{
    return totalCost;
}

double Path::getTotalDistance() const
{
    return totalDistance;
}

const Lista<Node*>& Path::getTravelledNodes() const
{
    return *travelledNodes;
}

const Lista<Edge*>& Path::getTravelledEdges() const
{
    return *travelledEdges;
}

