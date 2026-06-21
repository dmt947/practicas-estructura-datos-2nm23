#include <iostream>
#include "pila.h"

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	pila pila;
    int op;
    string dato;

    do {
        cout << "\n***** MENU DE PILA *****\n";
        cout << "1. Insertar\n";
        cout << "2. Eliminar\n";
        cout << "3. Ver tope\n";
        cout << "4. Mostrar pila\n";
        cout << "5. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> op;

        switch (op) {
            case 1:
                cout << "Ingrese dato a insertar: ";
                cin >> dato;
                pila.insertar(dato);
                break;
            case 2:
                pila.eliminar();
                break;
            case 3:
                pila.verTope();
                break;
            case 4:
                pila.mostrarPila();
                break;
            case 5:
                cout << "Saliendo...\n";
                break;
            default:
                cout << "Opcion invalida.\n";
        }
    } while (op != 5);
	
	return 0;
}