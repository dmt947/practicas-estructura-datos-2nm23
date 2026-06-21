#include "DijkstraRow.h"

DijkstraRow::DijkstraRow(Node* n, double initW, Node* prevN, Connection* prevC, bool vis)
{
    node = n;
    weight = initW;
    previousNode = prevN;
    previousConnection = prevC;
    visited = vis;

    accumulatedCost = (initW == 0.0) ? 0.0 : 1e9;
    accumulatedDistance = (initW == 0.0) ? 0.0 : 1e9;
}

DijkstraRow::~DijkstraRow() {}

Node* DijkstraRow::getNode() const
{
    return node;
}

double DijkstraRow::getWeight() const
{
    return weight;
}
void DijkstraRow::setWeight(double w)
{
    weight = w;
}

Node* DijkstraRow::getPreviousNode() const
{
    return previousNode;
}
void DijkstraRow::setPreviousNode(Node* prevN)
{
    previousNode = prevN;
}

Connection* DijkstraRow::getPreviousConnection() const
{
    return previousConnection;
}
void DijkstraRow::setPreviousConnection(Connection* prevC)
{
    previousConnection = prevC;
}

bool DijkstraRow::isVisited() const
{
    return visited;
}
void DijkstraRow::setVisited(bool visit)
{
    visited = visit;
}

double DijkstraRow::getAccumulatedDistance() const
{
    return accumulatedDistance;
}
void DijkstraRow::setAccumulatedDistance(double dist)
{
    accumulatedDistance = dist;
}

double DijkstraRow::getAccumulatedCost() const
{
    return accumulatedCost;
}
void DijkstraRow::setAccumulatedCost(double cost)
{
    accumulatedCost = cost;
}
