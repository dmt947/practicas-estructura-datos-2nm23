#ifndef MERGE_TPP
#define MERGE_TPP

#include "Merge.h"
template<typename T>
void Merge<T>::ordenar(vector<T>& v) {
    if (v.empty()) return;
    mergeSort(v, 0, v.size() - 1);
}

template<typename T>
void Merge<T>::mergeSort(vector<T>& n, int inicio, int final) {
    if (inicio >= final) return;

    int mitad = inicio + (final - inicio) / 2;

    mergeSort(n, inicio, mitad);
    mergeSort(n, mitad + 1, final);

    merge(n, inicio, mitad, final);
}

template<typename T>
void Merge<T>::merge(vector<T>& n, int inicio, int mitad, int final) {
    int i = inicio, j = mitad + 1, k = 0;

    vector<T> aux(final - inicio + 1);

    while (i <= mitad && j <= final) {
        if (n[i] < n[j]) {
            aux[k] = n[i];
            i++;
        } else {
            aux[k] = n[j];
            j++;
        }
        k++;
    }

    while (i <= mitad) {
        aux[k] = n[i];
        i++;
        k++;
    }

    while (j <= final) {
        aux[k] = n[j];
        j++;
        k++;
    }

    for (int h = 0; h < k; h++) {
        n[inicio + h] = aux[h];
    }
}

#endif
