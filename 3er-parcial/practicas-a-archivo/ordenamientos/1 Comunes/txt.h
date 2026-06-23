#ifndef TXT_H
#define TXT_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "persona.h"

using namespace std;

// Función plantilla para int, float, etc.
template<typename T>
void guardarTXT(
    const vector<T*>& original,
    const vector<T*>& ordenado,
    const string& ruta)
{
    ofstream f(ruta.c_str());

    if(!f){
        cout << "Error al crear el archivo\n";
        return;
    }

    f << "ORDEN ORIGINAL\n";
    for(size_t i = 0; i < original.size(); i++){
        f << *original[i] << " ";
    }

    f << "\n\nORDENADO\n";
    for(size_t i = 0; i < ordenado.size(); i++){
        f << *ordenado[i] << " ";
    }

    f << endl;
    f.close();
}

// Declaraciones de funciones no plantilla
void guardarTXTString(
    const vector<string*>& original,
    const vector<string*>& ordenado,
    const string& ruta);

void guardarTXTPersonas(
    const vector<persona*>& original,
    const vector<persona*>& ordenado,
    const string& ruta);

#endif
