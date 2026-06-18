#ifndef MAPLOADER_H
#define MAPLOADER_H

#include "Graph.h"
#include "../../JsonParser/include/JsonValue.h"


class MapLoader
{
public:
    MapLoader();
    virtual ~MapLoader();

    virtual bool fillGraph(void* root, Graph* graph) = 0;

protected:
    bool stringsEqual(const char* s1, const char* s2);
    char* dupString(const char* src);

private:
    JsonValue* findInObject(ObjectNode* objHead, const char* key);
};

#endif // MAPLOADER_H
