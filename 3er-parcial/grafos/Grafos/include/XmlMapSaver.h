#ifndef XMLMAPSAVER_H
#define XMLMAPSAVER_H

#include "MapSaver.h"

class XmlMapSaver : public MapSaver
{
public:
    XmlMapSaver();
    ~XmlMapSaver();

    bool saveGraph(const char* filename, const Graph* graph) override;

protected:

private:
};

#endif // XMLMAPSAVER_H
