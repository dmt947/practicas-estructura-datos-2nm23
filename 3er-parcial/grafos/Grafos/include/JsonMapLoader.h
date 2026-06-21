#ifndef JSONMAPLOADER_H
#define JSONMAPLOADER_H

#include "MapLoader.h"
#include "../../../parser/Parser/include/JsonValue.h"

class JsonMapLoader : public MapLoader
{
public:
    JsonMapLoader();
    virtual ~JsonMapLoader();

    virtual bool fillGraph(void* root, Graph* graph) override;
protected:

private:
    JsonValue* findInObject(ObjectNode* objHead, const char* key);
};

#endif // JSONMAPLOADER_H
