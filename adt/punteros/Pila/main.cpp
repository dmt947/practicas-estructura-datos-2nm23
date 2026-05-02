#include "Pila.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
    char r = ' ';
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
            Pila<int> p;
            while(r != 'f')
            {
                cout << "1. pop()" << endl;
                cout << "2. push()" << endl;
                cout << "3. peek()" << endl;
                cout << "Introduzca la accion a realizar ('f' si desea finalizar y usar otro tipo de dato): ";
                cin >> r;
                switch(r)
                {
                case '1':
                    cout <<"Se elimino: "<< p.pop() <<endl;
                    break;
                case '2':
                    int temp;
                    cout << "Introduzca el elemento que sera introducido a la pila: ";
                    cin >> temp;
                    p.push(temp);
                    cout << "Se agrego: " << temp << endl;
                    break;
                case '3':
                    cout << "El ultimo elemento es: " << p.peek() << endl;
                    break;
                }
            }
        }
        if(r == '2') // float
        {
            Pila<float> p;
            while(r != 'f')
            {
                cout << "1. pop()" << endl;
                cout << "2. push()" << endl;
                cout << "3. peek()" << endl;
                cout << "Introduzca la accion a realizar ('f' si desea finalizar y usar otro tipo de dato): ";
                cin >> r;
                switch(r)
                {
                case '1':
                    cout <<"Se elimino: "<< p.pop() <<endl;
                    break;
                case '2':
                    float temp;
                    cout << "Introduzca el elemento que sera introducido a la pila: ";
                    cin >> temp;
                    p.push(temp);
                    cout << "Se agrego: " << temp << endl;
                    break;
                case '3':
                    cout << "El ultimo elemento es: " << p.peek() << endl;
                    break;
                }
            }
        }
        if(r == '3') // string
        {
            Pila<string> p;
            string temp;
            while(r != 'f')
            {
                cout << "1. pop()" << endl;
                cout << "2. push()" << endl;
                cout << "3. peek()" << endl;
                cout << "Introduzca la accion a realizar ('f' si desea finalizar y usar otro tipo de dato): ";
                cin >> r;
                switch(r)
                {
                case '1':
                    cout <<"Se elimino: "<< p.pop() <<endl;
                    break;
                case '3':
                    cout << "El ultimo elemento es: " << p.peek() << endl;
                    break;
                case '2':
                    cout << "Introduzca la cadena que sera introducido a la pila (sin espacios): ";
                    cin >> temp;
                    p.push(temp);
                    cout << "Se agrego: " << temp << endl;
                    break;
                }
            }
        }
    }
    return 0;
}
