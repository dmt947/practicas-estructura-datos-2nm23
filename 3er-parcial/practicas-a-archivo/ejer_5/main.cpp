#include <iostream>
#include "MetodosCal.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	int CT;
	float T[3];
	int op;
	
	cout<<"Cantidad de terminos (0-3): " <<endl;
	cin >> CT;
	if(CT<=3 && CT>=0){
			for(int i=0;i<CT;i++){
			cout<<"Termino "<<i+1<<endl;
			cin>>T[i];
		}
	
		cout<<"Operacion"<<endl;
		cout<<"1- Suma"<<endl;
		cout<<"2- Resta"<<endl;
		cout<<"3- Multiplicacion"<<endl;
		cout<<"4- Division"<<endl;
		cout<<"5- Potencia"<<endl;
		cout<<"6- Raiz cuadrada"<<endl;
		cout<<"Escoje una opcion: ";
		cin>>op;
	
		calculadoraExtra* A1;
	
		if (CT == 0){
			A1 = new calculadoraExtra();
		}
		else if(CT == 1){
			A1 = new calculadoraExtra(T[0]);
		}
		else if(CT==2){
			A1 = new calculadoraExtra(T[0], T[1]);
		}
		else if(CT == 3){
			A1 = new calculadoraExtra(T[0], T[1], T[2]);
		}

		switch(op){
			case 1: 
				A1->suma();
			break;
			case 2: 
				A1->resta();
			break;
			case 3: 
				A1->multiplicacion();
			break;
			case 4: 
				A1->division();
			break;
			case 5: 
				A1->potencia();
			break;
			case 6: 
				A1->raiz();
			break;
		}
		delete A1;	
	}else{
		cout<<"Cantidad invalida"<<endl;
	}
	return 0;
}