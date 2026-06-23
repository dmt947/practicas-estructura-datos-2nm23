#ifndef LISTAT_H
#define LISTAT_H
#include "Lista.h"
#include "Nodo.h"

template <typename T>
class ListaT:public Lista
{
public:
    ListaT();
    virtual ~ListaT();

    bool vacia() override;
    bool llena() override;


    void insertar(T valor, int pos);
    void eliminar(int pos);
    T obtener(int pos);


protected:

private:
    static const int TAM = 32;
    Nodo<T> datos[TAM];
};

#include "../src/ListaT.tpp"

#endif // LISTAT_H
