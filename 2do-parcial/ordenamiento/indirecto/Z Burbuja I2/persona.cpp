#include "persona.h"

int persona::cr = 1;

persona::persona(){
    nombre = "";
    edad = 0;
}

string persona::getNombre() const { return nombre; }
int persona::getEdad() const { return edad; }

void persona::setNombre(const string& n){ nombre = n; }
void persona::setEdad(int e){ if(e >= 0) edad = e; }

ostream& operator<<(ostream& os, const persona& p){
    os << "Nombre: " << p.getNombre()
       << " Edad: " << p.getEdad();
    return os;
}

istream& operator>>(istream& is, persona& p){
    string n;
    int e;

    cout << "Nombre: ";
    getline(is >> ws, n);

    cout << "Edad: ";
    is >> e;

    p.setNombre(n);
    p.setEdad(e);

    return is;
}

bool persona::operator>(const persona& o){
    if(cr == 1) return nombre > o.nombre;
    return edad > o.edad;
}
