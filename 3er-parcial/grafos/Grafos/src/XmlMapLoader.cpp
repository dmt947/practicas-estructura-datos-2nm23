#include "XmlMapLoader.h"
#include <iostream>

XmlMapLoader::XmlMapLoader() : MapLoader() {}

XmlMapLoader::~XmlMapLoader() {}

bool XmlMapLoader::fillGraph(void* root, Graph* graph)
{
    if (root == nullptr || graph == nullptr)
    {
        std::cerr << "[XML LOADER ERROR]: Parametros nulos." << std::endl;
        return false;
    }
    XmlNode* xmlRoot = (XmlNode*)root;

    if (!stringsEqual(xmlRoot->getTag(), "mapa"))
    {
        std::cerr << "[XML LOADER ERROR]: La etiqueta raiz debe ser <mapa>." << std::endl;
        return false;
    }

    XmlNodeList* sectionCurrent = xmlRoot->getChildren();
    while (sectionCurrent != nullptr)
    {
        XmlNode* section = sectionCurrent->getNode();

        if (section != nullptr && section->getTag() != nullptr)
        {
            if (stringsEqual(section->getTag(), "nodos"))
            {
                XmlNodeList* nodeCurrent = section->getChildren();
                while (nodeCurrent != nullptr)
                {
                    if (nodeCurrent->getNode() != nullptr && nodeCurrent->getNode()->getTag() != nullptr)
                    {
                        if(stringsEqual(nodeCurrent->getNode()->getTag(), "nodo"))
                        {
                            const char* nodeName = nodeCurrent->getNode()->getContent();
                            if (nodeName != nullptr)
                            {

                                char* secureName = dupString(nodeName);
                                graph->addNode(secureName);
                            }
                        }
                    }
                    nodeCurrent = nodeCurrent->getNext();
                }
            }
            else if (stringsEqual(section->getTag(), "aristas"))
            {

                XmlNodeList* edgeCurrent = section->getChildren();
                while (edgeCurrent != nullptr)
                {
                    if (edgeCurrent->getNode() != nullptr && stringsEqual(edgeCurrent->getNode()->getTag(), "arista"))
                    {

                        const char* name = nullptr;
                        double time = 0.0;
                        double cost = 0.0;

                        XmlNodeList* propCurrent = edgeCurrent->getNode()->getChildren();
                        while (propCurrent != nullptr)
                        {
                            XmlNode* prop = propCurrent->getNode();
                            if (prop != nullptr)
                            {
                                if (stringsEqual(prop->getTag(), "nombre"))
                                {
                                    name = prop->getContent();
                                }
                                else if (stringsEqual(prop->getTag(), "tiempo"))
                                {
                                    if (prop->getContent() != nullptr)
                                    {
                                        time = std::atof(prop->getContent());
                                    }
                                }
                                else if (stringsEqual(prop->getTag(), "costo"))
                                {
                                    if (prop->getContent() != nullptr)
                                    {
                                        cost = std::atof(prop->getContent());
                                    }
                                }
                            }
                            propCurrent = propCurrent->getNext();
                        }

                        if (name != nullptr)
                        {
                            char* secureEdgeName = dupString(name);
                            graph->addEdge(secureEdgeName, time, cost);
                        }
                    }

                    edgeCurrent = edgeCurrent->getNext();
                }
            }

            else if (stringsEqual(section->getTag(), "conexiones"))
            {

                XmlNodeList* connCurrent = section->getChildren();
                while (connCurrent != nullptr)
                {
                    if (connCurrent->getNode() != nullptr && stringsEqual(connCurrent->getNode()->getTag(), "conexion"))
                    {
                        const char* from = nullptr;
                        const char* to = nullptr;
                        const char* via = nullptr;

                        XmlNodeList* propCurrent = connCurrent->getNode()->getChildren();
                        while (propCurrent != nullptr)
                        {
                            XmlNode* prop = propCurrent->getNode();
                            if (prop != nullptr)
                            {
                                if (stringsEqual(prop->getTag(), "origen"))
                                {
                                    from = prop->getContent();
                                }
                                else if (stringsEqual(prop->getTag(), "destino"))
                                {
                                    to = prop->getContent();
                                }
                                else if (stringsEqual(prop->getTag(), "via"))
                                {
                                    via = prop->getContent();
                                }
                            }
                            propCurrent = propCurrent->getNext();
                        }

                        if (from != nullptr && to != nullptr && via != nullptr)
                        {

                            char* secureFrom = dupString(from);
                            char* secureTo = dupString(to);
                            char* secureVia = dupString(via);

                            graph->connectNodes(secureFrom, secureTo, secureVia);

                            delete[] secureFrom;
                            delete[] secureTo;
                            delete[] secureVia;
                        }
                    }
                    connCurrent = connCurrent->getNext();
                }
            }
        }
        sectionCurrent = sectionCurrent->getNext();
    }

    return true;

}
