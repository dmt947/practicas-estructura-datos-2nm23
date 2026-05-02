#ifdef LISTAT_H

#include <iostream>
using namespace std;
template <typename T>
ListaT<T>::ListaT():Lista() {}

template <typename T>
ListaT<T>::~ListaT() {}


template <typename T>
bool ListaT<T>::vacia()
{
    return this->ultimo == -1;
}

template <typename T>
bool ListaT<T>::llena()
{
    return this->ultimo == TAM - 1;
}

template <typename T>
void ListaT<T>::insertar(T valor, int pos)
{
    if(llena() || pos < 0 || pos > longitud())
    {
        cerr<<"Error: La lista esta vacia." <<endl;
        return;
    }
    for(int i = this->ultimo; i>= pos; i--)
    {
        datos[i+1].setDato(datos[i].getDato());
    }
    datos[pos].setDato(valor);
    this->ultimo++;
}

template <typename T>
void ListaT<T>::eliminar(int pos)
{
    if(vacia() || pos < 0 || pos > this->ultimo)
    {
        cerr<<"Error: La lista esta vacia." <<endl;
        return;
    }
    for(int i = pos; i < this->ultimo; i++)
    {
        datos[i].setDato(datos[i+1].getDato());
    }
    datos[this->ultimo].setDato(T());
    this->ultimo--;
}

template <typename T>
T ListaT<T>::obtener(int pos)
{
    if(vacia() || pos < 0 || pos > this->ultimo)
    {
        cerr<<"Error: La lista esta vacia." <<endl;
        return T();
    }

    return datos[pos].getDato();
}

#endif // LISTAT_H
