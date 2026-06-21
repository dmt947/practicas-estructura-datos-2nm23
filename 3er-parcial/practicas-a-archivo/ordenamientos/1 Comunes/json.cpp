#include "json.h"


void guardarJSONString(
    const vector<string*>& original,
    const vector<string*>& ordenado,
    const string& ruta)
{
    ofstream f(ruta.c_str());

    if(!f){
        cout << "Error al crear archivo\n";
        return;
    }

    f << "{\n";

    f << "  \"original\": [";
    for(size_t i = 0; i < original.size(); i++){
        f << "\"" << *original[i] << "\"";
        if(i < original.size()-1)
            f << ",";
    }

    f << "],\n";

    f << "  \"ordenado\": [";
    for(size_t i = 0; i < ordenado.size(); i++){
        f << "\"" << *ordenado[i] << "\"";
        if(i < ordenado.size()-1)
            f << ",";
    }

    f << "]\n";

    f << "}";

    f.close();
}

void guardarJSONPersonas(
    const vector<persona*>& original,
    const vector<persona*>& ordenado,
    const string& ruta)
{
    ofstream f(ruta.c_str());

    if(!f){
        cout << "Error al crear archivo\n";
        return;
    }

    f << "{\n";

    // Original
    f << "  \"original\": [\n";

    for(size_t i = 0; i < original.size(); i++){
        f << "    {\n";
        f << "      \"nombre\": \"" << original[i]->getNombre() << "\",\n";
        f << "      \"edad\": " << original[i]->getEdad() << "\n";
        f << "    }";

        if(i < original.size()-1)
            f << ",";

        f << "\n";
    }

    f << "  ],\n";

    // Ordenado
    f << "  \"ordenado\": [\n";

    for(size_t i = 0; i < ordenado.size(); i++){
        f << "    {\n";
        f << "      \"nombre\": \"" << ordenado[i]->getNombre() << "\",\n";
        f << "      \"edad\": " << ordenado[i]->getEdad() << "\n";
        f << "    }";

        if(i < ordenado.size()-1)
            f << ",";

        f << "\n";
    }

    f << "  ]\n";
    f << "}";

    f.close();
}
