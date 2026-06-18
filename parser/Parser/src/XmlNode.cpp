#include "XmlNode.h"

char* XmlNode::cloneString(const char* src)
{
    if (src == nullptr) return nullptr;
    int len = 0;
    while (src[len] != '\0') len++;
    char* dest = new char[len + 1];
    for (int i = 0; i < len; i++)
    {
        dest[i] = src[i];
    }
    dest[len] = '\0';
    return dest;
}

XmlNode::XmlNode(const char* tagName)
{
    tag = cloneString(tagName);
    content = nullptr;
    children = nullptr;
    lastChild = nullptr;
}

XmlNode::~XmlNode()
{
    if (tag != nullptr) delete[] tag;
    if (content != nullptr) delete[] content;
    if (children != nullptr)
    {
        XmlNodeList* current = children;
        while (current != nullptr)
        {
            if (current->getNode()!= nullptr)
            {
                delete current->getNode();
            }
            current = current->getNext();
        }
        delete children;
    }
}

void XmlNode::setContent(const char* text)
{
    if (content != nullptr) delete[] content;
    content = cloneString(text);
}

void XmlNode::addChild(XmlNode* child)
{
    if (child == nullptr) return;
    XmlNodeList* newNodeElement = new XmlNodeList(child);
    if (children == nullptr)
    {
        children = newNodeElement;
    }
    else
    {
        lastChild->setNext(newNodeElement);
    }
    lastChild = newNodeElement;
}

const char* XmlNode::getTag() const
{
    return tag;
}
const char* XmlNode::getContent() const
{
    return content;
}
XmlNodeList* XmlNode::getChildren() const
{
    return children;
}
