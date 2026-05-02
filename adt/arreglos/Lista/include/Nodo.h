#ifndef NODO_H
#define NODO_H

template <typename T>
class Nodo
{
public:
    Nodo();
    Nodo(const T& d);
    ~Nodo();
    T getDato();
    void setDato(const T& d);

protected:

private:
    T dato;
};

#include "../src/Nodo.tpp"

#endif // NODO_H
