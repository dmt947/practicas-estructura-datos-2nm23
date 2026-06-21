#ifndef DIGRAPH_H
#define DIGRAPH_H

#include "Graph.h"

class Digraph : public Graph
{
public:
    Digraph();
    virtual ~Digraph();

    bool connectNodes(const char* from, const char* to, const char* via) override;

protected:

private:
};

#endif // DIGRAPH_H
