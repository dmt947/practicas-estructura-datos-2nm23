#include "JsonMapLoader.h"
#include <iostream>

JsonMapLoader::JsonMapLoader() : MapLoader() {}

JsonMapLoader::~JsonMapLoader() {}

JsonValue* JsonMapLoader::findInObject(ObjectNode* objHead, const char* key)
{
    ObjectNode* current = objHead;
    while(current != nullptr)
    {
        if(stringsEqual(current->getKey(), key))
        {
            return current->getValue();
        }
        current = current->getNext();
    }
    return nullptr;
}

bool JsonMapLoader::fillGraph(void* root, Graph* graph)
{
    if(root == nullptr || graph == nullptr)
    {
        return false;
    }
    JsonValue* jsonRoot = (JsonValue*)root;
    if(jsonRoot->getType() != JSON_OBJECT)
    {
        std::cerr << "[ERROR]: La raiz del JSON debe ser un objeto" << std::endl;
        return false;
    }
    ObjectNode* mainObj = jsonRoot->getObj();

    JsonValue* nodosVal = findInObject(mainObj, "nodos");
    if(nodosVal != nullptr && nodosVal->getType() == JSON_ARRAY)
    {
        ArrayNode* currNode = nodosVal->getArr();
        while(currNode != nullptr)
        {
            JsonValue* item = currNode->getValue();
            if(item != nullptr && item->getType() == JSON_STRING)
            {
                graph->addNode(item->getStr());
            }
            currNode = currNode->getNext();
        }
    }
    JsonValue* aristasVal = findInObject(mainObj, "aristas");
    if(aristasVal != nullptr && aristasVal->getType() == JSON_ARRAY)
    {
        ArrayNode* currEdgeNode = aristasVal->getArr();
        while(currEdgeNode != nullptr)
        {
            JsonValue* edgeObjVal = currEdgeNode->getValue();
            if(edgeObjVal != nullptr && edgeObjVal->getType() == JSON_OBJECT)
            {
                ObjectNode* edgeFields = edgeObjVal->getObj();

                JsonValue* nameVal = findInObject(edgeFields, "nombre");
                JsonValue* timeVal = findInObject(edgeFields, "tiempo");
                JsonValue* costVal = findInObject(edgeFields, "costo");

                if(nameVal && timeVal && costVal)
                {
                    graph->addEdge(nameVal->getStr(), timeVal->getNum(), costVal->getNum());
                }
            }
            currEdgeNode = currEdgeNode->getNext();
        }
    }
    JsonValue* conexionesVal = findInObject(mainObj,"conexiones");
    if(conexionesVal != nullptr && conexionesVal->getType() == JSON_ARRAY)
    {
        ArrayNode* currConnNode = conexionesVal->getArr();
        while(currConnNode != nullptr)
        {
            JsonValue* connObjVal = currConnNode->getValue();
            if(connObjVal != nullptr && connObjVal->getType() == JSON_OBJECT)
            {
                ObjectNode* connFields = connObjVal->getObj();
                JsonValue* orgVal = findInObject(connFields, "origen");
                JsonValue* destVal = findInObject(connFields, "destino");
                JsonValue* viaVal = findInObject(connFields, "via");
                if(orgVal && destVal && viaVal)
                {
                    graph->connectNodes(orgVal->getStr(), destVal->getStr(), viaVal->getStr());
                }
            }
            currConnNode = currConnNode->getNext();
        }
    }
    return true;
}
