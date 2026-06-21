#include<iostream>
#include <iomanip>
#include <cmath>
#include <fstream> 
#include <sstream>
#include <string>
#include "MetodosCal.h"
using namespace std;


MetodosCal::MetodosCal(){
	NT = 0;
}

MetodosCal::MetodosCal(float _T1){
	T1 = _T1;
	NT = 1;
}
	
MetodosCal::MetodosCal(float _T1, float _T2){
	T1 = _T1;
	T2 = _T2;
	NT = 2;
}

MetodosCal::MetodosCal(float _T1, float _T2,float _T3){
	T1 = _T1;
	T2 = _T2;
	T3 = _T3;
	NT = 3;
}

MetodosCal::~MetodosCal(){}

//constructores de la herencia

calculadoraExtra::calculadoraExtra(){
	NT = 0;
}

calculadoraExtra::calculadoraExtra(float _T1){
	T1 = _T1;
	NT = 1;
}

calculadoraExtra::calculadoraExtra(float _T1, float _T2){
	T1 = _T1;
	T2 = _T2;
	NT = 2;
}

calculadoraExtra::calculadoraExtra(float _T1, float _T2, float _T3){
	T1 = _T1;
	T2 = _T2;
	T3 = _T3;
	NT = 3;
}

//constructores de la sobreescritura

calculadoraNueva::calculadoraNueva(){
	NT = 0;
}

calculadoraNueva::calculadoraNueva(float _T1){
	T1 = _T1;
	NT = 1;
}

calculadoraNueva::calculadoraNueva(float _T1, float _T2){
	T1 = _T1;
	T2 = _T2;
	NT = 2;
}

calculadoraNueva::calculadoraNueva(float _T1, float _T2, float _T3){
	T1 = _T1;
	T2 = _T2;
	T3 = _T3;
	NT = 3;
}

//************************************************************************************

// Implementación del método de guardado
void MetodosCal::guardarEnArchivo(string texto) {
	ofstream archivo("historial_operaciones.txt", ios::app); 
	if (archivo.is_open()) {
		archivo << texto << endl;
		archivo.close();
		cout << "\n[OK] Operacion guardada en 'historial_operaciones.txt'" << endl;
	} else {
		cout << "\n[ERROR] No se pudo escribir en el archivo .txt" << endl;
	}
}

//************************************************************************************

void MetodosCal::suma(){
	if(NT == 0){
		cout<<" No hay terminos que operar "<<endl;
	}
	if(NT == 1){
		R = T1 ;
		cout<<fixed<<setprecision(2);
		cout<<T1<<" = "<<R;
		
		ostringstream ss;
		ss << fixed << setprecision(2) << T1 << " = " << R;
		guardarEnArchivo(ss.str());
	}
	if(NT == 2){
		R = T1 + T2;
		cout<<fixed<<setprecision(2);
		cout<<T1<<" + "<<T2<<" = "<<R;
		
		ostringstream ss;
		ss << fixed << setprecision(2) << T1 << " + " << T2 << " = " << R;
		guardarEnArchivo(ss.str());
	}else if(NT ==3){
		R = T1+T2+T3;
		cout<<fixed<<setprecision(2);
		cout<<T1<<" + "<<T2<<" + "<<T3<<" = "<<R;	
		
		ostringstream ss;
		ss << fixed << setprecision(2) << T1 << " + " << T2 << " + " << T3 << " = " << R;
		guardarEnArchivo(ss.str());
	}
}
	
void MetodosCal::resta(){
	if(NT == 0){
		cout<<" No hay terminos que operar "<<endl;
	}
	if(NT == 1){
		R = T1 ;
		cout<<fixed<<setprecision(2);
		cout<<T1<<" = "<<R;
		
		ostringstream ss;
		ss << fixed << setprecision(2) << T1 << " = " << R;
		guardarEnArchivo(ss.str());
	}
	if(NT == 2){
		R = T1 - T2;
		cout<<fixed<<setprecision(2);
		cout<<T1<<" - "<<T2<<" = "<<R;
		
		ostringstream ss;
		ss << fixed << setprecision(2) << T1 << " - " << T2 << " = " << R;
		guardarEnArchivo(ss.str());
	}else if(NT ==3){
		R = T1-T2-T3;
		cout<<fixed<<setprecision(2);
		cout<<T1<<" - "<<T2<<" - "<<T3<<" = "<<R;	
		
		ostringstream ss;
		ss << fixed << setprecision(2) << T1 << " - " << T2 << " - " << T3 << " = " << R;
		guardarEnArchivo(ss.str());
	}
}
	
void MetodosCal::multiplicacion(){
	if(NT == 0){
		cout<<" No hay terminos que operar "<<endl;
	}
	if(NT == 1){
		R = T1 ;
		cout<<fixed<<setprecision(2);
		cout<<T1<<" = "<<R;
		
		ostringstream ss;
		ss << fixed << setprecision(2) << T1 << " = " << R;
		guardarEnArchivo(ss.str());
	}
	if(NT == 2){
			R = T1*T2;
			cout<<fixed<<setprecision(2);
			cout<<T1<<" * "<<T2<<" = "<<R;
			
			ostringstream ss;
			ss << fixed << setprecision(2) << T1 << " * " << T2 << " = " << R;
			guardarEnArchivo(ss.str());
	}else if(NT ==3){
		R = T1*T2*T3;
		cout<<fixed<<setprecision(2);
		cout<<T1<<" * "<<T2<<" * "<<T3<<" = "<<R;	
		
		ostringstream ss;
		ss << fixed << setprecision(2) << T1 << " * " << T2 << " * " << T3 << " = " << R;
		guardarEnArchivo(ss.str());
	}	
}

void MetodosCal::division(){
	if(NT == 0){
		cout<<" No hay terminos que operar "<<endl;
	}
	if(NT == 1){
		R = T1 ;
		cout<<fixed<<setprecision(2);
		cout<<T1<<" = "<<R;
		
		ostringstream ss;
		ss << fixed << setprecision(2) << T1 << " = " << R;
		guardarEnArchivo(ss.str());
	}
	if(NT == 2){
		R = T1/T2;
		cout<<fixed<<setprecision(2);
		cout<<T1<<" / "<<T2<<" = "<<R;
		
		ostringstream ss;
		ss << fixed << setprecision(2) << T1 << " / " << T2 << " = " << R;
		guardarEnArchivo(ss.str());
	}else if(NT ==3){
		R = (T1/T2)/T3;
		cout<<fixed<<setprecision(2);
		cout<<"("<<T1<<" / "<<T2<<") / "<<T3<<" = "<<R;	
		
		ostringstream ss;
		ss << fixed << setprecision(2) << "(" << T1 << " / " << T2 << ") / " << T3 << " = " << R;
		guardarEnArchivo(ss.str());
	}
}

//************************************************************************************

void calculadoraExtra::potencia(){
	if(NT == 2){
		R = pow(T1,T2);
		cout<<fixed<<setprecision(2);
		cout<<T1<<" ^ "<<T2<<" = "<<R<<endl;
		
		ostringstream ss;
		ss << fixed << setprecision(2) << T1 << " ^ " << T2 << " = " << R;
		guardarEnArchivo(ss.str());
	}
	else{
		cout<<"La potencia necesita 2 terminos"<<endl;
	}
}

void calculadoraExtra::raiz(){
	if(NT == 1){
		R = sqrt(T1);
		cout<<fixed<<setprecision(2);
		cout<<"Raiz de "<<T1<<" = "<<R<<endl;
		
		ostringstream ss;
		ss << fixed << setprecision(2) << "Raiz de " << T1 << " = " << R;
		guardarEnArchivo(ss.str());
	}
	else{
		cout<<"La raiz necesita 1 termino"<<endl;
	}
}

//************************************************************************************

void calculadoraNueva::multiplicacion(){
	if(NT == 2){
		R = 0;
		for(int i = 0; i < T2; i++){
			R = R + T1;
			cout<<"Paso "<<i+1<<": "<<R<<endl;
		}
		cout<<T1<<" * "<<T2<<" = "<<R<<endl;
		
		ostringstream ss;
		ss << T1 << " * " << T2 << " = " << R << " (Por sumas sucesivas)";
		guardarEnArchivo(ss.str());
	}
	else{
		calculadoraExtra::multiplicacion();
	}
}

void calculadoraNueva::potencia(){
	if(NT == 2){
		R = 1;
		for(int i = 0; i < T2; i++){
			R = R * T1;
			cout<<"Paso "<<i+1<<": "<<R<<endl;
		}
		cout<<T1<<" ^ "<<T2<<" = "<<R<<endl;
		
		ostringstream ss;
		ss << T1 << " ^ " << T2 << " = " << R << " (Por multiplicaciones sucesivas)";
		guardarEnArchivo(ss.str());
	}
	else{
		calculadoraExtra::potencia();
	}
}

void calculadoraNueva::division(){
	if(NT == 2){
		int contador = 0;
		float temp = T1;

		while(temp >= T2){
			cout<<temp<<" - "<<T2<<" = ";
			temp = temp - T2;
			contador++;
		}
		R = contador;
		cout<<"\n"<<T1<<" / "<<T2<<" = "<<R<<endl;
		
		ostringstream ss;
		ss << T1 << " / " << T2 << " = " << R << " (Por restas sucesivas - Cociente entero)";
		guardarEnArchivo(ss.str());
	}
	else{
		calculadoraExtra::division();
	}
}
	
