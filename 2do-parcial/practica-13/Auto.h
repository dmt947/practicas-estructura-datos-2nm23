#ifndef AUTO_H
#define AUTO_H

class Auto{
protected:
    float precio;
    int anio;

public:
    Auto();
    ~Auto();

    void setPrecio(float p);
    float getPrecio();

    void setAnio(int a);
    int getAnio();
    
};

#endif 
