#include "Persona.h"
#include "Auto.h"
#include <iostream>
#include <ostream>
#include <string>

struct DatosAuto{
    float precio;
    int anio;
};

struct DatosPersona {
    std::string nom;
    std::string apat;
    std::string amat;
    int edad;
    char genero;
};

using namespace std;

int main () {
    int np, na;
    char r;
    cout << "Introduce el numero de personas a generar: ";
    cin >> np;
    cout << "Introduce el numero de carros a generar: ";
    cin >> na;
    cout << "1.\tUsar programacion estructurada" << endl;
    cout << "2.\tUsar programacion orientada a objetos" << endl;
    cout << "Ingrese una opcion: ";
    cin >> r;
    if(r == '1'){
        cout << "====Usando estructuras====" << endl;
        DatosPersona *pes = new DatosPersona[np];
        for (int i = 0; i < np; i++) {
            cout << "Nombre de la persona " << i << ": ";
            cin >> (pes + i)->nom;
            cout << "Apellido paterno de la persona " << i << ": ";
            cin >> (pes + i)->apat;
            cout << "Apellido materno de la persona " << i << ": ";
            cin >> (pes + i)->amat;
            cout << "Genero de la persona " << i << " [M/F]: ";
            cin >> (pes + i)->genero;
            cout << "Edad de la persona " << i << ": ";
            cin >> (pes + i)->edad;
        }
        DatosAuto *aes = new DatosAuto[na];
        for (int i = 0; i < na; i++) {
            cout << "Anio del carro " << i << ": ";
            cin >> (aes + i)->anio;
            cout << "Precio del carro " << i << ": ";
            cin >> (aes + i)->precio;
        }
        for (int i = 0; i < np; i++) {
            cout << "Nombre: " << (pes + i)->nom << endl;
            cout << "Apellido paterno: " << (pes + i)->apat<< endl;
            cout << "Apellido materno: " << (pes + i)->amat<< endl;
            cout << "Genero: " << (pes + i)->genero << endl;
            cout << "Edad: " << (pes + i)->edad << endl;
        }

        for (int i = 0; i < na; i++) {
            cout << "Anio: " << (aes + i)->anio << endl;
            cout << "Precio: " << (aes + i)->precio << endl;
        }
        delete [] pes;
        delete [] aes;
    } else if(r == '2') {
        cout << "====Usando clases====" << endl;
        Persona *ps = new Persona[np];
        for (int i = 0; i < np; i++) {
            string nom, amat, apat;
            char g;
            int e;
            cout << "Nombre de la persona " << i << ": ";
            cin >> nom;
            cout << "Apellido paterno de la persona " << i << ": ";
            cin >> apat;
            cout << "Apellido materno de la persona " << i << ": ";
            cin >> amat;
            cout << "Genero de la persona " << i << " [M/F]: ";
            cin >> g;
            cout << "Edad de la persona " << i << ": ";
            cin >> e;
            (ps + i)->setNombre(nom);
            (ps + i)->setApat(apat);
            (ps + i)->setAmat(amat);
            (ps + i)->setGenero(g);
            (ps + i)->setEdad(e);
        }
        Auto *as = new Auto[5];
        for (int i = 0; i < na; i++) {
            int a;
            float p;
            cout << "Anio del carro " << i << ": ";
            cin >> a;
            cout << "Precio del carro " << i << ": ";
            cin >> p;
            (as + i)->setAnio(a);
            (as + i)->setPrecio(p);
        }

        for (int i = 0; i < np; i++) {
            cout << "Nombre: " << (ps + i)->getNombre() << endl;
            cout << "Apellido paterno: " << (ps + i)->getApat() << endl;
            cout << "Apellido materno: " << (ps + i)->getAmat() << endl;
            cout << "Genero: " << (ps + i)->getGenero() << endl;
            cout << "Edad: " << (ps + i)->getEdad() << endl;
        }

        for (int i = 0; i < na; i++) {
            cout << "Anio: " << (as + i)->getAnio() << endl;
            cout << "Precio: " << (as + i)->getPrecio() << endl;
        }
        delete [] ps;
        delete[] as;
    }
    return 0;
}
