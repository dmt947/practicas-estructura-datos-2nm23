#include <iostream>
#include <algorithm>
#include "Operaciones.h"
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	int n1,n2,n3,n4,n5;

    cout << "Ingrese 5 numeros: ";
    cin >> n1 >> n2 >> n3 >> n4 >> n5;
    
    Operaciones op;

    op.setNumeros(n1,n2,n3,n4,n5);

    cout<<"\nSuma: "<<op.getSuma()<<endl;
    cout<<"Promedio: "<<op.getPromedio()<<endl;
    cout<<"Media: "<<op.getMedia()<<endl;
    cout<<"Maximo: "<<op.getMaximo()<<endl;
    cout<<"Minimo: "<<op.getMinimo()<<endl;
    
    op.registrarOperaciones();
	
	return 0;
}