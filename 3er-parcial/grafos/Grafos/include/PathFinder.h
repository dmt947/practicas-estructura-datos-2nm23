#ifndef PATHFINDER_H
#define PATHFINDER_H

#include "Graph.h"
#include "DijkstraRow.h"
#include "Path.h"
#include "../../../adt/punteros/Lista/include/Lista.h"
#include "../../../adt/punteros/Pila/include/Pila.h"

class PathFinder
{
public:
    PathFinder();
    ~PathFinder();

    Path* shortestPath(const Graph* graph, const char* origin, const char *destination, int criteria);

protected:

private:
    const double INF = 1e9;
};

#endif // PATHFINDER_H
