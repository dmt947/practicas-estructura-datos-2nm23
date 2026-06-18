#ifndef PATHFINDER_H
#define PATHFINDER_H

#include "Graph.h"
#include "DijkstraRow.h"
#include "../../../adt/punteros/Lista/include/Lista.h"
#include "../../../adt/punteros/Pila/include/Pila.h"

class PathFinder
{
public:
    PathFinder();
    ~PathFinder();

    Pila<Node*>* shortestPath(const Graph* graph, const char* origin, const char *destination, int criteria);
    double getTotalDistance() const;

protected:

private:
    const double INF = 1e9;
    double totalDistance;

    void setTotalDistance(double totalDist);
};

#endif // PATHFINDER_H
