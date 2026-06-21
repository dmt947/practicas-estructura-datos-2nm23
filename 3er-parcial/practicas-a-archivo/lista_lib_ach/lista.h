#ifndef LISTA_H
#define LISTA_H

#include <list>
#include <string>

class lista
{
	public:
		lista();
		~lista();
    	void insertar(std::string dato);
    	void eliminar(std::string dato);
    	void mostrar();
    	
	private:
		std::list<std::string> datos;
    	std::string archivoDatos;

    	void guardarEnArchivo();
    	void cargarDesdeArchivo();
};

#endif