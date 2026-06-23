#include<iostream>
#include <string>
#include <vector>
#include "funciones.h"
#include "persona.h"
#include "burbuja.h"
#include "json.h"
#include "txt.h"
#include "cvs.h"
#include "xml.h"
using namespace std;

int main(){
	int CA=0,TV=0;
	
	cout<<"Cantidad de valores"<<endl;  //Menu
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
		impresion(o);
		burbuja(p);
		cout << "\nOrdenado:\n";
		impresion(p);
		guardarJSON(o,p,"datosBurbuja.json");
		guardarTXT(o, p, "datosBurbuja.txt");
		guardarCSV(o, p, "datosBurbuja.csv");
		guardarXML(o, p, "datosBurbuja.xml");
	}
	else if(TV == 2){
		vector<float> n(CA);
		vector<float*> o(CA);
		vector<float*> p(CA);
		declaracion(n);
		direcciones(p,n);
		direcciones(o,n);
		cout << "\nOrden original:\n"; 
		impresion(o);
		burbuja(p);
		cout << "\nOrdenado:\n";
		impresion(p);
		guardarJSON(o,p,"datosBurbuja.json");
		guardarTXT(o, p, "datosBurbuja.txt");
		guardarCSV(o, p, "datosBurbuja.csv");
		guardarXML(o, p, "datosBurbuja.xml");
	}
	else if(TV == 3){
		vector<string> n(CA);
		vector<string*> o(CA);
		vector<string*> p(CA);
		declaracionString(n); //Especializacion para string 
		direcciones(p,n);
		direcciones(o,n); 
		cout << "\nOrden original:\n";
		impresion(o);
		burbuja(p);
		cout << "\nOrdenado:\n";
		impresion(p);
		guardarJSONString(o,p,"datosBurbuja.json");
		guardarTXTString(o, p, "datosBurbuja.txt");
		guardarCSVString(o, p, "datosBurbuja.csv");
		guardarXMLString(o, p, "datosBurbuja.xml");
	}
	else if(TV == 4){
		vector<persona> n(CA);
		vector<persona*> o(CA);
		vector<persona*> p(CA);
		cout<<"Ordenar por Nombre(1)/Edad(2)"<<endl;
		cin>>persona::cr;
		declaracion(n);
		direcciones(p,n);
		direcciones(o,n);
		cout << "\nOrden original:\n"; 
		impresion(o);
		burbuja(p);
		cout << "\nOrdenado:\n";
		impresion(p);
		guardarJSONPersonas(o,p,"datosBurbuja.json");
		guardarTXTPersonas(o, p, "datosBurbuja.txt");
		guardarCSVPersonas(o, p, "datosBurbuja.csv");
		guardarXMLPersonas(o, p, "datosBurbuja.xml");
	}

	return 0;
}
