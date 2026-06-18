#ifndef XMLNODELIST_H
#define XMLNODELIST_H

class XmlNode;
#include "XmlNode.h"

class XmlNodeList
{
public:
    XmlNodeList(XmlNode* n);
    ~XmlNodeList();

    XmlNode* getNode() const;
    XmlNodeList* getNext() const;

    void setNext(XmlNodeList* n);
protected:

private:
    XmlNode* node;
    XmlNodeList* next;
};

#endif // XMLNODELIST_H
