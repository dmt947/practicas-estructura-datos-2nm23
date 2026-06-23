#ifndef COLA_H
#define COLA_H

#include <queue>
#include <string>

class cola
{
	public:
		cola();
		~cola();
		void encolar(std::string dato);
    	void desencolar();
    	void mostrar();
    	
	private:
    	std::queue<std::string> datos;
    	std::string archivoDatos;

    	void guardarEnArchivo();
    	void cargarDesdeArchivo();
};

#endif