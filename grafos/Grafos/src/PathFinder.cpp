#include "PathFinder.h"
#include <iostream>

PathFinder::PathFinder() {}

PathFinder::~PathFinder() {}

Path* PathFinder::shortestPath(const Graph* graph, const char* origin, const char *destination, int criteria)
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
        double initialWeight = (n == org) ? 0.0 : INF;
        DijkstraRow* row = new DijkstraRow(n, initialWeight, nullptr, nullptr, false);
        table.add(row, table.longitud());
    }

    for(int count = 0; count < numNodes; count++)
    {
        DijkstraRow* currentCol = nullptr;
        double minWeight = INF;

        for(int i = 0; i < table.longitud(); i++)
        {
            DijkstraRow* row = table.get(i);
            if(!row->isVisited() && row->getWeight() < minWeight)
            {
                minWeight = row->getWeight();
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
                    double edgeWeight = (criteria == 1) ? conn->getEdge()->getTime() : conn->getEdge()->getCost();
                    double altWeight = currentCol->getWeight() + edgeWeight;

                    if(altWeight < vCol->getWeight())
                    {
                        vCol->setWeight(altWeight);
                        vCol->setPreviousNode(u);
                        vCol->setPreviousConnection(conn);
                        vCol->setAccumulatedCost(currentCol->getAccumulatedCost() + conn->getEdge()->getCost());
                        vCol->setAccumulatedDistance(currentCol->getAccumulatedDistance() + conn->getEdge()->getTime());
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

    if(destCol == nullptr || destCol->getWeight() == INF)
    {
        std::cerr << "[ERROR]: No hay ruta disponible" << std::endl;
        while(!table.vacia())
        {
            delete table.remove(0);
        }
        return nullptr;
    }

    Lista<Node*>* travelledNodes = new Lista<Node*>;
    Lista<Edge*>* travelledEdges = new Lista<Edge*>;

    DijkstraRow* iterCol = destCol;

    Pila<Node*> stackNodes;
    Pila<Edge*> stackEdges;

    while(iterCol != nullptr && iterCol->getNode() != org)
    {
        stackNodes.push(iterCol->getNode());

        if(iterCol->getPreviousConnection() != nullptr)
        {
            stackEdges.push(iterCol->getPreviousConnection()->getEdge());
        }

        Node* prevNode = iterCol->getPreviousNode();
        iterCol = nullptr;

        if(prevNode != nullptr)
        {
            for(int i = 0; i < table.longitud(); i++)
            {
                if(table.get(i)->getNode() == prevNode)
                {
                    iterCol = table.get(i);
                    break;
                }
            }
        }
    }

    travelledNodes->add(org, travelledNodes->longitud());

    while(!stackEdges.vacia())
    {
        travelledEdges->add(stackEdges.pop(), travelledEdges->longitud());
    }

    while(!stackNodes.vacia())
    {
        travelledNodes->add(stackNodes.pop(), travelledNodes->longitud());
    }

    double totalD = destCol->getAccumulatedDistance();
    double totalC = destCol->getAccumulatedCost();

    Path* finalPath = new Path(org, totalC, totalD, travelledNodes, travelledEdges);

    while (!table.vacia())
    {
        delete table.remove(0);
    }

    return finalPath;
}
