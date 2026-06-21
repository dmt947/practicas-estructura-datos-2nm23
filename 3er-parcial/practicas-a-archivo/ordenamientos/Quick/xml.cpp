#include "xml.h"

void guardarXMLString(
    const vector<string*>& original,
    const vector<string*>& ordenado,
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

void guardarXMLPersonas(
    const vector<persona*>& original,
    const vector<persona*>& ordenado,
    const string& ruta)
{
    ofstream f(ruta.c_str());

    if(!f){
        cout << "Error al crear el archivo\n";
        return;
    }

    f << "<?xml version=\"1.0\"?>\n";
    f << "<personas>\n";

    f << "  <original>\n";
    for(size_t i = 0; i < original.size(); i++){
        f << "    <persona>\n";
        f << "      <nombre>"
          << original[i]->getNombre()
          << "</nombre>\n";
        f << "      <edad>"
          << original[i]->getEdad()
          << "</edad>\n";
        f << "    </persona>\n";
    }
    f << "  </original>\n";

    f << "  <ordenado>\n";
    for(size_t i = 0; i < ordenado.size(); i++){
        f << "    <persona>\n";
        f << "      <nombre>"
          << ordenado[i]->getNombre()
          << "</nombre>\n";
        f << "      <edad>"
          << ordenado[i]->getEdad()
          << "</edad>\n";
        f << "    </persona>\n";
    }
    f << "  </ordenado>\n";

    f << "</personas>\n";

    f.close();
}
