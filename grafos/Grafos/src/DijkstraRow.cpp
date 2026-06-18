#include "DijkstraRow.h"

DijkstraRow::DijkstraRow(Node* n, double dist, Node* prev, bool vis)
{
    node = n;
    distance = dist;
    previous = prev;
    visited = vis;
}

DijkstraRow::~DijkstraRow() {}

Node* DijkstraRow::getNode() const
{
    return node;
}

double DijkstraRow::getDistance() const
{
    return distance;
}

Node* DijkstraRow::getPrevious() const
{
    return previous;
}

bool DijkstraRow::isVisited() const
{
    return visited;
}

void DijkstraRow::setDistance(double dist)
{
    distance = dist;
}

void DijkstraRow::setPrevious(Node* prev)
{
    previous = prev;
}

void DijkstraRow::setVisited(bool vis)
{
    visited = vis;
}
