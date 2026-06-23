#ifndef FUNCIONES_H
#define FUNCIONES_H
#include<iostream>
#include <string>
#include <vector>
using namespace std;
template<typename T> //Aux para cambiar 
void direcciones(vector<T*>& N,vector<T>& n){
	for(size_t i= 0;i<N.size();i++){
		N[i]= &n[i];
	}
}
template<typename T>
void declaracion(vector<T>& n_){
	cout<<"Introduzca los valores"<<endl;
	for(int i=0;i<n_.size();i++){ //Pide datos hasta llenar el arreglo
		cin>>n_[i];	
	}
}

template<typename T>
void declaracionString(vector<T>& n_){ //Especializacion para string. 
	cout<<"Introduzca los valores"<<endl;
	for(size_t i = 0; i < n_.size(); i++){   //size_t tipo de dato para tamaños de arreglo
		getline(cin >> ws, n_[i]);   //ws limpia espacio en blanco.Se guardan los datos en n_[i]
	}
}

template<typename T>
void impresion(const vector<T*>& n_){
	for(size_t i=0;i<n_.size();i++){
		cout<<*n_[i]<<" ";
	}
	cout<<endl;
}
#endif
