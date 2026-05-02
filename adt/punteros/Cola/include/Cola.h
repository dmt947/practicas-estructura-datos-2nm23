#ifndef COLA_H
#define COLA_H

#include "Coleccion.h"
#include "Nodo.h"

template <typename T>
class Cola: public Coleccion
{
public:
    Cola();
    ~Cola();

    bool vacia() override;
    int longitud() override;

    bool enqueue(const T& elem);
    T dequeue();
    const T& front();

protected:

private:
    Nodo<T>* frente;
    Nodo<T>* final;
};

#include "../src/Cola.tpp"

#endif // COLA_H
