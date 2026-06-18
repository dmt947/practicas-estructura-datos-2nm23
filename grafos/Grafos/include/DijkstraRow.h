#ifndef DIJKSTRAROW_H
#define DIJKSTRAROW_H

#include "Node.h"

class DijkstraRow
{
public:
    DijkstraRow(Node* n, double dist, Node* prev, bool vis);
    ~DijkstraRow();

    Node* getNode() const;
    double getDistance() const;
    Node* getPrevious() const;
    bool isVisited() const;

    void setDistance(double dist);
    void setPrevious(Node* prev);
    void setVisited(bool vis);

protected:

private:
    Node* node;
    double distance;
    Node* previous;
    bool visited;
};

#endif // DIJKSTRAROW_H
