#include "XmlNodeList.h"

XmlNodeList::XmlNodeList(XmlNode* n)
{
    node = n;
    next = nullptr;
}

XmlNodeList::~XmlNodeList()
{
    if(next!=nullptr)
    {
        delete next;
    }
}

XmlNode* XmlNodeList::getNode() const
{
    return node;
}

XmlNodeList* XmlNodeList::getNext() const
{
    return next;
}

void XmlNodeList::setNext(XmlNodeList* n)
{
    next = n;
}
