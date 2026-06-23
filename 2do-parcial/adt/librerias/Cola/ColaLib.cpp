#include <iostream>
#include <queue>
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

// SALIDA
ostream& operator<<(ostream &os, const persona &p) {
    os << "Nombre: " << p.getNombre()
       << " Edad: " << p.getEdad();
    return os;
}

// ENTRADA
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

// MOSTRAR
template<typename T>
void mostrar(queue<T> cola) {
    cout << "\nCola actual:\n";
    while (!cola.empty()) {
        cout << cola.front() << endl;
        cola.pop();
    }
}

// CONTAR
template<typename T>
int contar(queue<T> cola) {
    int c = 0;
    while (!cola.empty()) {
        cola.pop();
        c++;
    }
    return c;
}

// ==========================
// VERSION SIN if constexpr
// ==========================

// Para tipos normales
template<typename T>
void leerDato(T &t) {
    cin >> t;
}

// Especialización para string
template<>
void leerDato<string>(string &t) {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, t);
}

// ==========================
// MENU
// ==========================
template<typename T>
void menu() {
    queue<T> cola;
    int op, c = 1;
    T t;

    while (c != 0) {
        cout << "\n--- MENU COLA ---\n";
        cout << "1. Enqueue\n2. Dequeue\n3. Mostrar\n4. Frente\n5. Contar\n";
        cout << "Seleccione: ";
        cin >> op;

        switch (op) {
        case 1:
            cout << "Ingrese dato:\n";
            leerDato(t);
            cola.push(t);
            break;

        case 2:
            if (!cola.empty()) {
                cout << "Eliminado: " << cola.front() << endl;
                cola.pop();
            } else {
                cout << "Cola vacia\n";
            }
            break;

        case 3:
            mostrar(cola);
            break;

        case 4:
            if (!cola.empty()) {
                cout << "Frente: " << cola.front() << endl;
            } else {
                cout << "Cola vacia\n";
            }
            break;

        case 5:
            cout << "Total: " << contar(cola) << endl;
            break;

        default:
            cout << "Opcion invalida\n";
        }

        cout << "Continuar? 1 = si / 0 = no: ";
        cin >> c;
    }
}

// MAIN
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
