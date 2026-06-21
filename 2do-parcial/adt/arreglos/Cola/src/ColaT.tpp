#ifdef COLAT_H

#include <iostream>
using namespace std;

template<typename T>
ColaT<T>::ColaT():Cola(){}

template<typename T>
ColaT<T>::~ColaT(){}

template <typename T>
bool ColaT<T>::vacia()
{
    return this->frente == -1;
}

template <typename T>
bool ColaT<T>::llena()
{
    return this->final == TAM - 1;
}

template <typename T>
void ColaT<T>::enqueue(const T& valor)
{
    if(llena())
    {
        cerr<<"Error: La cola esta llena." <<endl;
        return;
    }
    if(vacia())
    {
        this->frente = 0;
    }
    this->final++;
    datos[this->final].setDato(valor);
}

template <typename T>
T ColaT<T>::dequeue()
{
    if(vacia())
    {
        cerr<<"Error: La cola esta vacia." <<endl;
        return T();
    }

    T temp = datos[this->frente].getDato();
    datos[this->frente].setDato(T());

    if(this->frente == this->final)  // solo habia un elemento
    {
        this->frente = -1;
        this->final = -1;
    }
    else     // mas de un elemento
    {
        this->frente++;
    }

    return temp;
}

template <typename T>
T ColaT<T>::first()
{
    if(vacia())
    {
        cerr<<"Error: La cola esta vacia." <<endl;
        return T();
    }
    return datos[this->frente].getDato();
}

#endif
