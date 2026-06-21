#include <iostream>
#include <vector>
#include <string>
#include <fstream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

std::string polvoDeCantor(int longitud) {
    if (longitud <= 1) return "*";
    int segmento = longitud / 3;
    std::string espacio(segmento, ' ');
    std::string sub_problema = polvoDeCantor(segmento);
    
    return sub_problema + espacio + sub_problema;
}

std::vector<std::string> trianguloSierpinski(int nivel) {
    if (nivel == 0) return {"*"};
    
    std::vector<std::string> anterior = trianguloSierpinski(nivel - 1);
    std::string espacios(1 << (nivel - 1), ' '); 
    std::vector<std::string> resultado;
    
    for (const auto& linea : anterior) {
        resultado.push_back(espacios + linea + espacios);
    }
    
    for (const auto& linea : anterior) {
        resultado.push_back(linea + " " + linea);
    }
    
    return resultado;
}

int main(int argc, char** argv) {
	
	int longitud_cantor = 27; // Se sugiere usar potencias de 3 (3, 9, 27, 81...)
    int nivel_sierpinski = 4; // Profundidad de repetición del triángulo

    std::string resultado_cantor = polvoDeCantor(longitud_cantor);
    std::vector<std::string> resultado_sierpinski = trianguloSierpinski(nivel_sierpinski);

    std::ofstream archivo("Fractales.txt");
    if (archivo.is_open()) {
        archivo << "FRACTALES RECURSIVOS\n";
        archivo << "==================================================\n\n";
        
        archivo << "--- POLVO DE CANTOR ---\n";
        archivo << resultado_cantor << "\n\n\n";
        
        archivo << "--- TRIANGULO DE SIERPINSKI ---\n";
        for (const auto& linea : resultado_sierpinski) {
            archivo << linea << "\n";
        }
        
        archivo.close();
        std::cout << "Resultados guardados en 'fractales.txt'.\n";
    } else {
        std::cerr << "Error al abrir el archivo de salida.\n";
    }
	
	return 0;
}