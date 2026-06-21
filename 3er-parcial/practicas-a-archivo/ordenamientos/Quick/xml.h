#ifndef XML_H
#define XML_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "persona.h"

using namespace std;

template<typename T>
void guardarXML(
    const vector<T*>& original,
    const vector<T*>& ordenado,
    const string& ruta)
{
    ofstream f(ruta.c_str());

    if(!f){
        cout << "Error al crear el archivo\n";
        return;
    }

    f << "<?xml version=\"1.0\"?>\n";
    f << "<datos>\n";

    f << "  <original>\n";
    for(size_t i = 0; i < original.size(); i++){
        f << "    <valor>"
          << *original[i]
          << "</valor>\n";
    }
    f << "  </original>\n";

    f << "  <ordenado>\n";
    for(size_t i = 0; i < ordenado.size(); i++){
        f << "    <valor>"
          << *ordenado[i]
          << "</valor>\n";
    }
    f << "  </ordenado>\n";

    f << "</datos>\n";

    f.close();
}

void guardarXMLString(
    const vector<string*>& original,
    const vector<string*>& ordenado,
    const string& ruta);

void guardarXMLPersonas(
    const vector<persona*>& original,
    const vector<persona*>& ordenado,
    const string& ruta);

#endif
