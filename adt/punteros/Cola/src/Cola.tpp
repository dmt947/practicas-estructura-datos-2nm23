#ifdef COLA_H

template <typename T>
Cola<T>::Cola():Coleccion(),frente(nullptr),final(nullptr) {}

template <typename T>
Cola<T>::~Cola()
{
    while(!vacia())
    {
        dequeue();
    }
}

template <typename T>
bool Cola<T>::vacia()
{
    return frente == nullptr;
}

template <typename T>
int Cola<T>::longitud()
{
    return this->tam;
}

template <typename T>
bool Cola<T>::enqueue(const T& elem)
{
    Nodo<T>* temp = new Nodo<T>(elem);
    if(vacia())
    {
        frente = temp;
        final = temp;
    }
    else
    {
        final->siguiente = temp;
        final = temp;
    }
    this->tam++;
    return true;
}

template <typename T>
T Cola<T>::dequeue()
{
    if(vacia())
    {
        return T();
    }

    T temp = frente->dato;
    Nodo<T>* aux = frente;
    frente = frente->siguiente;

    if(frente == nullptr)
    {
        final = nullptr;
    }

    delete aux;
    this->tam--;
    return temp;
}

template <typename T>
const T& Cola<T>::front()
{
    if(vacia())
    {
        static T nulo = T();
        return nulo;
    }

    return frente->dato;
}
#endif // COLA_H
