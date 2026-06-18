#ifndef ARRAYNODE_H
#define ARRAYNODE_H

class JsonValue;
#include "JsonValue.h"

class ArrayNode
{
public:
    ArrayNode(JsonValue* val);
    ~ArrayNode();

    JsonValue* getValue() const;
    ArrayNode* getNext() const;
    void setNext(ArrayNode* nextNode);

protected:

private:
    JsonValue* value;
    ArrayNode* next;
};

#endif // ARRAYNODE_H
