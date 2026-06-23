#include "Auto.h"
#include <fstream>
#include <sstream>
#include <iomanip>
#include <iostream>

using namespace std;

//constructor (se ponen e inicializa las variables)
Auto::Auto()
{
}

//destructor
Auto::~Auto()
{
}

//implementacion de metodos a utilizar
void Auto::setPrecio(float p)
{
    precio = p;
}

float Auto::getPrecio()
{
    return precio;
}

void Auto::setAnio(int a)
{
    anio = a;
}

int Auto::getAnio()
{
    return anio;
}

// Implementación de las funciones de archivo
void Auto::guardarEnArchivo(string texto) {
	ofstream archivo("registro_sistema.txt", ios::app);
	if (archivo.is_open()) {
		archivo << texto << endl;
		archivo.close();
		cout << "[OK] Datos del Auto guardados en 'registro_sistema.txt'" << endl;
	} else {
		cout << "[ERROR] No se pudo escribir el archivo del Auto." << endl;
	}
}

void Auto::registrarAuto() {
	ostringstream ss;
	ss << "=== REGISTRO DE OBJETO AUTO ===\n"
	   << "Precio: $" << fixed << setprecision(2) << precio << "\n"
	   << "Anio: " << anio << "\n"
	   << "===============================\n";
	guardarEnArchivo(ss.str());
}
