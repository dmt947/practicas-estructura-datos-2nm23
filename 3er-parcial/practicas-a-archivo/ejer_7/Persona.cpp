#include "Persona.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

Persona::Persona()
{
}

Persona::~Persona()
{
}

void Persona::setNombre(std::string n){
    nom = n;
}

void Persona::setApat(std::string ap){
	apat = ap;
}

void Persona::setAmat(std::string am){
	amat = am;
}

void Persona::setGenero(char g){
	genero = g;
}

void Persona::setEdad(int e){
	edad = e;
}

//****************************************************************

std::string Persona::getNombre(){
    return nom;
}

std::string Persona::getApat(){
	return apat;
}
std::string Persona::getAmat(){
	return amat;
}

char Persona::getGenero(){
	return genero;
}

int Persona::getEdad(){
	return edad;
}

// Implementación de las funciones de archivo
void Persona::guardarEnArchivo(string texto) {
	ofstream archivo("registro_sistema.txt", ios::app);
	if (archivo.is_open()) {
		archivo << texto << endl;
		archivo.close();
		cout << "[OK] Datos de la Persona guardados en 'registro_sistema.txt'" << endl;
	} else {
		cout << "[ERROR] No se pudo escribir el archivo de la Persona." << endl;
	}
}

void Persona::registrarPersona() {
	ostringstream ss;
	ss << "=== REGISTRO DE OBJETO PERSONA ===\n"
	   << "Nombre Completo: " << nom << " " << apat << " " << amat << "\n"
	   << "Genero: " << (genero == 1 ? "Masculino" : "Femenino") << "\n"
	   << "Edad: " << edad << " anos\n"
	   << "==================================\n";
	guardarEnArchivo(ss.str());
}


