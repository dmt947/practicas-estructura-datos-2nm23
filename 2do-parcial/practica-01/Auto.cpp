#include "Auto.h"
Auto::Auto(){}

Auto::Auto(float precio, int anio):precio(precio), anio(anio){}

Auto::~Auto(){}

void Auto::setPrecio(float p){
    precio = p;
}

float Auto::getPrecio(){
    return precio;
}

void Auto::setAnio(int a){
    anio = a;
}

int Auto::getAnio(){
    return anio;
}

