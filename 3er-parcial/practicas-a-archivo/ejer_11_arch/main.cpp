#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>

using Matrix = std::vector<std::vector<int>>;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void guardarMatriz(std::ofstream& archivo, const std::string& titulo, const Matrix& matriz) {
    archivo << "--- " << titulo << " ---\n";
    for (const auto& fila : matriz) {
        archivo << "[ ";
        for (int elemento : fila) {
            archivo << std::setw(4) << elemento << " ";
        }
        archivo << "]\n";
    }
    archivo << "\n";
}


int main(int argc, char** argv) {
	
	Matrix A = {
        {1, 2, 3},
        {4, 5, 6}
    };
    
    Matrix B = {
        {7, 8},
        {9, 10},
        {11, 12}
    };
    
    int constante = 3;

    Matrix A_por_constante = A;
    for (auto& fila : A_por_constante) {
        for (auto& elemento : fila) {
            elemento *= constante;
        }
    }

    Matrix A_por_B(2, std::vector<int>(2, 0));
    for (size_t i = 0; i < 2; ++i) {
        for (size_t j = 0; j < 2; ++j) {
            for (size_t k = 0; k < 3; ++k) {
                A_por_B[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    // Guardar los resultados en el archivo de texto
    std::ofstream archivo("Matrices.txt");
    if (archivo.is_open()) {
        archivo << "RESULTADOS DE MATRICES\n";
        archivo << "=========================================\n\n";
        
        guardarMatriz(archivo, "Matriz Original A", A);
        guardarMatriz(archivo, "Matriz Original B", B);
        guardarMatriz(archivo, "Matriz A * Constante (" + std::to_string(constante) + ")", A_por_constante);
        guardarMatriz(archivo, "Matriz A * Matriz B (A x B)", A_por_B);
        
        archivo.close();
        std::cout << "Resultados guardados en 'matrices.txt'.\n";
    } else {
        std::cerr << "Error al abrir el archivo de salida.\n";
    }
	
	return 0;
}