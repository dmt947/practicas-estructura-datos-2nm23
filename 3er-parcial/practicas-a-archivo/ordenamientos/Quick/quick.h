#ifndef QUICK_H
#define QUICK_H
#include<iostream>
#include <string>
#include <vector>
using namespace std;
template<typename T> //Aux para cambiar 
void cambio(T* &N1,T* &N2){
	T* aux;
	aux = N1;
	N1 = N2;
	N2 = aux;
}
template<typename T>
int particion(vector<T*>& n,int inicio,int final){
	T* pivote=n[final];
	int p=inicio-1;
	for(int i=inicio;i<final;i++){
		if(*n[i]<*pivote){
			p++;
			cambio(n[i],n[p]);
			}
	}
	p++;
	cambio(n[final],n[p]);
	return p;
}
template<typename T>
void quicksort(vector<T*>& n,int inicio,int final){
	if(inicio<final){
		int pivote = particion(n,inicio,final);
		quicksort(n,inicio,pivote-1);
		quicksort(n,pivote+1,final);
	}
}
#endif
