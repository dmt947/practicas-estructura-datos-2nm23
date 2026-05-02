#ifndef COLECCION_H
#define COLECCION_H


class Coleccion
{
public:
    Coleccion();
    virtual ~Coleccion();

    virtual bool vacia() = 0;
    virtual int longitud() = 0;

protected:
    int tam;
private:

};

#endif // COLECCION_H
