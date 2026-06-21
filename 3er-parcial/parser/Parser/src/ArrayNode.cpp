#include "ArrayNode.h"

ArrayNode::ArrayNode(JsonValue* val)
{
    value = val;
    next = nullptr;
}

ArrayNode::~ArrayNode()
{
    if(value != nullptr)
    {
        delete value;
    }
    if(next != nullptr)
    {
        delete next;
    }
}

JsonValue* ArrayNode::getValue() const
{
    return value;
}

ArrayNode* ArrayNode::getNext() const
{
    return next;
}

void ArrayNode::setNext(ArrayNode* nextNode)
{
    next = nextNode;
}
