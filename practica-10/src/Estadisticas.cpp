#include "Estadisticas.h"
#include <iostream>

using namespace std;

Estadisticas::Estadisticas():numeros(new int[5]) {}

Estadisticas::~Estadisticas() {}

void Estadisticas::ingresarDatos()
{
    for(int i = 0; i < 5; i++)
    {
        cout << "Ingrese el numero " << i + 1 << ": ";
        cin >> *(numeros+i);
    }
}

int Estadisticas::calcularSuma()
{
    int s = 0;
    for(int i = 0; i < 5; i++)
    {
        s += *(numeros + i);
    }
    return s;
}

float Estadisticas::calcularPromedio()
{
    return calcularSuma()/5.0;
}

int Estadisticas::obtenerMaximo()
{
    int max = *numeros;
    for(int i = 1; i < 5; i++)
    {
        if(max < *(numeros + i))
        {
            max = *(numeros + i);
        }
    }
    return max;
}

int Estadisticas::obtenerMinimo()
{
    int min = *numeros;
    for(int i = 1; i < 5; i++)
    {
        if(min > *(numeros + i))
        {
            min = *(numeros + i);
        }
    }
    return min;
}
