#include "JsonParser.h"
#include <cstdlib>

JsonParser::JsonParser(const char* txt) : Parser(txt) {}

JsonParser::~JsonParser() {}

void* JsonParser::parse()
{
    skipSpaces();
    JsonValue* root = parseValue();
    skipSpaces();
    if (text[pos] != '\0' || error)
    {
        error = true;
        if (root != nullptr) delete root;
        return nullptr;
    }
    return (void*)root;
}

JsonValue* JsonParser::parseValue()
{
    if (error) return nullptr;
    skipSpaces();
    char c = text[pos];
    if(c == '{') return parseObject();
    if(c == '[') return parseArray();
    if(c == '"') return parseString();
    if((c >= '0' && c <= '9') || c == '-') return parseNumber();
    error = true;
    return nullptr;
}

char* JsonParser::parseRawString()
{
    if (text[pos] != '"')
    {
        error = true;
        return nullptr;
    }
    pos++;
    int start = pos;
    while(text[pos] != '\0' && text[pos] != '"') pos++;
    if (text[pos] == '\0')
    {
        error = true;
        return nullptr;
    }
    int len = pos - start;
    char* str = new char[len + 1];
    for(int i = 0; i < len; i++) str[i] = text[start + i];
    str[len] = '\0';
    pos++;
    return str;
}

JsonValue* JsonParser::parseString()
{
    char* str = parseRawString();
    if (error || !str) return nullptr;
    JsonValue* value = new JsonValue();
    value->setStr(str);
    return value;
}

JsonValue* JsonParser::parseNumber()
{
    if (error) return nullptr;
    int start = pos;
    while(text[pos] != '\0' && ((text[pos] >= '0' && text[pos] <= '9') || text[pos] == '.' || text[pos] == '-')) pos++;
    int len = pos - start;
    if (len == 0)
    {
        error = true;
        return nullptr;
    }
    char* temp = new char[len + 1];
    for(int i = 0; i < len; i++) temp[i] = text[start + i];
    temp[len] = '\0';
    JsonValue* value = new JsonValue();
    value->setNum(atof(temp));
    delete[] temp;
    return value;
}

JsonValue* JsonParser::parseArray()
{
    if (error) return nullptr;
    pos++;

    JsonValue* arr = new JsonValue();
    arr->setArr(nullptr);

    ArrayNode* last = nullptr;
    skipSpaces();

    while(text[pos] != '\0' && text[pos] != ']')
    {
        JsonValue* item = parseValue();
        if (error)
        {
            if(item != nullptr) delete item;
            delete arr;
            return nullptr;
        }

        ArrayNode* node = new ArrayNode(item);

        if(arr->getArr() == nullptr)
        {
            arr->setArr(node);
        }
        else
        {
            last->setNext(node);
        }

        last = node;
        skipSpaces();

        if(text[pos] == ',')
        {
            pos++;
            skipSpaces();
            if (text[pos] == ']')
            {
                error = true;
                delete arr;
                return nullptr;
            }
        }
        else if (text[pos] != ']')
        {
            error = true;
            delete arr;
            return nullptr;
        }
    }

    if (text[pos] == '\0')
    {
        error = true;
        delete arr;
        return nullptr;
    }
    pos++;
    return arr;
}

JsonValue* JsonParser::parseObject()
{
    if (error) return nullptr;
    pos++;

    JsonValue* obj = new JsonValue();
    obj->setObj(nullptr);

    ObjectNode* last = nullptr;
    skipSpaces();

    while(text[pos] != '\0' && text[pos] != '}')
    {
        char* key = parseRawString();
        if (error || !key)
        {
            if(key) delete[] key;
            delete obj;
            return nullptr;
        }

        skipSpaces();
        if (text[pos] != ':')
        {
            delete[] key;
            error = true;
            delete obj;
            return nullptr;
        }
        pos++;

        skipSpaces();
        JsonValue* value = parseValue();
        if (error)
        {
            delete[] key;
            delete obj;
            return nullptr;
        }

        ObjectNode* node = new ObjectNode(key, value);

        if(obj->getObj() == nullptr)
        {
            obj->setObj(node);
        }
        else
        {
            last->setNext(node);
        }

        last = node;
        skipSpaces();

        if(text[pos] == ',')
        {
            pos++;
            skipSpaces();
            if (text[pos] == '}')
            {
                error = true;
                delete obj;
                return nullptr;
            }
        }
        else if (text[pos] != '}')
        {
            error = true;
            delete obj;
            return nullptr;
        }
    }

    if (text[pos] == '\0')
    {
        error = true;
        delete obj;
        return nullptr;
    }
    pos++;
    return obj;
}
