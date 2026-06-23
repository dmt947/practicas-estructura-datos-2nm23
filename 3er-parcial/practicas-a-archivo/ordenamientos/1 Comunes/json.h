#ifndef JSON_H
#define JSON_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "persona.h"

using namespace std;

class persona; // Declaración adelantada

template<typename T>
void guardarJSON(
    const vector<T*>& original,
    const vector<T*>& ordenado,
    const string& ruta)
{
    ofstream f(ruta.c_str());

    f << "{\n";

    f << "  \"original\": [";
    for(size_t i=0;i<original.size();i++){
        f << *original[i];
        if(i < original.size()-1) f << ",";
    }

    f << "],\n";

    f << "  \"ordenado\": [";
    for(size_t i=0;i<ordenado.size();i++){
        f << *ordenado[i];
        if(i < ordenado.size()-1) f << ",";
    }

    f << "]\n";

    f << "}\n";

    f.close();
}

void guardarJSONString(const vector<string*>& original,
                       const vector<string*>& ordenado,
                       const string& ruta);

void guardarJSONPersonas(const vector<persona*>& original,
                         const vector<persona*>& ordenado,
                         const string& ruta);

#endif
