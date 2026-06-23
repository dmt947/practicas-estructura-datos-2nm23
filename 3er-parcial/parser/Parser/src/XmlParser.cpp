#include "XmlParser.h"

XmlParser::XmlParser(const char* txt) : Parser(txt) {}

XmlParser::~XmlParser() {}

bool XmlParser::stringsEqual(const char* s1, const char* s2)
{
    if (s1 == nullptr || s2 == nullptr) return false;
    int i = 0;
    while (s1[i] != '\0' && s2[i] != '\0')
    {
        if (s1[i] != s2[i]) return false;
        i++;
    }
    return s1[i] == s2[i];
}

char* XmlParser::parseTagName()
{
    if (text[pos] != '<')
    {
        error = true;
        return nullptr;
    }
    pos++;

    if (text[pos] == '/')
    {
        pos--;
        return nullptr;
    }

    int start = pos;
    while (text[pos] != '\0' && text[pos] != '>' && text[pos] != ' ' && text[pos] != '/')
    {
        pos++;
    }

    int len = pos - start;
    if (len == 0)
    {
        error = true;
        return nullptr;
    }

    char* tagName = new char[len + 1];
    for (int i = 0; i < len; i++)
    {
        tagName[i] = text[start + i];
    }
    tagName[len] = '\0';

    while (text[pos] != '\0' && text[pos] != '>')
    {
        pos++;
    }

    if (text[pos] == '>') pos++;
    return tagName;
}

char* XmlParser::parseTextContent()
{
    int start = pos;
    while (text[pos] != '\0' && text[pos] != '<')
    {
        pos++;
    }

    int len = pos - start;
    if (len == 0) return nullptr;

    char* content = new char[len + 1];
    for (int i = 0; i < len; i++)
    {
        content[i] = text[start + i];
    }
    content[len] = '\0';
    return content;
}

XmlNode* XmlParser::parseElement()
{
    if (error) return nullptr;
    skipSpaces();

    char* tagName = parseTagName();
    if (error || tagName == nullptr)
    {
        if (tagName) delete[] tagName;
        return nullptr;
    }

    XmlNode* currentNode = new XmlNode(tagName);
    delete[] tagName;

    skipSpaces();

    while (text[pos] != '\0')
    {
        skipSpaces();

        if (text[pos] == '<')
        {
            if (text[pos + 1] == '/')
            {
                pos += 2;
                int startClose = pos;
                while (text[pos] != '\0' && text[pos] != '>') pos++;

                int lenClose = pos - startClose;
                char* closeName = new char[lenClose + 1];
                for(int i = 0; i < lenClose; i++) closeName[i] = text[startClose + i];
                closeName[lenClose] = '\0';

                if (text[pos] == '>') pos++;

                if (!stringsEqual(currentNode->getTag(), closeName))
                {
                    error = true;
                }

                delete[] closeName;
                return currentNode;
            }
            else
            {
                XmlNode* child = parseElement();
                if (error)
                {
                    delete currentNode;
                    return nullptr;
                }
                currentNode->addChild(child);
            }
        }
        else
        {
            char* textData = parseTextContent();
            if (textData != nullptr)
            {
                currentNode->setContent(textData);
                delete[] textData;
            }
        }
    }

    error = true;
    delete currentNode;
    return nullptr;
}

void* XmlParser::parse()
{
    skipSpaces();
    if (text[pos] == '<' && text[pos + 1] == '?')
    {
        while (text[pos] != '\0' && text[pos] != '>') pos++;
        if (text[pos] == '>') pos++;
        skipSpaces();
    }

    XmlNode* root = parseElement();
    skipSpaces();

    if (text[pos] != '\0' || error)
    {
        error = true;
        if (root != nullptr) delete root;
        return nullptr;
    }

    return (void*)root;
}
