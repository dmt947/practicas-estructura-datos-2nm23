#include<iostream>
#include <string>
#include <vector>
#include "funciones.h"
#include "persona.h"
#include "merge.h"
#include "json.h"
#include "txt.h"
#include "cvs.h"
#include "xml.h"
using namespace std;
int main(){
	int CA=0,i=0,TV=0;
	cout<<"Cantidad de valores"<<endl;
	cin>>CA;
	cout<<"Tipos de valores Entero(1)/Flotante(2)/Cadena(3)/Estructura(4)"<<endl;
	cin>>TV;
	if(TV == 1){
		vector<int> n(CA);
		vector<int*> o(CA);
		vector<int*> p(CA);
		declaracion(n);
		direcciones(p,n);
		direcciones(o,n);
		cout << "\nOrden original:\n";  
		impresion(p);
		mergesort(p,0,CA-1);
		cout << "\nOrdenado:\n";
		impresion(p);
		guardarJSON(o,p,"datosMerge.json");
		guardarTXT(o, p, "datosMerge.txt");
		guardarCSV(o, p, "datosMerge.csv");
		guardarXML(o, p, "datosMerge.xml");
	}
	else if(TV == 2){
		vector<float> n(CA);
		vector<float*> o(CA);
		vector<float*> p(CA);
		declaracion(n);
		direcciones(p,n); 
		direcciones(o,n);
		cout << "\nOrden original:\n"; 
		impresion(p);
		mergesort(p,0,CA-1);
		cout << "\nOrdenado:\n";
		impresion(p);
		guardarJSON(o,p,"datosMerge.json");
		guardarTXT(o, p, "datosMerge.txt");
		guardarCSV(o, p, "datosMerge.csv");
		guardarXML(o, p, "datosMerge.xml");
	}
	
	else if(TV == 3){
		vector<string> n(CA);
		vector<string*> o(CA);
		vector<string*> p(CA);
		declaracionString(n);
		direcciones(p,n);
		direcciones(o,n);
		cout << "\nOrden original:\n";  
		impresion(p);
		mergesort(p,0,CA-1);
		cout << "\nOrdenado:\n";
		impresion(p);
		guardarJSONString(o,p,"datosMerge.json");
		guardarTXTString(o, p, "datosMerge.txt");
		guardarCSVString(o, p, "datosMerge.csv");
		guardarXMLString(o, p, "datosMerge.xml");
	}
	else if(TV==4){
	vector<persona> n(CA);
	vector<persona*> o(CA);
	vector<persona*> p(CA);
	cout<<"Ordenar por Nombre(1)/Edad(2)"<<endl;
	cin>>persona::cr;
		declaracion(n);
		direcciones(p,n);
		direcciones(o,n);
		cout << "\nOrden original:\n";  
		impresion(p);
		mergesort(p,0,CA-1);
		cout << "\nOrdenado:\n";
		impresion(p);
		guardarJSONPersonas(o,p,"datosMerge.json");
		guardarTXTPersonas(o, p, "datosMerge.txt");
		guardarCSVPersonas(o, p, "datosMerge.csv");
		guardarXMLPersonas(o, p, "datosMerge.xml");
	}
	else{
		cout<<"Valor invalido";
	}	
	return 0;
}
