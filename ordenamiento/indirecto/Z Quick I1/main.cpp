#include <iostream>
#include <vector>

#include "QuickI.h"
#include "UtilidadesI.h"
#include "persona.h"

using namespace std;
int main(){
    int CA, TV;

    cout << "Cantidad de valores\n";
    cin >> CA;

    cout << "Tipo Entero(1)/Float(2)/String(3)/Persona(4)\n";
    cin >> TV;

    if(TV == 1){
        vector<int> n(CA);
        vector<int*> p(CA);

        Utilidades<int>::leer(n);
        Utilidades<int>::direcciones(p, n);

        IOrdenador<int>* ord = new Quick<int>();

        Utilidades<int>::imprimir(p);
        ord->ordenar(p);
        Utilidades<int>::imprimir(p);

        delete ord;
    }
    else if(TV == 2){
        vector<float> n(CA);
        vector<float*> p(CA);

        Utilidades<float>::leer(n);
        Utilidades<float>::direcciones(p,n);

        IOrdenador<float>* ord = new Quick<float>();

        Utilidades<float>::imprimir(p);
        ord->ordenar(p);
        Utilidades<float>::imprimir(p);

        delete ord;
    }
    else if(TV == 3){
        vector<string> n(CA);
        vector<string*> p(CA);

        Utilidades<string>::leerString(n);
        Utilidades<string>::direcciones(p, n);

        IOrdenador<string>* ord = new Quick<string>();

        Utilidades<string>::imprimir(p);
        ord->ordenar(p);
        Utilidades<string>::imprimir(p);

        delete ord;
    }
    else if(TV == 4){
        vector<persona> n(CA);
        vector<persona*> p(CA);

        cout << "Ordenar por Nombre(1)/Edad(2)\n";
        cin >> persona::cr;

        Utilidades<persona>::leer(n);
        Utilidades<persona>::direcciones(p, n);

        IOrdenador<persona>* ord = new Quick<persona>();

        Utilidades<persona>::imprimir(p);
        ord->ordenar(p);
        Utilidades<persona>::imprimir(p);

        delete ord;
    }

    return 0;
}
