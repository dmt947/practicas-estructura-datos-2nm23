#include "Persona.h"
#include <string>

Persona::Persona(){}

Persona::Persona(std::string nom, std::string apat, std::string amat, char genero, int edad):nom(nom), apat(apat), amat(amat), genero(genero), edad(edad){}

Persona::~Persona(){}

void Persona::setNombre(std::string n){
    nom = n;
}

void Persona::setApat(std::string n){
    apat = n;
}

void Persona::setAmat(std::string n){
    amat = n;
}

void Persona::setGenero(char g){
    genero = g;
}

void Persona::setEdad(int e){
    edad = e;
}

std::string Persona::getNombre(){
    return nom;
}

std::string Persona::getApat(){
    return apat;
}

std::string Persona::getAmat(){
    return amat;
}

char Persona::getGenero(){
    return genero;
}

int Persona::getEdad(){
    return edad;
}
