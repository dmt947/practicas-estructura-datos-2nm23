#ifndef JSONVALUE_H
#define JSONVALUE_H

class ArrayNode;
#include "ArrayNode.h"
class ObjectNode;
#include "ObjectNode.h"

enum JsonType
{
    JSON_NULL,
    JSON_NUMBER,
    JSON_STRING,
    JSON_ARRAY,
    JSON_OBJECT
};

class JsonValue
{
public:
    JsonValue();
    ~JsonValue();

    void setNum(double n);
    void setStr(char* s);
    void setArr(ArrayNode* a);
    void setObj(ObjectNode* o);

    JsonType getType() const;
    double getNum() const;
    const char* getStr() const;
    ArrayNode* getArr() const;
    ObjectNode* getObj() const;

protected:

private:
    JsonType type;
    double num;
    char* str;
    ArrayNode* arr;
    ObjectNode* obj;
};

#endif // JSONVALUE_H
