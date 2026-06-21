#include "cola.h"
#include <iostream>
#include <fstream>

using namespace std;

cola::cola(): archivoDatos("cola.txt"){
	cargarDesdeArchivo();
}

cola::~cola(){}

void cola::guardarEnArchivo() {
    ofstream archivo(archivoDatos);
    queue<string> copia = datos;
    while (!copia.empty()) {
        archivo << copia.front() << "\n";
        copia.pop();
    }
    archivo.close();
}

void cola::cargarDesdeArchivo() {
    ifstream archivo(archivoDatos);
    string linea;
    while (getline(archivo, linea)) {
        datos.push(linea); 
    }
    archivo.close();
}

void cola::encolar(string dato) {
    datos.push(dato);
    guardarEnArchivo();
}

void cola::desencolar() {
    if (datos.empty()) {
        cout << "La cola esta vacia.\n";
        return;
    }
    datos.pop();
    guardarEnArchivo();
    cout << "Elemento desencolado.\n";
}

void cola::mostrar() {
    if (datos.empty()) {
        cout << "La cola esta vacia.\n";
        return;
    }
    queue<string> copia = datos;
    cout << "Frente -> ";
    while (!copia.empty()) {
        cout << copia.front() << " -> ";
        copia.pop();
    }
    cout << "Final\n";
}

