#ifndef ESTADISTICAS_H
#define ESTADISTICAS_H


class Estadisticas
{
public:
    Estadisticas();
    ~Estadisticas();

    void ingresarDatos();
    int calcularSuma();
    float calcularPromedio();
    int obtenerMaximo();
    int obtenerMinimo();

protected:

private:
    int *numeros;
};

#endif // ESTADISTICAS_H
