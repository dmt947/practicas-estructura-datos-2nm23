#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "Graph.h"
#include "Digraph.h"
#include "Tree.h"
#include "PathFinder.h"
#include "Path.h"

#include "../../../parser/Parser/include/Parser.h"
#include "../../../parser/Parser/include/JsonParser.h"
#include "../../../parser/Parser/include/XmlParser.h"

#include "MapLoader.h"
#include "JsonMapLoader.h"
#include "XmlMapLoader.h"

int main()
{
    std::cout << "=========================================================" << std::endl;
    std::cout << "1. Leer desde archivo JSON" << std::endl;
    std::cout << "2. Leer desde archivo XML" << std::endl;
    std::cout << "=========================================================" << std::endl;
    std::cout << "Selecciona el formato de entrada [1-2] (default: 1): ";

    std::string opcionFormato;
    std::getline(std::cin, opcionFormato);
    if(opcionFormato == "")
    {
        opcionFormato = "1";
    }

    Parser* parserObj = nullptr;
    MapLoader* loaderObj = nullptr;
    std::string nombreArchivo = "";
    std::string tipoFormato = "";

    if (opcionFormato == "1")
    {
        loaderObj = new JsonMapLoader();
        tipoFormato = "json";
        std::cout << "\n[FORMATO]: Has seleccionado JSON." << std::endl;
    }
    else if (opcionFormato == "2")
    {
        loaderObj = new XmlMapLoader();
        tipoFormato = "xml";
        std::cout << "\n[FORMATO]: Has seleccionado XML." << std::endl;
    }
    else
    {
        std::cerr << "[ERROR]: Opcion de formato invalida. Saliendo." << std::endl;
        return 1;
    }

    std::cout << "\n=========================================================" << std::endl;
    std::cout << "                 Selecciona una estructura               " << std::endl;
    std::cout << "=========================================================" << std::endl;
    std::cout << "1. Grafo" << std::endl;
    std::cout << "2. Digrafo" << std::endl;
    std::cout << "3. Arbol" << std::endl;
    std::cout << "=========================================================" << std::endl;
    std::cout << "Selecciona una opcion [1-3] (default: 1): ";

    std::string opcionEstructura;
    std::getline(std::cin, opcionEstructura);
    if(opcionEstructura == "")
    {
        opcionEstructura = "1";
    }

    Graph* miMapa = nullptr;

    if (opcionEstructura == "1")
    {
        miMapa = new Graph();
        nombreArchivo = "grafo." + tipoFormato;
        std::cout << "\n[CONFIG]: Has seleccionado un GRAFO. Abriendo '" << nombreArchivo << "'..." << std::endl;
    }
    else if (opcionEstructura == "2")
    {
        miMapa = new Digraph();
        nombreArchivo = "digrafo." + tipoFormato;
        std::cout << "\n[CONFIG]: Has seleccionado un DIGRAFO. Abriendo '" << nombreArchivo << "'..." << std::endl;
    }
    else if (opcionEstructura == "3")
    {
        miMapa = new Tree();
        nombreArchivo = "arbol." + tipoFormato;
        std::cout << "\n[CONFIG]: Has seleccionado un ARBOL. Cargando '" << nombreArchivo << "'..." << std::endl;
    }
    else
    {
        std::cerr << "[ERROR]: Opcion de estructura invalida. Saliendo." << std::endl;
        delete loaderObj;
        return 1;
    }

    std::ifstream archivo(nombreArchivo);
    if (!archivo.is_open())
    {
        std::cerr << "[ERROR]: No se pudo abrir el archivo: " << nombreArchivo << std::endl;
        delete miMapa;
        delete loaderObj;
        return 1;
    }

    std::stringstream buffer;
    buffer << archivo.rdbuf();
    std::string contenido = buffer.str();
    archivo.close();

    if (tipoFormato == "json")
    {
        parserObj = new JsonParser(contenido.c_str());
    }
    else
    {
        parserObj = new XmlParser(contenido.c_str());
    }

    std::cout << "[PARSER]: Parseando archivo..." << std::endl;
    void* valor = parserObj->parse();

    if (parserObj->failed() || valor == nullptr)
    {
        std::cerr << "[ERROR]: El parser detecto un fallo critico de sintaxis en el archivo." << std::endl;
        if (valor != nullptr)
        {
            if (tipoFormato == "json")
            {
                delete (JsonValue*)valor;
            }
            else
            {
                delete (XmlNode*)valor;
            }
        }
        delete parserObj;
        delete loaderObj;
        delete miMapa;
        return 1;
    }

    std::cout << "[PARSER]: Parseado completo." << std::endl;
    std::cout << "[LOADER]: Mapeando datos al grafo." << std::endl;

    if (!loaderObj->fillGraph(valor, miMapa))
    {
        std::cerr << "[ERROR]: El cargador fallo al mapear los datos al grafo." << std::endl;
        if (tipoFormato == "json")
        {
            delete (JsonValue*)valor;
        }
        else
        {
            delete (XmlNode*)valor;
        }
        delete parserObj;
        delete loaderObj;
        delete miMapa;
        return 1;
    }

    if (tipoFormato == "json")
    {
        delete (JsonValue*)valor;
    }
    else
    {
        delete (XmlNode*)valor;
    }

    delete parserObj;
    delete loaderObj;

    std::cout << "[LOADER]:Grafo cargado exitosamente." << std::endl;

    PathFinder buscador;
    std::string origen, destino;
    bool continuar = true;

    while (continuar)
    {
        std::cout << "\n---------------------------------------------------------" << std::endl;

        if(opcionEstructura == "1")
        {
            std::cout << "GRAFO:" << std::endl;
        }
        else if(opcionEstructura == "2")
        {
            std::cout << "DIGRAFO:" << std::endl;
        }
        else if(opcionEstructura == "3")
        {
            std::cout << "ARBOL:" << std::endl;
        }

        const Lista<Node*>& listaNodos = miMapa->getNodes();
        const Lista<Connection*>& listaConexiones = miMapa->getConnections();


        for (int i = 0; i < listaNodos.longitud(); i++)
        {
            Node* nodo = listaNodos.get(i);
            std::cout << "> NODO: " << nodo->getName() << std::endl;
            for(int j = 0; j < listaConexiones.longitud(); j++)
            {
                Connection* conexion = listaConexiones.get(j);
                if(conexion->getOrg() == nodo)
                {
                    Edge* via = conexion->getEdge();
                    Node* dest = conexion->getDest();
                    std::cout << "--> Conexion a NODO: " << dest->getName() << " | VIA: " << via->getName() << " | TIEMPO: " << via->getTime() << " | COSTO: " << via->getCost() << std::endl;
                }
            }

        }
        std::cout << "---------------------------------------------------------" << std::endl;
        std::cout << "(Escribe 'x' para salir)\n" << std::endl;

        std::cout << "¿Donde estas? [A / B / C / D] (default: A): ";
        std::getline(std::cin, origen);
        if (origen == "x" || origen == "X")
        {
            break;
        }
        else if (origen == "")
        {
            origen = "A";
        }

        std::cout << "¿A donde quieres ir? [A / B / C / D] (default: A):";
        std::getline(std::cin, destino);
        if (destino == "x" || destino == "X")
        {
            break;
        }
        else if (destino == "")
        {
            destino = "A";
        }

        std::cout << "\n[PATHFINDER] Procesando ruta" << std::endl;

        Path* rutaC = buscador.shortestPath(miMapa, origen.c_str(), destino.c_str(), 0);
        Path* rutaD = buscador.shortestPath(miMapa, origen.c_str(), destino.c_str(), 1);

        if (rutaC != nullptr && rutaD != nullptr)
        {
            std::cout << "\n>>> RUTA MAS RAPIDA DE '" << origen.c_str() << "' A '" << destino.c_str()<<"' <<<" << std::endl;
            std::cout << "> TIEMPO: " << rutaD->getTotalDistance() << std::endl;
            std::cout << "> COSTO: " << rutaD->getTotalCost() << std::endl;
            std::cout << "> RUTA: " << rutaD->getTravelledNodes().get(0)->getName();

            for(int i = 0; i < rutaD->getTravelledEdges().longitud(); i++)
            {
                std::cout << " -- VIA: " << rutaD->getTravelledEdges().get(i)->getName() << " -> " << rutaD->getTravelledNodes().get(i+1)->getName();
            }
            std::cout << " -> FIN" << std::endl;
            delete rutaD;

            std::cout << "\n>>> RUTA MAS BARATA DE '" << origen.c_str() << "' A '" << destino.c_str()<<"' <<<" << std::endl;
            std::cout << ">TIEMPO: " << rutaC->getTotalDistance() << std::endl;
            std::cout << ">COSTO: " << rutaC->getTotalCost() << std::endl;
            std::cout << ">RUTA: " << rutaC->getTravelledNodes().get(0)->getName();

            for(int i = 0; i < rutaC->getTravelledEdges().longitud(); i++)
            {
                std::cout << " -- VIA: " << rutaC->getTravelledEdges().get(i)->getName() << " -> " << rutaC->getTravelledNodes().get(i+1)->getName();
            }
            std::cout << " -> FIN" << std::endl;
            delete rutaC;
        }
        else
        {
            std::cout << "\n[PATHFINDER]: No existe una ruta valida desde '" << origen << "' hasta '" << destino << "' en esta estructura." << std::endl;
        }
    }
    delete miMapa;

    std::cout << "[FIN]: Programa finalizado con éxito." << std::endl;
    return 0;
}
