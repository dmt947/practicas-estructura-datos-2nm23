#ifndef OPERACIONES_H
#define OPERACIONES_H

#include <string>

class Operaciones
{
	public:
		Operaciones();
		~Operaciones();
		
		void setNumeros(int a, int b, int c, int d, int e);

    	float getSuma();
    	float getPromedio();
    	float getMedia();
    	int getMaximo();
    	int getMinimo();
    	
    	void guardarEnArchivo(std::string texto);
		void registrarOperaciones();
    	
	protected:
		int num1,num2,num3,num4,num5;
		
};

#endif