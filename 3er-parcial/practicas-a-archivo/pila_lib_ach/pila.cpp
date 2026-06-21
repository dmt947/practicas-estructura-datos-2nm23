#include "pila.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

pila::pila(): archivoDatos("pila.txt"){
cargarDesdeArchivo();
}

pila::~pila(){}

void pila::guardarEnArchivo() {
    ofstream archivo(archivoDatos);
    stack<string> copia = datos;
    while (!copia.empty()) {
        archivo << copia.top() << "\n";
        copia.pop();
    }
    archivo.close();
}

void pila::cargarDesdeArchivo() {
    ifstream archivo(archivoDatos);
    string linea;
    vector<string> temp;
    
    while (getline(archivo, linea)) {
        temp.push_back(linea);
    }
    archivo.close();

    for (auto it = temp.rbegin(); it != temp.rend(); ++it) {
        datos.push(*it);
    }
}

void pila::insertar(string dato) {
    datos.push(dato);
    guardarEnArchivo();
}

void pila::eliminar() {
    if (datos.empty()) {
        cout << "La pila esta vacia.\n";
        return;
    }
    datos.pop();
    guardarEnArchivo();
    cout << "Elemento eliminado del tope.\n";
}

void pila::verTope() {
    if (datos.empty()) {
        cout << "La pila esta vacia.\n";
    } else {
        cout << "El tope de la pila es: " << datos.top() << "\n";
    }
}

void pila::mostrarPila() {
    if (datos.empty()) {
        cout << "La pila esta vacia.\n";
        return;
    }
    stack<string> copia = datos;
    cout << "Pila (Tope -> Fondo):\n";
    while (!copia.empty()) {
        cout << copia.top() << "\n";
        copia.pop();
    }
}