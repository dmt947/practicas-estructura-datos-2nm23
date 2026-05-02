#include "ListaT.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
    char r = ' ';
    int i = 0;
    while(r != 'x')
    {
        cout << "Introduzca el tipo de dato: " << endl;
        cout << "1. int" << endl;
        cout << "2. float" << endl;
        cout << "3. string" << endl;
        cout << "O introduzca 'x' para finalizar" << endl;
        cin >> r;
        if(r == '1')// int
        {
            ListaT<int> p;
            while(r != 'f')
            {
                cout << "1. eliminar()" << endl;
                cout << "2. insertar()" << endl;
                cout << "3. obtener()" << endl;
                cout << "Introduzca la accion a realizar ('f' si desea finalizar y usar otro tipo de dato): ";
                cin >> r;
                switch(r)
                {
                case '1':
                    cout <<"Introduzca el indice del elemento a eliminar: ";
                    cin >> i;
                    cout << "Se elimino: "<< p.obtener(i) << " en el indice "<< i <<endl;
                    p.eliminar(i);
                    cout << "Longitud: " << p.longitud() << endl;
                    break;
                case '2':
                    int temp;
                    cout << "Introduzca el elemento que sera introducido a la Lista: ";
                    cin >> temp;
                    cout << "Introduzca el indice en donde sera introducido: ";
                    cin >> i;
                    p.insertar(temp, i);
                    cout << "Se agrego: " << temp << " en el indice " << i << endl;
                    cout << "Longitud: " << p.longitud() << endl;
                    break;
                case '3':
                    cout << "Introduzca el indice del elemento a mostrar: ";
                    cin >> i;
                    cout << "El elemento en "<< i << " es: " << p.obtener(i) << endl;
                    cout << "Longitud: " << p.longitud() << endl;
                    break;
                }
            }
        }
        if(r == '2') // float
        {
            ListaT<float> p;
            int i;
            while(r != 'f')
            {
                cout << "1. eliminar()" << endl;
                cout << "2. insertar()" << endl;
                cout << "3. obtener()" << endl;
                cout << "Introduzca la accion a realizar ('f' si desea finalizar y usar otro tipo de dato): ";
                cin >> r;
                switch(r)
                {
                case '1':
                    cout <<"Introduzca el indice del elemento a eliminar: ";
                    cin >> i;
                    cout <<"Se elimino: "<< p.obtener(i) <<" en el indice "<< i <<endl;
                    p.eliminar(i);
                    cout << "Longitud: " << p.longitud() << endl;
                    break;
                case '2':
                    float temp;
                    cout << "Introduzca el elemento que sera introducido a la Lista: ";
                    cin >> temp;
                    cout << "Introduzca el indice en donde sera introducido: ";
                    cin >> i;
                    p.insertar(temp, i);
                    cout << "Se agrego: " << temp << " en el indice " << i << endl;
                    cout << "Longitud: " << p.longitud() << endl;
                    break;
                case '3':
                    cout << "Introduzca el indice del elemento a mostrar: ";
                    cin >> i;
                    cout << "El elemento en "<< i << " es: " << p.obtener(i) << endl;
                    cout << "Longitud: " << p.longitud() << endl;
                    break;
                }
            }
        }
        if(r == '3') // string
        {
            ListaT<string> p;
            int i;
            string temp;
            while(r != 'f')
            {
                cout << "1. eliminar()" << endl;
                cout << "2. insertar()" << endl;
                cout << "3. obtener()" << endl;
                cout << "Introduzca la accion a realizar ('f' si desea finalizar y usar otro tipo de dato): ";
                cin >> r;
                switch(r)
                {
                case '1':
                    cout <<"Introduzca el indice del elemento a eliminar: ";
                    cin >> i;
                    cout <<"Se elimino: "<< p.obtener(i) <<" en el indice "<< i <<endl;
                    p.eliminar(i);
                    cout << "Longitud: " << p.longitud() << endl;
                    break;
                case '2':
                    cout << "Introduzca el elemento que sera introducido a la Lista: ";
                    cin >> temp;
                    cout << "Introduzca el indice en donde sera introducido: ";
                    cin >> i;
                    p.insertar(temp, i);
                    cout << "Se agrego: " << temp << " en el indice " << i << endl;
                    cout << "Longitud: " << p.longitud() << endl;
                    break;
                case '3':
                    cout << "Introduzca el indice del elemento a mostrar: ";
                    cin >> i;
                    cout << "El elemento en "<< i << " es: " << p.obtener(i) << endl;
                    cout << "Longitud: " << p.longitud() << endl;
                    break;
                }
            }
        }
    }
    return 0;
}
