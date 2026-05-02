#ifndef ORDENADOR_H
#define ORDENADOR_H

#include "IOrdenador.h"

template<typename T>
class Ordenador : public IOrdenador<T>{
protected:
    void intercambio(T &a, T &b);
};

#include "Ordenador.tpp"

#endif
