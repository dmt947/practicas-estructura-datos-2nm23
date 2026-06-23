#ifndef OBJECTNODE_H
#define OBJECTNODE_H

class JsonValue;
#include "JsonValue.h"

class ObjectNode
{
public:
    ObjectNode(char* k, JsonValue* val);
    ~ObjectNode();

    const char* getKey() const;
    JsonValue* getValue() const;
    ObjectNode* getNext() const;

    void setNext(ObjectNode* nextNode);

protected:

private:
    char* key;
    JsonValue* value;
    ObjectNode* next;
};

#endif // OBJECTNODE_H
