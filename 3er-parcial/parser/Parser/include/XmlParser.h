#ifndef XMLPARSER_H
#define XMLPARSER_H

#include "Parser.h"

class XmlNode;
#include "XmlNode.h"
class XmlNodeList;
#include "XmlNodeList.h"

class XmlParser : public Parser
{
public:
    XmlParser(const char* txt);
    virtual ~XmlParser();

    void* parse() override;

protected:

private:
    char* parseTagName();
    char* parseTextContent();
    XmlNode* parseElement();
    bool stringsEqual(const char* s1, const char* s2);
};

#endif // XMLPARSER_H
