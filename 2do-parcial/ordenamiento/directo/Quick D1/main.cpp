#include <iostream>
#include <vector>
#include "Quick.h"
#include "Utilidades.h"
#include "persona.h"
using namespace std;

int main(){
    int CA,TV;

    cout<<"Cantidad de valores\n";
    cin>>CA;

    cout<<"Tipo Entero(1)/Float(2)/String(3)/Persona(4)\n";
    cin>>TV;

    if(TV == 1){
        vector<int> v(CA);
        Utilidades<int>::leer(v);

        IOrdenador<int>* ord = new Quick<int>(); // POLIMORFISMO

        Utilidades<int>::imprimir(v);
        ord->ordenar(v);
        Utilidades<int>::imprimir(v);

        delete ord;
    }
    else if(TV == 2){
        vector<float> v(CA);
        Utilidades<float>::leer(v);

        IOrdenador<float>* ord = new Quick<float>();

        Utilidades<float>::imprimir(v);
        ord->ordenar(v);
        Utilidades<float>::imprimir(v);

        delete ord;
    }
    else if(TV == 3){
        vector<string> v(CA);
        Utilidades<string>::leerString(v);

        IOrdenador<string>* ord = new Quick<string>();

        Utilidades<string>::imprimir(v);
        ord->ordenar(v);
        Utilidades<string>::imprimir(v);

        delete ord;
    }
    else if(TV == 4){
        vector<persona> v(CA);

        cout<<"Ordenar por Nombre(1)/Edad(2)\n";
        cin>>persona::cr;

        Utilidades<persona>::leer(v);

        IOrdenador<persona>* ord = new Quick<persona>();

        Utilidades<persona>::imprimir(v);
        ord->ordenar(v);
        Utilidades<persona>::imprimir(v);

        delete ord;
    }

    return 0;
}
