#ifndef BURBUJAI_TPP
#define BURBUJAI_TPP

template<typename T>
void Burbuja<T>::ordenar(vector<T*>& datos){
    for(size_t i = 0; i < datos.size(); i++){
        for(size_t j = 0; j < datos.size() - 1 - i; j++){
            if(*datos[j] > *datos[j + 1]){
                this->intercambio(datos[j], datos[j + 1]);
            }
        }
    }
}

#endif
