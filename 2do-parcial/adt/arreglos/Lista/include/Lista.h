#ifndef LISTA_H
#define LISTA_H

class Lista
{
public:
    Lista();
    ~Lista();

    virtual bool vacia() = 0;
    virtual bool llena() = 0;


    int longitud() const;

protected:
    int ultimo;
private:

};

#endif // LISTA_H
