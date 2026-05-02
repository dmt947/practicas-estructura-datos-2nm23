#ifdef NODO_H

template <typename T>
Nodo<T>::Nodo(const T& valor):dato(valor), siguiente(nullptr) {}

template <typename T>
Nodo<T>::~Nodo() {}

#endif // NODO_H
