#include "persona.h"
#include <iostream>
#include <string>
int persona::cr=1;
persona :: persona() {
	nombre ="";
	edad =0;
}
string persona::getNombre() const{ //Getters
    return nombre;
}

int persona::getEdad() const{
    return edad;
}

void persona::setNombre(const string& n) { //Setters
        nombre = n;
    }

void persona::setEdad(int e) {
        if (e >= 0)
            edad = e;
        else
            cout << "Edad invalida\n";
    }

bool persona::operator<(const persona& otra) const{ //Define que hacer al comparar con >
	if (cr==1){									//N[j] > N[j+1] -> Persona[j] > persona otra[j+1]. cr define si se compara nombre o edad.
		return nombre < otra.nombre;
	}
	else{
		return edad < otra.edad;
	}
}
bool persona::operator>(const persona& otra) const{ //Define que hacer al comparar con >
	if (cr==1){									//N[j] > N[j+1] -> Persona[j] > persona otra[j+1]. cr define si se compara nombre o edad.
		return nombre > otra.nombre;
	}
	else{
		return edad > otra.edad;
	}
}



ostream& operator<<(ostream &os, const persona &p) { //Operadores. Define que hacer al usar cout
    os << "Nombre: " << p.getNombre()
       << " Edad: " << p.getEdad();
    return os;
}

istream& operator>>(istream &is, persona &p) { //Define que hacer al usar cin
    string nombre;
    int edad;

    cout << "Nombre: ";
    getline(cin >> ws, nombre);

    cout << "Edad: ";
    is >> edad;

    p.setNombre(nombre);
    p.setEdad(edad);

    return is;
}
