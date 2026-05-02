#ifndef PILA_H
#define PILA_H

class Pila
{
public:
    Pila();
    virtual ~Pila();

    virtual bool vacia() = 0;
    virtual bool llena() = 0;

protected:
    int tope;
private:

};

#endif // PILA_H
