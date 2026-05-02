#ifndef COLAT_H
#define COLAT_H

#include "Cola.h"
#include "Nodo.h"

template <typename T>
class ColaT:public Cola
{
public:
    ColaT();
    ~ColaT();

    bool llena() override;
    bool vacia() override;

    T dequeue();
    void enqueue(const T& valor);
    T first();

protected:

private:
    static const int TAM = 32;
    Nodo<T> datos[TAM];
};

#include "../src/ColaT.tpp"

#endif // COLAT_H
