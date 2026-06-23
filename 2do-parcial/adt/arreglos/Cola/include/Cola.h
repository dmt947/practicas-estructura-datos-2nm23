#ifndef COLA_H
#define COLA_H

class Cola
{
public:
    Cola();
    virtual ~Cola();

    virtual bool vacia() = 0;
    virtual bool llena() = 0;

protected:
    int frente, final;
private:

};

#endif // COLA_H
