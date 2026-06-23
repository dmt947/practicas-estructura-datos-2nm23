#include <iostream>
#include <vector>
#include <fstream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

long long factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}

int fibonacci(int n) {
    if (n <= 0) return 0;
    if (n == 1) return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int sumaSucesivaRecursiva(const std::vector<int>& vec, size_t indice) {
    if (indice == vec.size()) return 0;
    return vec[indice] + sumaSucesivaRecursiva(vec, indice + 1);
}

int main(int argc, char** argv) {
	
	int num_fact = 5;
    int num_fibo = 7;
    std::vector<int> numeros_calculadora = {10, 20, 30, 40};

    long long res_factorial = factorial(num_fact);
    int res_fibonacci = fibonacci(num_fibo);
    int res_calculadora = sumaSucesivaRecursiva(numeros_calculadora, 0);

    std::ofstream archivo("Recursividad.txt");
    if (archivo.is_open()) {
        archivo << "RECURSIVIDAD\n";
        archivo << "=========================================\n\n";
        
        archivo << "1. Factorial de " << num_fact << ":\n";
        archivo << "   Resultado: " << res_factorial << "\n\n";
        
        archivo << "2. Numero de Fibonacci en la posicion " << num_fibo << ":\n";
        archivo << "   Resultado: " << res_fibonacci << "\n\n";
        
        archivo << "3. Calculadora (Suma sucesiva recursiva):\n";
        archivo << "   Elementos: ";
        for (int num : numeros_calculadora) archivo << num << " ";
        archivo << "\n   Resultado Total: " << res_calculadora << "\n";
        
        archivo.close();
        std::cout << "Resultados guardados en 'recursividad.txt'.\n";
    } else {
        std::cerr << "Error al abrir el archivo de salida.\n";
    }
	
	return 0;
}