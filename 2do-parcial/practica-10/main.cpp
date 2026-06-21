#include "Estadisticas.h"
#include <iostream>

using namespace std;

int main()
{
    Estadisticas e;
    e.ingresarDatos();
    cout << "Promedio o media aritmetica: " << e.calcularPromedio() << endl;
    cout << "Maximo: " << e.obtenerMaximo() << endl;
    cout << "Minimo: " << e.obtenerMinimo() << endl;
    cout << "Suma: " << e.calcularSuma() << endl;
    return 0;
}
