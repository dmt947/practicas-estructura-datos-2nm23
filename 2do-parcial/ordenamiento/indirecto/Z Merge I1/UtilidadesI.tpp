#ifndef UTILIDADESI_TPP
#define UTILIDADESI_TPP

#include <iostream>
#include <vector>
#include <string>

using namespace std;

template<typename T>
void Utilidades<T>::leer(vector<T>& v){
    cout << "Introduzca valores\n";
    for(size_t i = 0; i < v.size(); i++){
        cin >> v[i];
    }
}

template<typename T>
void Utilidades<T>::leerString(vector<T>& v){
    cout << "Introduzca valores\n";
    for(size_t i = 0; i < v.size(); i++){
        getline(cin >> ws, v[i]);
    }
}

template<typename T>
void Utilidades<T>::imprimir(const vector<T*>& v){
    for(size_t i = 0; i < v.size(); i++){
        cout << *v[i] << " ";
    }
    cout << endl;
}

template<typename T>
void Utilidades<T>::direcciones(vector<T*>& p, vector<T>& n){
    for(size_t i = 0; i < p.size(); i++){
        p[i] = &n[i];
    }
}

#endif
