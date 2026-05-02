#ifdef LISTA_H

template <typename T>
Lista<T>::Lista():Coleccion(), inicio(nullptr) {}

template <typename T>
Lista<T>::~Lista()
{
    while(!vacia())
    {
        remove(tam-1);
    }
}

template <typename T>
bool Lista<T>::vacia()
{
    return inicio == nullptr;
}

template <typename T>
int Lista<T>::longitud()
{
    return tam;
}

template <typename T>
bool Lista<T>::add(const T& elem, int pos)
{
    if(pos < 0 || pos > tam)
    {
        return false;
    }

    Nodo<T>* temp = new Nodo(elem);

    if(pos == 0)
    {
        temp->siguiente = inicio;
        inicio = temp;
        tam++;
        return true;
    }

    Nodo<T>* actual = inicio;
    for(int i = 0; i < pos - 1; i++)
    {
        actual = actual->siguiente;
    }
    temp->siguiente = actual->siguiente;
    actual->siguiente = temp;

    tam++;
    return true;
}

template <typename T>
bool Lista<T>::set(int pos, const T& elem)
{
    if(pos < 0 || pos > tam)
    {
        return false;
    }
    Nodo<T>* actual = inicio;
    for(int i = 0; i < pos; i++)
    {
        actual = actual->siguiente;
    }
    actual->dato = elem;
    return true;
}

template <typename T>
T Lista<T>::remove(int pos)
{
    if(vacia() || pos < 0 || pos > tam - 1)
    {
        return T();
    }
    Nodo<T>* aBorrar = nullptr;
    if(pos == 0)
    {
        aBorrar = inicio;
        inicio = nullptr;
    }
    else
    {
        Nodo<T>* anterior = inicio;
        for(int i = 0; i < pos - 1; i++)
        {
            anterior = anterior->siguiente;
        }
        Nodo<T>* aBorrar = anterior->siguiente;
        anterior->siguiente = aBorrar->siguiente;
    }

    T dato = aBorrar->dato;
    delete aBorrar;
    tam--;
    return dato;
}

template<typename T>
const T& Lista<T>::get(int pos)
{
    if(pos < 0 || pos > tam)
    {
        static T nulo = T();
        return nulo;
    }
    Nodo<T>* actual = inicio;
    for(int i = 0; i < pos; i++)
    {
        actual = actual->siguiente;
    }
    return actual->dato;
}

#endif // LISTA_H
