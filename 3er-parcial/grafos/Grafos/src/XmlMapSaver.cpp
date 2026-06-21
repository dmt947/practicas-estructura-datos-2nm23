#include "XmlMapSaver.h"
#include <iostream>
#include <fstream>

XmlMapSaver::XmlMapSaver() {}

XmlMapSaver::~XmlMapSaver() {}

bool XmlMapSaver::saveGraph(const char* filename, const Graph* graph)
{
    std::ofstream file(filename);
    if(!file.is_open())
    {
        std::cerr << "[ERROR]: No se pudo abrir el archivo para escribir XML: " << filename << std::endl;
        return false;
    }

    const Lista<Node*>& nodes = graph->getNodes();
    const Lista<Edge*>& edges = graph->getEdges();
    const Lista<Connection*>& connections = graph->getConnections();

    file << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n";
    file << "<mapa>\n";

    file << "  <nodos>\n";
    for (int i = 0; i < nodes.longitud(); i++)
    {
        file << "    <nodo>" << nodes.get(i)->getName() << "</nodo>\n";
    }
    file << "  </nodos>\n";

    file << "  <aristas>\n";
    for (int i = 0; i < edges.longitud(); i++)
    {
        Edge* e = edges.get(i);
        file << "    <arista>\n";
        file << "      <nombre>" << e->getName() << "</nombre>\n";
        file << "      <tiempo>" << e->getTime() << "</tiempo>\n";
        file << "      <costo>" << e->getCost() << "</costo>\n";
        file << "    </arista>\n";
    }
    file << "  </aristas>\n";

    file << "  <conexiones>\n";
    for (int i = 0; i < connections.longitud(); i++)
    {
        Connection* conn = connections.get(i);
        file << "    <conexion>\n";
        file << "      <origen>" << conn->getOrg()->getName() << "</origen>\n";
        file << "      <destino>" << conn->getDest()->getName() << "</destino>\n";
        file << "      <via>" << conn->getEdge()->getName() << "</via>\n";
        file << "    </conexion>\n";
    }
    file << "  </conexiones>\n";

    file << "</mapa>\n";

    file.close();
    return true;
}
