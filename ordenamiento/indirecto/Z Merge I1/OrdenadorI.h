#ifndef ORDENADOR_H
#define ORDENADOR_H

#include "IOrdenadorI.h"

template<typename T>
class Ordenador : public IOrdenador<T>{
protected:
    void intercambio(T*& a, T*& b);
};

#include "OrdenadorI.tpp"
#endif
