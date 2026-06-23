#ifndef PILA_H
#define PILA_H

#include <stack>
#include <string>

class pila
{
	public:
		pila();
		~pila();
		void insertar(std::string dato);
    	void eliminar();
    	void verTope();
    	void mostrarPila();
	
	private:
		std::stack<std::string> datos;
    	std::string archivoDatos;

    	void guardarEnArchivo();
    	void cargarDesdeArchivo();
};

#endif