#include "Lista.h"
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
            Lista<int> p;
            while(r != 'f')
            {
                cout << "1. remove()" << endl;
                cout << "2. add()" << endl;
                cout << "3. get()" << endl;
                cout << "Introduzca la accion a realizar ('f' si desea finalizar y usar otro tipo de dato): ";
                cin >> r;
                switch(r)
                {
                case '1':
                    cout <<"Introduzca el indice del elemento a remove: ";
                    cin >> i;
                    cout << "Se elimino: "<< p.remove(i) << " en el indice "<< i <<endl;
                    cout << "Longitud: " << p.longitud() << endl;
                    break;
                case '2':
                    int temp;
                    cout << "Introduzca el elemento que sera introducido a la Lista: ";
                    cin >> temp;
                    cout << "Introduzca el indice en donde sera introducido: ";
                    cin >> i;
                    if(p.add(temp, i))
                    {
                        cout << "Se agrego: " << temp << " en el indice " << i << endl;
                        cout << "Longitud: " << p.longitud() << endl;
                    }
                    else
                    {
                        cout << "Hubo un error" << endl;
                    }
                    break;
                case '3':
                    cout << "Introduzca el indice del elemento a mostrar: ";
                    cin >> i;
                    cout << "El elemento en "<< i << " es: " << p.get(i) << endl;
                    cout << "Longitud: " << p.longitud() << endl;
                    break;
                }
            }
        }
        if(r == '2') // float
        {
            Lista<float> p;
            int i;
            while(r != 'f')
            {
                cout << "1. remove()" << endl;
                cout << "2. add()" << endl;
                cout << "3. get()" << endl;
                cout << "Introduzca la accion a realizar ('f' si desea finalizar y usar otro tipo de dato): ";
                cin >> r;
                switch(r)
                {
                case '1':
                    cout <<"Introduzca el indice del elemento a remove: ";
                    cin >> i;
                    cout <<"Se elimino: "<< p.remove(i) <<" en el indice "<< i <<endl;
                    cout << "Longitud: " << p.longitud() << endl;
                    break;
                case '2':
                    float temp;
                    cout << "Introduzca el elemento que sera introducido a la Lista: ";
                    cin >> temp;
                    cout << "Introduzca el indice en donde sera introducido: ";
                    cin >> i;
                    if(p.add(temp, i))
                    {
                        cout << "Se agrego: " << temp << " en el indice " << i << endl;
                        cout << "Longitud: " << p.longitud() << endl;
                    }
                    else
                    {
                        cout << "Hubo un error" << endl;
                    }
                    break;
                case '3':
                    cout << "Introduzca el indice del elemento a mostrar: ";
                    cin >> i;
                    cout << "El elemento en "<< i << " es: " << p.get(i) << endl;
                    cout << "Longitud: " << p.longitud() << endl;
                    break;
                }
            }
        }
        if(r == '3') // string
        {
            Lista<string> p;
            int i;
            string temp;
            while(r != 'f')
            {
                cout << "1. remove()" << endl;
                cout << "2. add()" << endl;
                cout << "3. get()" << endl;
                cout << "Introduzca la accion a realizar ('f' si desea finalizar y usar otro tipo de dato): ";
                cin >> r;
                switch(r)
                {
                case '1':
                    cout <<"Introduzca el indice del elemento a remove: ";
                    cin >> i;
                    cout <<"Se elimino: "<< p.remove(i) <<" en el indice "<< i <<endl;
                    cout << "Longitud: " << p.longitud() << endl;
                    break;
                case '2':
                    cout << "Introduzca el elemento que sera introducido a la Lista: ";
                    cin >> temp;
                    cout << "Introduzca el indice en donde sera introducido: ";
                    cin >> i;
                    if(p.add(temp, i))
                    {
                        cout << "Se agrego: " << temp << " en el indice " << i << endl;
                        cout << "Longitud: " << p.longitud() << endl;
                    }
                    else
                    {
                        cout << "Hubo un error" << endl;
                    }
                    break;
                case '3':
                    cout << "Introduzca el indice del elemento a mostrar: ";
                    cin >> i;
                    cout << "El elemento en "<< i << " es: " << p.get(i) << endl;
                    cout << "Longitud: " << p.longitud() << endl;
                    break;
                }
            }
        }
    }
    return 0;
}
