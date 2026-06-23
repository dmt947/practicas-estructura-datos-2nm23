#ifndef MERGEI_TPP
#define MERGEI_TPP

template<typename T>
void Merge<T>::ordenar(vector<T*>& v){
    if(v.empty()) return;
    mergeSort(v, 0, v.size() - 1);
}

template<typename T>
void Merge<T>::mergeSort(vector<T*>& v, int izq, int der){
    if(izq >= der) return;

    int mid = izq + (der - izq) / 2;

    mergeSort(v, izq, mid);
    mergeSort(v, mid + 1, der);
    merge(v, izq, mid, der);
}

template<typename T>
void Merge<T>::merge(vector<T*>& v, int izq, int mid, int der){
    vector<T*> aux;

    int i = izq;
    int j = mid + 1;

    while(i <= mid && j <= der){
        if(*v[i] < *v[j]){
            aux.push_back(v[i]);
            i++;
        }else{
            aux.push_back(v[j]);
            j++;
        }
    }

    while(i <= mid){
        aux.push_back(v[i]);
        i++;
    }

    while(j <= der){
        aux.push_back(v[j]);
        j++;
    }

    for(size_t k = 0; k < aux.size(); k++){
        v[izq + k] = aux[k];
    }
}

#endif
