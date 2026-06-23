#ifndef MERGEI_H
#define MERGEI_H

#include <vector>
#include "OrdenadorI.h"

using namespace std;

template<typename T>
class Merge : public Ordenador<T>{
public:
    void ordenar(vector<T*>& v) override;

private:
    void mergeSort(vector<T*>& v, int izq, int der);
    void merge(vector<T*>& v, int izq, int mid, int der);
};

#include "MergeI.tpp"
#endif
