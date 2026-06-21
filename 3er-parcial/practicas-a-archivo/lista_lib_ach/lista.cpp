#include "lista.h"
#include <iostream>
#include <fstream>

using namespace std;

lista::lista(): archivoDatos("lista.txt"){
cargarDesdeArchivo();
}

lista::~lista(){}


void lista::guardarEnArchivo() {
    ofstream archivo(archivoDatos);
    for (const string& elemento : datos) {
        archivo << elemento << "\n";
    }
    archivo.close();
}

void lista::cargarDesdeArchivo() {
    ifstream archivo(archivoDatos);
    string linea;
    while (getline(archivo, linea)) {
        datos.push_back(linea);
    }
    archivo.close();
}

void lista::insertar(string dato) {
    datos.push_back(dato);
    guardarEnArchivo();
}

void lista::eliminar(string dato) {
    datos.remove(dato); 
    guardarEnArchivo();
    cout << "Elemento eliminado (si existia).\n";
}

void lista::mostrar() {
    if (datos.empty()) {
        cout << "La lista esta vacia.\n";
        return;
    }
    for (const string& elemento : datos) {
        cout << elemento << " -> ";
    }
    cout << "NULL\n";
}
