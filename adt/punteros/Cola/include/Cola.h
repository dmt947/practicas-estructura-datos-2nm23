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

    bool vacia() const override;
    int longitud() const override;

    bool enqueue(const T& elem);
    T dequeue();
    const T& front() const;

protected:

private:
    Nodo<T>* frente;
    Nodo<T>* final;
};

#include "../src/Cola.tpp"

#endif // COLA_H
