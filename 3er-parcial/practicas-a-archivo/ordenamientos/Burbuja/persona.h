#ifndef PERSONA_H
#define PERSONA_H
#include<iostream>
#include <string>
#include <vector>
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

		void setNombre(const string& n);
		void setEdad(int e);

		bool operator<(const persona& otra) const;  //Definicion de los operadores ,>, >> y << para la clase.
		bool operator>(const persona& otra) const;
		friend ostream& operator<<(ostream &os, const persona &p);
		friend istream& operator>>(istream &is, persona &p);
};
#endif
