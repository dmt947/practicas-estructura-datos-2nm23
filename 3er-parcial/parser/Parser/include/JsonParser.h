#ifndef JSONPARSER_H
#define JSONPARSER_H

#include "Parser.h"

class JsonValue;
#include "JsonValue.h"

class JsonParser : public Parser
{
public:
    JsonParser(const char* txt);
    ~JsonParser();
    virtual void* parse() override;

protected:

private:

    JsonValue* parseValue();
    JsonValue* parseObject();
    JsonValue* parseArray();
    char* parseRawString();
    JsonValue* parseString();
    JsonValue* parseNumber();
};

#endif // JSONPARSER_H
