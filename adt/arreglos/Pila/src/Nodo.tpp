#ifdef NODO_H

template <typename T>
Nodo<T>::Nodo(): dato(T()) {}

template <typename T>
Nodo<T>::Nodo(const T& d):dato(d) {}

template <typename T>
Nodo<T>::~Nodo() {}

template <typename T>
T Nodo<T>::getDato()
{
    return dato;
}

template <typename T>
void Nodo<T>::setDato(const T& d)
{
    dato = d;
}

#endif // NODO_H
