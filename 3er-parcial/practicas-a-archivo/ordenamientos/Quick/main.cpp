#include<iostream>
#include <string>
#include <vector>
#include "funciones.h"
#include "persona.h"
#include "quick.h"
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
		quicksort(p,0,CA-1);
		cout << "\nOrdenado:\n";
		impresion(p);
		guardarJSON(o,p,"datosQuick.json");
		guardarTXT(o, p, "datosQuick.txt");
		guardarCSV(o, p, "datosQuick.csv");
		guardarXML(o, p, "datosQuick.xml");
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
		quicksort(p,0,CA-1);
		cout << "\nOrdenado:\n";
		impresion(p);
		guardarJSON(o,p,"datosQuick.json");
		guardarTXT(o, p, "datosQuick.txt");
		guardarCSV(o, p, "datosQuick.csv");
		guardarXML(o, p, "datosQuick.xml");
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
		quicksort(p,0,CA-1);
		cout << "\nOrdenado:\n";
		impresion(p);
		guardarJSONString(o,p,"datosQuick.json");
		guardarTXTString(o, p, "datosQuick.txt");
		guardarCSVString(o, p, "datosQuick.csv");
		guardarXMLString(o, p, "datosQuick.xml");
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
		quicksort(p,0,CA-1);
		cout << "\nOrdenado:\n";
		impresion(p);
		guardarJSONPersonas(o,p,"datosQuick.json");
		guardarTXTPersonas(o, p, "datosQuick.txt");
		guardarCSVPersonas(o, p, "datosQuick.csv");
		guardarXMLPersonas(o, p, "datosQuick.xml");
	}
	else{
		cout<<"Valor invalido";
	}	
	return 0;
}
