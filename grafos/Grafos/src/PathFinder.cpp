#include "PathFinder.h"
#include <iostream>

PathFinder::PathFinder() {}

PathFinder::~PathFinder() {}

Pila<Node*>* PathFinder::shortestPath(const Graph* graph, const char* origin, const char *destination, int criteria)
{
    const Lista<Node*>& nodes = graph->getNodes();
    const Lista<Connection*>& connections = graph->getConnections();
    int numNodes = nodes.longitud();

    if(numNodes == 0)
    {
        std::cerr << "[ERROR]: Grafo invalido"<< std::endl;
        return nullptr;
    }

    Node* org = graph->findNode(origin);
    Node* dest = graph->findNode(destination);

    if(org == nullptr || dest == nullptr)
    {
        std::cerr << "[ERROR]: Origen o Destino invalidos" << std::endl;
        return nullptr;
    }

    Lista<DijkstraRow*> table;
    for(int i = 0; i < numNodes; i++)
    {
        Node* n = nodes.get(i);
        double initialDist = (n == org) ? 0.0 : INF;
        DijkstraRow* row = new DijkstraRow(n, initialDist, nullptr, false);
        table.add(row, table.longitud());
    }

    for(int count = 0; count < numNodes; count++)
    {
        DijkstraRow* currentCol = nullptr;
        double minDist = INF;

        for(int i = 0; i < table.longitud(); i++)
        {
            DijkstraRow* row = table.get(i);
            if(!row->isVisited() && row->getDistance() < minDist)
            {
                minDist = row->getDistance();
                currentCol = row;
            }
        }

        if(currentCol == nullptr)
        {
            break;
        }

        currentCol->setVisited(true);
        Node* u = currentCol->getNode();

        int numConn = connections.longitud();

        for(int i = 0; i < numConn; i++)
        {
            Connection* conn = connections.get(i);

            if(conn->getOrg() == u)
            {
                Node* v = conn->getDest();
                DijkstraRow* vCol = nullptr;

                for(int j = 0; j < table.longitud(); j++)
                {
                    if(table.get(j)->getNode() == v)
                    {
                        vCol = table.get(j);
                        break;
                    }
                }
                if(vCol != nullptr && !vCol->isVisited())
                {
                    double weight = (criteria == 1) ? conn->getEdge()->getTime() : conn->getEdge()->getCost();
                    double altDist = currentCol->getDistance() + weight;

                    if(altDist < vCol->getDistance())
                    {
                        vCol->setDistance(altDist);
                        vCol->setPrevious(u);
                    }
                }
            }
        }
    }
    DijkstraRow* destCol = nullptr;
    for(int i = 0; i < table.longitud(); i++)
    {
        if(table.get(i)->getNode() == dest)
        {
            destCol = table.get(i);
            break;
        }
    }

    if(destCol == nullptr || destCol->getDistance() == INF)
    {
        std::cerr << "[ERROR]: No hay ruta disponible" << std::endl;
        while(!table.vacia())
        {
            delete table.remove(0);
        }
        return nullptr;
    }

    Pila<Node*> supportedPath;
    Node* iter = dest;

    while(iter != nullptr)
    {
        supportedPath.push(iter);
        Node* root = nullptr;
        for(int i = 0; i < table.longitud(); i++)
        {
            if(table.get(i)->getNode() == iter)
            {
                root = table.get(i)->getPrevious();
                break;
            }
        }
        iter = root;
    }

    setTotalDistance(destCol->getDistance());

    Pila<Node*>* finalPath = new Pila<Node*>();

    while(!supportedPath.vacia())
    {
        finalPath->push(supportedPath.pop());
    }

    while (!table.vacia())
    {
        delete table.remove(0);
    }

    return finalPath;
}

void PathFinder::setTotalDistance(double totalDist)
{
    totalDistance = totalDist;
}

double PathFinder::getTotalDistance() const
{
    return totalDistance;
}
