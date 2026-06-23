#ifndef XMLNODE_H
#define XMLNODE_H

class XmlNodeList;
#include "XmlNodeList.h"

class XmlNode
{
public:
    XmlNode(const char* tagName);
    ~XmlNode();

    void setContent(const char* text);
    void addChild(XmlNode* child);

    const char* getTag() const;
    const char* getContent() const;
    XmlNodeList* getChildren() const;

private:
    char* tag;
    char* content;
    XmlNodeList* children;
    XmlNodeList* lastChild;

    char* cloneString(const char* src);
};

#endif // XMLNODE_H
