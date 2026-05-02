#ifndef LISTA_H
#define LISTA_H

#include "Nodo.h"
#include "Coleccion.h"

template <typename T>
class Lista: public Coleccion
{
public:
    Lista();
    ~Lista();

    bool vacia() override;
    int longitud() override;

    bool add(const T& elem, int pos);

    bool set(int pos, const T& elem);

    T remove(int pos);

    const T& get(int pos);

protected:

private:
    Nodo<T>* inicio;
};

#include "../src/Lista.tpp"

#endif // LISTA_H
