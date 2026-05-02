#ifndef ORDENADORI_TPP
#define ORDENADORI_TPP

template<typename T>
void Ordenador<T>::intercambio(T*& a, T*& b){
    T* aux = a;
    a = b;
    b = aux;
}

#endif
