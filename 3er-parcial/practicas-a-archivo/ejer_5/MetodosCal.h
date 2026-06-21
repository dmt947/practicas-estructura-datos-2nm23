#ifndef METODOSCAL_H
#define METODOSCAL_H
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
		void multiplicacion();
		void division();
		
		void guardarEnArchivo(string texto);
		
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

		void potencia();
		void raiz();
};

#endif