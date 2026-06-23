#include "JsonMapSaver.h"
#include <string>
#include <iostream>
#include <fstream>

JsonMapSaver::JsonMapSaver() {}

JsonMapSaver::~JsonMapSaver() {}

bool JsonMapSaver::saveGraph(const char* filename, const Graph* graph)
{
    std::ofstream file(filename);
    if(!file.is_open())
    {
        std::cerr << "[ERROR]: No se pudo abrir el archivo para escribir JSON: " << filename << std::endl;
        return false;
    }
    const Lista<Node*>& nodes = graph->getNodes();
    const Lista<Edge*>& edges = graph->getEdges();
    const Lista<Connection*>& connections = graph->getConnections();

    file << "{\n";
    file << "  \"nodos\": [ ";
    for (int i = 0; i < nodes.longitud(); i++)
    {
        file << "\"" << nodes.get(i)->getName() << "\"";
        if (i < nodes.longitud() - 1) file << ",";
    }
    file << " ],\n";
    file << "  \"aristas\": [\n";
    for (int i = 0; i < edges.longitud(); i++)
    {
        Edge* e = edges.get(i);
        file << "    { \"nombre\": \"" << e->getName() << "\", \"tiempo\": " << e->getTime() << ", \"costo\": " << e->getCost() << " }";
        if (i < edges.longitud() - 1) file << ",";
        file << "\n";
    }
    file << "  ],\n";
    file << "  \"conexiones\": [\n";
    Lista<std::string> conexionesEscritas;

    for (int i = 0; i < connections.longitud(); i++)
    {
        Connection* conn = connections.get(i);
        std::string origName = conn->getOrg()->getName();
        std::string destName = conn->getDest()->getName();
        std::string edgeName = conn->getEdge()->getName();

        // Creamos un identificador único para el regreso (Destino-Origen-Via)
        std::string espejo = destName + "-" + origName + "-" + edgeName;

        // Verificamos si ya guardamos el regreso de esta conexión
        bool yaSeGuardoEspejo = false;
        for(int j = 0; j < conexionesEscritas.longitud(); j++)
        {
            if(conexionesEscritas.get(j) == espejo)
            {
                yaSeGuardoEspejo = true;
                break;
            }
        }

        // Si ya se guardó su pareja de regreso, nos la saltamos para no duplicar el archivo
        if (yaSeGuardoEspejo)
        {
            continue;
        }

        // Registrar esta conexión como escrita
        std::string actual = origName + "-" + destName + "-" + edgeName;
        conexionesEscritas.add(actual, conexionesEscritas.longitud());
        if(i > 0)
        {
            file << ",\n";
        }
        file << "    { \"origen\": \"" << origName << "\", \"destino\": \"" << destName << "\", \"via\": \"" << edgeName << "\" }";
    }
    file << "\n  ]\n";
    file << "}\n";

    file.close();
    return true;
}
