#ifndef XMLMAPLOADER_H
#define XMLMAPLOADER_H

#include "MapLoader.h"
#include "../../../parser/Parser/include/XmlNode.h"

class XmlMapLoader:public MapLoader
{
public:
    XmlMapLoader();
    virtual ~XmlMapLoader();

    virtual bool fillGraph(void* root, Graph* graph) override;
protected:

private:
};

#endif // XMLMAPLOADER_H
