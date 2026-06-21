#ifndef MERGE_H
#define MERGE_H
#include<iostream>
#include <string>
#include<vector>
using namespace std;
template<typename T>
void cambio(T &N1,T &N2){
	T aux;
			aux = N1;
			N1=N2;
			N2= aux;
}
template<typename T>
void merge(vector<T*>& n,int inicio,int mitad,int final){
	int i=inicio,j=mitad+1,k=0;
	vector<T*> aux(final - inicio + 1);
	while(i<=mitad && j<=final){
		if(*n[i]<*n[j]){
			aux[k]=n[i];
			i++;
		}
		else{
			aux[k]=n[j];
			j++;
		}
		k++;
	}
	while(i<=mitad){
		aux[k]=n[i];
		i++;
		k++;
	}
	while(j<=final){
		aux[k]=n[j];
		j++;
		k++;
	}
	for(int h=0;h<k;h++){
		n[inicio+h]=aux[h];
	}
}
template<typename T>
void mergesort(vector<T*>& n,int inicio,int final){
	if(inicio<final){
		int mitad=(inicio+final)/2;
		mergesort(n,inicio,mitad);
		mergesort(n,mitad+1,final);
		merge(n,inicio,mitad,final);
	}
	
}
#endif
