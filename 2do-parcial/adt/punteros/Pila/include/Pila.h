#ifndef PILA_H
#define PILA_H

#include "Coleccion.h"
#include "Nodo.h"

template <typename T>
class Pila: public Coleccion
{
public:
    Pila();
    ~Pila();

    bool vacia() const override;
    int longitud() const override;

    bool push(const T& elem);
    T pop();
    const T& peek() const;

protected:

private:
    Nodo<T>* tope;
};

#include "../src/Pila.tpp"

#endif // PILA_H
