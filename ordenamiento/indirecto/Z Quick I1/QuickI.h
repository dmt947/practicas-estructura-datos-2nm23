#ifndef QUICKI_H
#define QUICKI_H

#include <vector>
#include "OrdenadorI.h"
using namespace std;

template<typename T>
class Quick : public Ordenador<T> {
public:
    void ordenar(vector<T*>& n) override;

private:
    int particion(vector<T*>& n, int inicio, int final);
    void quicksort(vector<T*>& n, int inicio, int final);
};

#include "QuickI.tpp"

#endif
