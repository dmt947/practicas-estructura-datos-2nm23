#ifndef DIJKSTRAROW_H
#define DIJKSTRAROW_H

#include "Node.h"
#include "Connection.h"

class DijkstraRow
{
public:
    DijkstraRow(Node* n, double initW, Node* prevN, Connection* prevC, bool vis);
    ~DijkstraRow();

    Node* getNode() const;

    double getWeight() const;
    void setWeight(double w);

    Node* getPreviousNode() const;
    void setPreviousNode(Node* n);

    Connection* getPreviousConnection() const;
    void setPreviousConnection(Connection* c);

    bool isVisited() const;
    void setVisited(bool vis);

    double getAccumulatedDistance() const;
    void setAccumulatedDistance(double dist);

    double getAccumulatedCost() const;
    void setAccumulatedCost(double c);


protected:

private:
    Node* node;
    Node* previousNode;
    Connection* previousConnection;

    double weight;
    double accumulatedDistance;
    double accumulatedCost;

    bool visited;
};

#endif // DIJKSTRAROW_H
