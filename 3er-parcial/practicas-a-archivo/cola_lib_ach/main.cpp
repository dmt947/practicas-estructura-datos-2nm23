#include <iostream>
#include "cola.h"

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	cola cola;
    int opcion;
    string dato;

    do {
        cout << "\n***** MENU DE COLA *****\n";
        cout << "1. Encolar\n";
        cout << "2. Desencolar\n";
        cout << "3. Mostrar\n";
        cout << "4. Salir\n";
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Ingrese dato a encolar: ";
                cin >> dato;
                cola.encolar(dato);
                break;
            case 2:
                cola.desencolar();
                break;
            case 3:
                cola.mostrar();
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