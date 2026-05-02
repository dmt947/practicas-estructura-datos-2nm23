#include "Persona.h"
#include "Auto.h"
#include <iostream>
#include <ostream>
#include <string>

using namespace std;

int main () {
    int np, na;
    char r;
    cout << "Introduce el numero de personas a generar: ";
    cin >> np;
    cout << "Introduce el numero de carros a generar: ";
    cin >> na;
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
        *(ps + i) = Persona(nom, apat, amat, g, e);
}
    Auto *as = new Auto[5];
    for (int i = 0; i < na; i++) {
        int a;
        float p;
        cout << "Anio del carro " << i << ": ";
        cin >> a;
        cout << "Precio del carro " << i << ": ";
        cin >> p;
        *(as + i) = Auto(p, a);
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
    
    return 0;
}
