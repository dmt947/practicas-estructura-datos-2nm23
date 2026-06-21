#include "JsonValue.h"

JsonValue::JsonValue()
{
    type = JSON_NULL;
    num = 0.0;
    str = nullptr;
    arr = nullptr;
    obj = nullptr;
}

JsonValue::~JsonValue()
{
    if(type == JSON_STRING && str != nullptr)
    {
        delete[] str;
    }
    else if(type == JSON_ARRAY && arr != nullptr)
    {
        delete arr;
    }
    else if(type == JSON_OBJECT && obj != nullptr)
    {
        delete obj;
    }
}

void JsonValue::setNum(double n)
{
    type = JSON_NUMBER;
    num = n;
}
void JsonValue::setStr(char* s)
{
    type = JSON_STRING;
    str = s;
}
void JsonValue::setArr(ArrayNode* a)
{
    type = JSON_ARRAY;
    arr = a;
}
void JsonValue::setObj(ObjectNode* o)
{
    type = JSON_OBJECT;
    obj = o;
}

JsonType JsonValue::getType() const
{
    return type;
}
double JsonValue::getNum() const
{
    return num;
}
const char* JsonValue::getStr() const
{
    return str;
}
ArrayNode* JsonValue::getArr() const
{
    return arr;
}
ObjectNode* JsonValue::getObj() const
{
    return obj;
}
