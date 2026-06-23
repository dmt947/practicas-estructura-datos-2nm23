#include <iostream>
#include <fstream>
#include <sstream>
#include "Auto.h"
#include "Persona.h"
using namespace std;

struct DatosAuto{
	float precio1;
	int anio1;
};

struct DatosPersona {
	std::string nom1;
	std::string apat1;		
	std::string amat1;
	char genero1;
	int edad1;
};

// Funciones auxiliares para guardar los structs en el mismo archivo externo
void guardarStructAuto(DatosAuto da) {
	ofstream archivo("registro_sistema_struct.txt", ios::app);
	if(archivo.is_open()) {
		archivo << "=== REGISTRO STRUCT DATOSAUTO ===\n"
		        << "Precio: $" << da.anio1 << "\n"   // Conservando la asignacion de tu main original
		        << "Anio: " << da.precio1 << "\n"
		        << "=================================\n\n";
		archivo.close();
	}
}

void guardarStructPersona(DatosPersona dp) {
	ofstream archivo("registro_sistema_struct.txt", ios::app);
	if(archivo.is_open()) {
		archivo << "=== REGISTRO STRUCT DATOSPERSONA ===\n"
		        << "Nombre: " << dp.nom1 << " " << dp.apat1 << " " << dp.amat1 << "\n"
		        << "Genero: " << (dp.genero1 == 1 ? "Masculino" : "Femenino") << "\n"
		        << "Edad: " << dp.edad1 << "\n"
		        << "====================================\n\n";
		archivo.close();
	}
}


int main(int argc, char** argv) {
	
	DatosAuto a;
	
	a.anio1 =300000;
	a.precio1 = 2026;
	
	cout << "Precio con struct: $" << a.anio1 << "\n";
    cout << "Anio con struct: " << a.precio1 << "\n";
    cout << "\n" << "Tamanio de struct DatosAuto en bytes: " << sizeof(a) << "\n";
    
    guardarStructAuto(a);
	
	cout << "\n***********************************************************\n";
	
	DatosPersona dp;
	
	dp.nom1 = "Pablo";
	dp.apat1 = "Roldan";
	dp.amat1 = "Medrano";
	dp.genero1 = 1;
	dp.edad1 = 20;
	
	cout << "Nombre con struct: " << dp.nom1 << "\n";
    cout << "Apellido paterno con struct: " << dp.apat1 << "\n";
    cout << "Apellido materno con struct: " << dp.amat1 << "\n";
	
	if (dp.genero1==1){
    	cout << "Genero con struct: Masculino\n";
	}else{
		cout << "Genero con struct: Femenino\n";
	}
	
	cout << "Edad con struct: " << dp.edad1 << "\n";
	
	cout << "\n" << "Tamanio de struct DatosPersona en bytes: " << sizeof(dp) << "\n";
	
	guardarStructPersona(dp);
	
	cout << "\n***********************************************************\n";
	
	Auto nuevo;
	
	nuevo.setPrecio(15000);
    nuevo.setAnio(2022);
    
    cout << "Precio con class: $" << nuevo.getPrecio() << "\n";
    cout << "Anio con class: " << nuevo.getAnio()<< "\n";
	cout << "\n" << "Tamanio de class Auto en bytes: " << sizeof(nuevo) << "\n";
	
	nuevo.registrarAuto();
    
    cout << "\n***********************************************************\n";
    
    Persona p;
    
    p.setNombre("Donas");
    p.setApat("Esca");
    p.setAmat("Rome");
    p.setGenero(1);
    p.setEdad(18);

    cout << "Nombre con class: " << p.getNombre() << "\n";
    cout << "Apellido paterno con class: " << p.getApat() << "\n";
    cout << "Apellido materno con class: " << p.getAmat() << "\n";
	
	if (p.getGenero()==1){
    	cout << "Genero con class: Masculino\n";
	}else{
		cout << "Genero con class: Femenino\n";
	}
	
	cout << "Edad con class: " << p.getEdad() << "\n";
	
	cout << "\n" << "Tamanio de class Persona en bytes: " << sizeof(p) << "\n";
	
	p.registrarPersona();
	
	cout << "\n***********************************************************\n";
	
	return 0;
}