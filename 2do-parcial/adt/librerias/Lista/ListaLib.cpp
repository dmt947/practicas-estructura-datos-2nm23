#include <iostream>
#include <list>
#include <limits>
using namespace std;
class persona {
private:
    string nombre;
    int edad;

public:
    persona() : nombre(""), edad(0) {}
    persona(string n, int e) : nombre(n), edad(e) {}

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
void mostrar(list<T> lista) {
    cout << "\nLista actual:\n";
    for (auto it = lista.begin(); it != lista.end(); ++it) {
        cout << *it << endl;
    }
}
template<typename T>
void buscar(list<T> lista, T valor) {
    for (auto it = lista.begin(); it != lista.end(); ++it) {
        if (*it == valor) {
            cout << "Elemento encontrado\n";
            return;
        }
    }
    cout << "Elemento no encontrado\n";
}
template<typename T>
void leerDato(T &t) {
    cin >> t;
}
template<>
void leerDato<string>(string &t) {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, t);
}
template<typename T>
void menu() {
    list<T> lista;
    int op, c = 1;
    T t;

    while (c != 0) {
        cout << "\n--- MENU LISTA ---\n";
        cout << "1. Insertar inicio\n";
        cout << "2. Insertar final\n";
        cout << "3. Eliminar inicio\n";
        cout << "4. Eliminar final\n";
        cout << "5. Mostrar\n";
        cout << "Seleccione: ";
        cin >> op;

        switch (op) {
        case 1:
            cout << "Ingrese dato:\n";
            leerDato(t);
            lista.push_front(t);
            break;

        case 2:
            cout << "Ingrese dato:\n";
            leerDato(t);
            lista.push_back(t);
            break;

        case 3:
            if (!lista.empty()) {
                cout << "Eliminado: " << lista.front() << endl;
                lista.pop_front();
            } else {
                cout << "Lista vacia\n";
            }
            break;

        case 4:
            if (!lista.empty()) {
                cout << "Eliminado: " << lista.back() << endl;
                lista.pop_back();
            } else {
                cout << "Lista vacia\n";
            }
            break;

        case 5:
            mostrar(lista);
            break;

        default:
            cout << "Opcion invalida\n";
        }

        cout << "Continuar? 1 = si / 0 = no: ";
        cin >> c;
    }
}
int main() {
    int op;

    cout << "--- TIPO DE DATO ---\n";
    cout << "1. Int\n2. Float\n3. String\n4. Persona\n";
    cin >> op;

    switch (op) {
    case 1: menu<int>(); break;
    case 2: menu<float>(); break;
    case 3: menu<string>(); break;
    case 4: menu<persona>(); break;
    default: cout << "Opcion invalida\n";
    }

    return 0;
}
