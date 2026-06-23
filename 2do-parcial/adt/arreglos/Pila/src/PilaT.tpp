#ifdef PILAT_H
#include <iostream>
using namespace std;

template <typename T>
PilaT<T>::PilaT()
{
    this->tope = -1;
}

template <typename T>
PilaT<T>::~PilaT() {}

template <typename T>
bool PilaT<T>::vacia()
{
    return this->tope == -1;
}

template <typename T>
bool PilaT<T>::llena()
{
    return this->tope == TAM - 1;
}

template <typename T>
void PilaT<T>::push(const T& valor)
{
    if(llena())
    {
        cerr<<"Error: La pila esta llena." <<endl;
        return;
    }
    this->tope++;
    datos[this->tope].setDato(valor);
}

template <typename T>
T PilaT<T>::pop()
{
    if(vacia())
    {
        cerr<<"Error: La pila esta vacia." <<endl;
        return T(); // Valor por defecto
    }
    T temp = datos[this->tope].getDato();
    datos[this->tope].setDato(T());
    this->tope--;

    return temp;
}

template <typename T>
T PilaT<T>::top()
{
    if(vacia())
    {
        cerr<<"Error: La pila esta vacia." <<endl;
        return T();
    }
    else
    {
        return datos[this->tope].getDato();
    }
}

#endif // PILAT_H
