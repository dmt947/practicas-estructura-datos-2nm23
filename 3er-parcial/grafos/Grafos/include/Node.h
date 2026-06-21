#ifndef NODE_H
#define NODE_H


class Node
{
public:
    Node(const char* n);
    ~Node();

    const char* getName() const;
    void setName(const char* n);
protected:

private:
    char* name;
};

#endif // NODE_H
