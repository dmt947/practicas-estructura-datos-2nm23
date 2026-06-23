#ifndef NODO_H
#define NODO_H

template <typename T>
class Nodo
{
public:
    T dato;
    Nodo<T>* siguiente;

    Nodo(const T& valor);
    virtual ~Nodo();

protected:

private:
};

#include "../src/Nodo.tpp"

#endif // NODO_H
