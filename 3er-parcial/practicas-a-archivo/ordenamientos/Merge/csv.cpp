#include "cvs.h"

void guardarCSVString(
    const vector<string*>& original,
    const vector<string*>& ordenado,
    const string& ruta)
{
    ofstream f(ruta.c_str());

    if(!f){
        cout << "Error al crear el archivo\n";
        return;
    }

    f << "Original,Ordenado\n";

    size_t n = max(original.size(), ordenado.size());

    for(size_t i = 0; i < n; i++){

        if(i < original.size())
            f << "\"" << *original[i] << "\"";

        f << ",";

        if(i < ordenado.size())
            f << "\"" << *ordenado[i] << "\"";

        f << "\n";
    }

    f.close();
}

void guardarCSVPersonas(
    const vector<persona*>& original,
    const vector<persona*>& ordenado,
    const string& ruta)
{
    ofstream f(ruta.c_str());

    if(!f){
        cout << "Error al crear el archivo\n";
        return;
    }

    f << "Nombre Original,Edad Original,Nombre Ordenado,Edad Ordenada\n";

    size_t n = max(original.size(), ordenado.size());

    for(size_t i = 0; i < n; i++){

        if(i < original.size()){
            f << original[i]->getNombre()
              << ","
              << original[i]->getEdad();
        }

        f << ",";

        if(i < ordenado.size()){
            f << ordenado[i]->getNombre()
              << ","
              << ordenado[i]->getEdad();
        }

        f << "\n";
    }

    f.close();
}
