#include <iostream>
#include "lista.h"

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	lista lista;
    int opcion;
    string dato;

    do {
        cout << "\n***** MENU DE LISTA *****\n";
        cout << "1. Insertar\n";
        cout << "2. Eliminar\n";
        cout << "3. Mostrar\n";
        cout << "4. Salir\n";
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Ingrese dato a insertar: ";
                cin >> dato;
                lista.insertar(dato);
                break;
            case 2:
                cout << "Ingrese dato a eliminar: ";
                cin >> dato;
                lista.eliminar(dato);
                break;
            case 3:
                lista.mostrar();
                break;
            case 4:
                cout << "Saliendo...\n";
                break;
            default:
                cout << "Opcion invalida.\n";
        }
    } while (opcion != 4);
	
	return 0;
}