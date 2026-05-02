#ifndef BURBUJA_H
#define BURBUJA_H

#include "Ordenador.h"
#include <vector>
using namespace std;

template<typename T>
class Burbuja : public Ordenador<T>{
public:
    void ordenar(vector<T>& datos) override;
};

#include "Burbuja.tpp"

#endif
