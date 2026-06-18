#ifndef TREE_H
#define TREE_H

#include "Graph.h"

class Tree : public Graph
{
public:
    Tree();
    virtual ~Tree();

    bool connectNodes(const char* from, const char* to, const char* via) override;

protected:

private:
};

#endif // TREE_H
