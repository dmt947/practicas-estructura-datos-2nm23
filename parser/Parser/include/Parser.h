#ifndef PARSER_H
#define PARSER_H


class Parser
{
public:
    Parser(const char* txt);
    virtual ~Parser();
    virtual void* parse() = 0;
    bool failed() const;

protected:
    const char* text;
    bool error;
    int pos;

    void skipSpaces();

private:
};

#endif // PARSER_H
