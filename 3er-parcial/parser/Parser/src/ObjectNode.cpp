#include "ObjectNode.h"

ObjectNode::ObjectNode(char* k, JsonValue* val)
{
    key = k;
    value = val;
    next = nullptr;
}

ObjectNode::~ObjectNode()
{
    if(key != nullptr)
    {
        delete[] key;
    }
    if(value != nullptr)
    {
        delete value;
    }
    if(next != nullptr)
    {
        delete next;
    }
}

const char* ObjectNode::getKey() const
{
    return key;
}

JsonValue* ObjectNode::getValue() const
{
    return value;
}

ObjectNode* ObjectNode::getNext() const
{
    return next;
}

void ObjectNode::setNext(ObjectNode* nextNode)
{
    next = nextNode;
}
