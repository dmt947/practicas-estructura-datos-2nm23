#ifndef AUTO_H
#define AUTO_H

#include <string>

class Auto
{
	//constructor y destructor, ahi es donde se podria poner los parametros, si se requiere
	public:
		Auto();
		~Auto();
	
	//metodos de la clase
		void setPrecio(float p);
    	float getPrecio();

    	void setAnio(int a);
    	int getAnio();
    
    	void guardarEnArchivo(std::string texto);
		void registrarAuto();
		
	//variabeles del programa
	protected:
		float precio;
		int anio;
};

#endif