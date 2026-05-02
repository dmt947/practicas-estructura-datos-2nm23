#ifndef PERSONA_H
#define PERSONA_H

#include <string>

class Persona{
protected:
    std::string nom;
    std::string apat;
    std::string amat;
    char genero;
    int edad;
    Persona* pPersona;

public:
    Persona();
    Persona(std::string nom, std::string apat, std::string amat, char genero, int edad); 
    ~Persona();

    void setNombre(std::string n);
    void setApat(std::string ap);
    void setAmat(std::string am);
    void setGenero(char g);
    void setEdad(int e);

    std::string getNombre();
    std::string getApat();
    std::string getAmat();
    char getGenero();
    int getEdad();
};

#endif

