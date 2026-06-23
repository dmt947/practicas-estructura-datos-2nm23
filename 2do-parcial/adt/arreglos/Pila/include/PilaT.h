#ifndef PILAT_H
#define PILAT_H

#include "Nodo.h"
#include "Pila.h"

template <typename T>
class PilaT: public Pila
{
public:
    PilaT();
    virtual ~PilaT();

    bool vacia() override;
    bool llena() override;

    T pop();
    void push(const T&);
    T top();

protected:

private:
    static const int TAM = 32;
    Nodo<T> datos[TAM];
};

#include "../src/PilaT.tpp"

#endif // PILAT_H
