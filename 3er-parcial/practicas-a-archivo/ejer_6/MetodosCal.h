#ifndef METODOSCAL_H
#define METODOSCAL_H
#include <string>
using namespace std;

class MetodosCal
{
	public:
		MetodosCal(); 
    	MetodosCal(float);
    	MetodosCal(float, float);
    	MetodosCal(float, float, float);
    	~MetodosCal();
    	
		void suma();
		void resta();
		virtual void multiplicacion();
		virtual void division();
		
		void guardarEnArchivo(string);
		
	protected:
		float T1;
		float T2;
		float T3;
		int NT;
		float R;
};

class calculadoraExtra : public MetodosCal{

	public:
		calculadoraExtra();
		calculadoraExtra(float);
		calculadoraExtra(float,float);
		calculadoraExtra(float,float,float);

		virtual void potencia();
		void raiz();
		
		
};

class calculadoraNueva : public calculadoraExtra{

	public:
		calculadoraNueva();
		calculadoraNueva(float);
		calculadoraNueva(float,float);
		calculadoraNueva(float,float,float);

		void multiplicacion() override;
		void division() override;
		void potencia() override;
		
};

#endif

