#include "Parser.h"

Parser::Parser(const char* txt)
{
    text = txt;
    error = false;
    pos = 0;
}

Parser::~Parser() {}

bool Parser::failed() const
{
    return error;
}

void Parser::skipSpaces()
{
    while(text[pos] != '\0' && (text[pos] == ' ' || text[pos] == '\n' || text[pos] == '\t'))
    {
        pos++;
    }
}

