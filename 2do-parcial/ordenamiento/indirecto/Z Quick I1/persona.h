#ifndef PERSONA_H
#define PERSONA_H

#include <iostream>
#include <string>
using namespace std;

class persona{
private:
    string nombre;
    int edad;

public:
    static int cr;

    persona();

    string getNombre() const;
    int getEdad() const;

    void setNombre(const string&);
    void setEdad(int);

    bool operator<(const persona&) const;
	bool operator>(const persona&) const;

    friend ostream& operator<<(ostream&, const persona&);
    friend istream& operator>>(istream&, persona&);
};

#endif
