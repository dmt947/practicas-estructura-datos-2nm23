#ifndef JSONMAPSAVER_H
#define JSONMAPSAVER_H

#include "MapSaver.h"

class JsonMapSaver : public MapSaver
{
public:
    JsonMapSaver();
    ~JsonMapSaver();
    bool saveGraph(const char* filename, const Graph* graph) override;
protected:

private:
};

#endif // JSONMAPSAVER_H
