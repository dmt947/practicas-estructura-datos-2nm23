#ifndef QUICKI_TPP
#define QUICKI_TPP

template<typename T>
void Quick<T>::ordenar(vector<T*>& n) {
    if (n.empty()) return;
    quicksort(n, 0, n.size() - 1);
}

template<typename T>
int Quick<T>::particion(vector<T*>& n, int inicio, int final) {
    T* pivote = n[final];
    int p = inicio - 1;

    for (int i = inicio; i < final; i++) {
        if (*n[i] < *pivote) {
            p++;
            this->intercambio(n[i], n[p]);
        }
    }

    p++;
    this->intercambio(n[p], n[final]);

    return p;
}


template<typename T>
void Quick<T>::quicksort(vector<T*>& n, int inicio, int final) {
    if (inicio < final) {
        int pivote = particion(n, inicio, final);

        quicksort(n, inicio, pivote - 1);
        quicksort(n, pivote + 1, final);
    }
}


#endif
