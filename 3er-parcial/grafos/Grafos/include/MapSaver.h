#ifndef MAPSAVER_H
#define MAPSAVER_H

#include "Graph.h"

class MapSaver
{
public:
    MapSaver();
    virtual ~MapSaver();

    virtual bool saveGraph(const char* filename, const Graph* graph) = 0;
protected:

private:
};

#endif // MAPSAVER_H
