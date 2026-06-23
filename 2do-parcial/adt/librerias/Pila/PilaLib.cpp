#include <iostream>
#include <stack>
#include <limits>
using namespace std;

class persona {
private:
    string nombre;
    int edad;

public:
    persona() : nombre(""), edad(0) {}
    persona(string n, int e) {
    	
        nombre = n;
        edad = e;
    }
    void setNombre(string n) { nombre = n; }
    void setEdad(int e) { edad = e; }
    
    string getNombre() const { return nombre; }
    int getEdad() const { return edad; }
};

ostream& operator<<(ostream &os, const persona &p) {
    os << "Nombre: " << p.getNombre()
       << " Edad: " << p.getEdad();
    return os;
}
istream& operator>>(istream &is, persona &p) {
    string nombre;
    int edad;

    is.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Nombre: ";
    getline(is, nombre);

    cout << "Edad: ";
    is >> edad;

    p.setNombre(nombre);
    p.setEdad(edad);

    return is;
}
template<typename T>
void mostrar(stack<T> pila) { 
	cout<<"Pila actual"<<endl;
    while (!pila.empty()) {
        cout << pila.top() << endl;
        pila.pop();
    }
}
template<typename T>
void menu(){
	int op;
	stack<T> pila;
	T t;
	int c=1;
	while(c!=0){
		cout<<"Operacion 1.push 2.pop 3.leer"<<endl;
		cin>>op;
		switch(op){	
		case 1:
			cout<<"Introduzca los dato"<<endl;
			cin>> t;
			pila.push(t);
		break;
		case 2:
			if(!pila.empty()) {
			cout<<"Valor eliminado: "<<pila.top()<<endl;
        	pila.pop();
    		}
    		else{
    			cout<<"Pila vacia"<<endl;
			}
		break;
		case 3:
			mostrar(pila);
		break;
		}
		cout<<"Continuar? 1/0"<<endl;
		cin>>c;
	}
	
}

int main() {
	int op;
	cout<<"Tipo de dato 1.Int 2.Float 3.String 4.Class"<<endl;
	cin>>op;
	switch(op){
		case 1:
		menu<int>();
		break;
		case 2:
		menu<float>();
		break;
		case 3:
		menu<string>();
		break;
		case 4:
		menu<persona>();
		break;
		default:
		cout<<"Valor invalido"<<endl;
	}
    return 0;
}
