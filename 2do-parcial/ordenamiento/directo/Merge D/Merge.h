#ifndef MERGE_H
#define MERGE_H

#include <vector>
using namespace std;

// Clase Merge
template<typename T>
class Merge : public Ordenador<T> {
public:
    void ordenar(vector<T>& v) override;

private:
    void merge(vector<T>& n, int inicio, int mitad, int final);
    void mergeSort(vector<T>& n, int inicio, int final);
};

#include "Merge.tpp"

#endif
