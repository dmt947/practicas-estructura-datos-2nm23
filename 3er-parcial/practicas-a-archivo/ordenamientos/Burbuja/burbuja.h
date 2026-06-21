#ifndef BURBUJA_H
#define BURBUJA_H
#include <iostream>
#include <string>
#include <vector>
#include "persona.h"
using namespace std;
template<typename T> //Aux para cambiar 
void cambio(T* &N1,T* &N2){
	T* aux;
	aux = N1;
	N1 = N2;
	N2 = aux;
}

template<typename T>
void burbuja(vector<T*>& N){   //Recibe el arreglo de cualquier tipo de dato
	for(size_t i=0;i<N.size();i++){  //Repite el recorrido del arreglo. Se ordena una posicion por iteracion.
		for(int j=0;j<N.size()-1-i;j++){	    //Selecciona la posicion 0 (inicio del arreglo) y lo recorre hasta Ca-1 (Final del arreglo). Despues de cada iteracion recorre 1 posicion menos porque la ultima posicion ya esta ordenada
			if(*N[j] > *N[j+1]){         //Si el valor actual es mayo que el siguiente ...
				cambio(N[j], N[j+1]); //Cambia el valor de la posicion actual con el siguiente y viceversa
			}
		}
	}
}
#endif
