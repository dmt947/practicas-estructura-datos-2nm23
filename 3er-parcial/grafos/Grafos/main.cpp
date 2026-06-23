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
#include "MapSaver.h"
#include "JsonMapSaver.h"
#include "XmlMapSaver.h"

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
    MapSaver* saverObj = nullptr;
    std::string nombreArchivo = "";
    std::string tipoFormato = "";

    if (opcionFormato == "1")
    {
        loaderObj = new JsonMapLoader();
        saverObj = new JsonMapSaver();
        tipoFormato = "json";
        std::cout << "\n[FORMATO]: Has seleccionado JSON." << std::endl;
    }
    else if (opcionFormato == "2")
    {
        loaderObj = new XmlMapLoader();
        saverObj = new XmlMapSaver();
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
        delete saverObj;
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
        delete saverObj;
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
    std::string eleccion, operacion, componente, origen, destino;

    while (eleccion != "X" || eleccion != "x")
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

        std::cout << "¿Que vas a hacer? [consultar/modificar/guardar] (default: consultar)";
        std::getline(std::cin, eleccion);
        if(eleccion == "modificar" || eleccion == "m")
        {
            do
            {
                std::cout << "NOTA: Cualquier cambio realizado se mantendra solamente en esta ejecucion hasta que se guarde en el archivo abierto." << std::endl;
                std::cout << "      Para esto se debe seleccionar la opcion 'guardar' en el menu anterior." << std::endl;
                std::cout << "¿Que deseas hacer? [añadir/eliminar] (default: añadir)";
                std::getline(std::cin, operacion);
                if(operacion == "añadir" || operacion == "a" || operacion == "")
                {
                    std::cout << "¿Que deseas añadir? [nodo/arista/conexion] (default: nodo): ";
                    std::getline(std::cin, componente);
                    if(componente == "nodo" || componente == "n" || componente == "")
                    {
                        std::cout << "¿Cual es el nombre? ";
                        std::string nombreNodo;
                        std::getline(std::cin, nombreNodo);
                        if(nombreNodo == "")
                        {
                            std::cerr << "Nombre invalido." << std::endl;
                            break;
                        }
                        if(miMapa->addNode(nombreNodo.c_str()))
                        {
                            std::cout << "Nodo: " << nombreNodo << " agregado con exito" << std::endl;
                        }
                        else
                        {
                            std::cout << "Error al agregar" << std::endl;
                        }
                    }
                    else if(componente == "arista" || componente=="a")
                    {
                        std::string nombreArista;
                        double tiempo, costo;

                        std::cout << "¿Cual es el nombre? ";
                        std::getline(std::cin, nombreArista);
                        std::cout << "¿Cual es el tiempo? ";
                        std::cin >> tiempo;
                        std::cout << "¿Cual es el costo? ";
                        std::cin >> costo;
                        std::cin.ignore();
                        if(nombreArista == "")
                        {
                            std::cerr << "Parametros invalidos." << std::endl;
                            break;
                        }
                        if(miMapa->addEdge(nombreArista.c_str(), tiempo, costo))
                        {
                            std::cout << "Arista: " << nombreArista << " agregada con exito." << std::endl;
                        }
                        else
                        {
                            std::cerr<<"Error al agregar"<<std::endl;
                        }

                    }
                    else if(componente == "conexion"||componente=="c")
                    {
                        std::string nombreOrigen, nombreDestino, nombreArista;
                        std::cout << "¿Cual es el origen? ";
                        std::getline(std::cin, nombreOrigen);
                        std::cout << "¿Cual es el destino? ";
                        std::getline(std::cin, nombreDestino);
                        std::cout << "¿Cual es el nombre de la via? ";
                        std::getline(std::cin, nombreArista);
                        if(nombreOrigen == "" || nombreDestino == "" || nombreArista == "")
                        {
                            std::cout << "Parametros invalidos" << std::endl;
                            break;
                        }
                        if(miMapa->connectNodes(nombreOrigen.c_str(), nombreDestino.c_str(), nombreArista.c_str()))
                        {
                            std::cout << "Conexion de: " << nombreOrigen << " a: " << nombreDestino << " via: " << nombreArista << std::endl;
                        }
                        else
                        {
                            std::cerr<<"Error al agregar"<<std::endl;
                        }
                    }
                }
                else if(operacion == "eliminar" || operacion == "e")
                {
                    std::cout << "¿Que deseas eliminar? [nodo/arista/conexion] (default: nodo)";
                    std::getline(std::cin, componente);
                    if(componente == "nodo"||componente=="n" || componente == "")
                    {
                        std::cout << "¿Cual es el nombre? ";
                        std::string nombreNodo;
                        std::getline(std::cin, nombreNodo);
                        if(nombreNodo == "")
                        {
                            std::cerr << "Nombre invalido." << std::endl;
                            break;
                        }
                        if(miMapa->removeNode(nombreNodo.c_str()))
                        {
                            std::cout << "Nodo: " << nombreNodo << " elminado con exito" << std::endl;
                        }
                        else
                        {
                            std::cout << "Error al eliminar" << std::endl;
                        }
                    }
                    else if(componente == "arista"||componente=="a")
                    {
                        std::string nombreArista;

                        std::cout << "¿Cual es el nombre? ";
                        std::getline(std::cin, nombreArista);
                        if(nombreArista == "")
                        {
                            std::cerr << "Parametros invalidos." << std::endl;
                            break;
                        }
                        if(miMapa->removeEdge(nombreArista.c_str()))
                        {
                            std::cout << "Arista: " << nombreArista << " eliminada con exito." << std::endl;
                        }
                        else
                        {
                            std::cerr<<"Error al eliminar"<<std::endl;
                        }

                    }
                    else if(componente == "conexion"||componente=="c")
                    {
                        std::string nombreOrigen, nombreDestino, nombreArista;
                        std::cout << "¿Cual es el origen? ";
                        std::getline(std::cin, nombreOrigen);
                        std::cout << "¿Cual es el destino? ";
                        std::getline(std::cin, nombreDestino);
                        std::cout << "¿Cual es el nombre de la via? ";
                        std::getline(std::cin, nombreArista);
                        if(nombreOrigen == "" || nombreDestino == "" || nombreArista == "")
                        {
                            std::cout << "Parametros invalidos" << std::endl;
                            break;
                        }
                        if(miMapa->removeConnection(nombreOrigen.c_str(), nombreDestino.c_str(), nombreArista.c_str()))
                        {
                            std::cout << "Conexion eliminada "<< std::endl;
                        }
                        else
                        {
                            std::cerr<<"Error al eliminar"<<std::endl;
                        }
                    }
                }
                std::cout<<"¿Deseas seguir modificando? [y/n]:";
                std::getline(std::cin, eleccion);
            }
            while(eleccion != "n");
        }
        else if(eleccion == "consultar" || eleccion == "")
        {
            do
            {
                std::cout << "¿Donde estas? [CASE SENSITIVE]: ";
                std::getline(std::cin, origen);
                std::cout << "¿A donde quieres ir? [CASE SENSITIVE]: ";
                std::getline(std::cin, destino);
                if (origen == "" || destino == "")
                {
                    std::cerr << "Parametros invalidos"<<std::endl;
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
                std::cout << "¿Deseas seguir consultando? [y/n]: ";
                std::getline(std::cin, eleccion);
            }
            while(eleccion!="n");
        }
        else if(eleccion == "guardar" || eleccion == "g")
        {
            std::cout << "[SAVER]: Guardando datos en '" << nombreArchivo<<"'..."<<std::endl;
            if(saverObj->saveGraph(nombreArchivo.c_str(),miMapa))
            {
                std::cout << "[SAVER]: Datos guardados exitosamente" <<std::endl;
            }
            else
            {
                std::cerr << "[SAVER]: No se pudieron guardar los datos en el archivo" <<std::endl;
            }
            std::cout << "Aceptar...";
            std::cin.ignore();
        }
        else if(eleccion == "x" || eleccion == "X")
        {
            break;
        }
    }
    delete miMapa;
    delete saverObj;

    std::cout << "[FIN]: Programa finalizado con éxito." << std::endl;
    return 0;
}
