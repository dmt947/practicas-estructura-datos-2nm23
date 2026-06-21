#ifndef BURBUJAI_H
#define BURBUJAI_H

#include "OrdenadorI.h"
#include <vector>
using namespace std;

template<typename T>
class Burbuja : public Ordenador<T>{
public:
    void ordenar(vector<T*>& datos) override;
};

#include "BurbujaI.tpp"
#endif
