#ifdef PILA_H

template <typename T>
Pila<T>::Pila():Coleccion(),tope(nullptr) {}

template <typename T>
Pila<T>::~Pila()
{
    while(!vacia())
    {
        pop();
    }
}

template <typename T>
bool Pila<T>::vacia() const
{
    return tope == nullptr;
}

template <typename T>
int Pila<T>::longitud() const
{
    return tam;
}

template <typename T>
bool Pila<T>::push(const T& elem)
{
    Nodo<T>* temp = new Nodo<T>(elem);
    temp->siguiente = tope;
    tope = temp;
    tam++;
    return true;
}

template <typename T>
T Pila<T>::pop()
{
    if(vacia())
    {
        return T();
    }

    T temp = tope->dato;
    Nodo<T>* aux = tope;
    tope = tope->siguiente;

    delete aux;
    tam--;
    return temp;
}

template <typename T>
const T& Pila<T>::peek() const
{
    if(vacia())
    {
        static T nulo = T();
        return nulo;
    }

    return tope->dato;
}
#endif // PILA_H
