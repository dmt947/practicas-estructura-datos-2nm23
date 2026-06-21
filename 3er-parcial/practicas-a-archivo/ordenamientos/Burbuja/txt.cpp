#include "txt.h"

void guardarTXTString(
    const vector<string*>& original,
    const vector<string*>& ordenado,
    const string& ruta)
{
    ofstream f(ruta.c_str());

    if(!f){
        cout << "Error al crear el archivo\n";
        return;
    }

    f << "ORDEN ORIGINAL\n";
    for(size_t i = 0; i < original.size(); i++){
        f << *original[i] << endl;
    }

    f << "\nORDENADO\n";
    for(size_t i = 0; i < ordenado.size(); i++){
        f << *ordenado[i] << endl;
    }

    f.close();
}

void guardarTXTPersonas(
    const vector<persona*>& original,
    const vector<persona*>& ordenado,
    const string& ruta)
{
    ofstream f(ruta.c_str());

    if(!f){
        cout << "Error al crear el archivo\n";
        return;
    }

    f << "ORDEN ORIGINAL\n";
    for(size_t i = 0; i < original.size(); i++){
        f << *original[i] << endl;
    }

    f << "\nORDENADO\n";
    for(size_t i = 0; i < ordenado.size(); i++){
        f << *ordenado[i] << endl;
    }

    f.close();
}
