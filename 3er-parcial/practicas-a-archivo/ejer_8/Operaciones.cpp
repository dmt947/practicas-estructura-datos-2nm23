#include "Operaciones.h"
#include <iostream>
#include <algorithm>
#include <fstream> 
#include <sstream>  
#include <iomanip>

using namespace std;


Operaciones::Operaciones(){}

Operaciones::~Operaciones(){}

void Operaciones::setNumeros(int a, int b, int c, int d, int e){
    num1 = a;
    num2 = b;
    num3 = c;
    num4 = d;
    num5 = e;
}

float Operaciones::getSuma(){
    return num1+num2+num3+num4+num5;
}

float Operaciones::getPromedio(){
    return getSuma()/5.0;
}

float Operaciones::getMedia(){
    return getPromedio();
}

int Operaciones::getMaximo(){
    return max({num1,num2,num3,num4,num5});
}

int Operaciones::getMinimo(){
    return min({num1,num2,num3,num4,num5});
}

void Operaciones::guardarEnArchivo(string texto) {
	ofstream archivo("reporte_operaciones.txt", ios::app);
	if (archivo.is_open()) {
		archivo << texto << endl;
		archivo.close();
		cout << "\n[OK] Resultados estadisticos guardados en 'reporte_operaciones.txt'" << endl;
	} else {
		cout << "\n[ERROR] No se pudo escribir o crear el archivo de reporte." << endl;
	}
}

void Operaciones::registrarOperaciones() {
	ostringstream ss;
	ss << "=========================================\n"
	   << "       REPORTE DE OPERACIONES ESTADISTICAS\n"
	   << "=========================================\n"
	   << "Numeros analizados: " << num1 << ", " << num2 << ", " << num3 << ", " << num4 << ", " << num5 << "\n"
	   << "-----------------------------------------\n"
	   << "Suma Total: " << getSuma() << "\n"
	   << fixed << setprecision(2)
	   << "Promedio:   " << getPromedio() << "\n"
	   << "Media:      " << getMedia() << "\n"
	   << "Maximo:     " << getMaximo() << "\n"
	   << "Minimo:     " << getMinimo() << "\n"
	   << "=========================================\n\n";
	
	guardarEnArchivo(ss.str());
}
