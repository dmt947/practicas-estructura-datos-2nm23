#ifndef UTILIDADES_H
#define UTILIDADES_H

#include <vector>
#include <string>
using namespace std;

template<typename T>
class Utilidades{
public:
    static void leer(vector<T>& v);
    static void leerString(vector<T>& v);
    static void imprimir(const vector<T>& v);
};

#include "Utilidades.tpp"

#endif
