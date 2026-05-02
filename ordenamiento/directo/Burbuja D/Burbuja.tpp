#ifndef BURBUJA_TPP
#define BURBUJA_TPP

#include <vector>
using namespace std;

template<typename T>
void Burbuja<T>::ordenar(vector<T>& datos){
    int n = datos.size();

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n - 1 - i; j++){
            if(datos[j] > datos[j + 1]){
                this->intercambio(datos[j], datos[j + 1]);
            }
        }
    }
}

#endif
