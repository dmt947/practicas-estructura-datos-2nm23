#ifndef AUTO_H
#define AUTO_H

class Auto{
protected:
    float precio;
    int anio;
    Auto* pAuto;

public:
    Auto();
    Auto(float precio, int anio);
    ~Auto();

    void setPrecio(float p);
    float getPrecio();

    void setAnio(int a);
    int getAnio();
    
};

#endif 
