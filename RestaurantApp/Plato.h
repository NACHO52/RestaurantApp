#ifndef PLATO_H
#define PLATO_H
#include <string>
using namespace std;



enum class PlatoTipo {
	Entrada = 1,
	Principal = 2,
	Guarnicion = 3,
	Postre = 4,
	Bebida = 5
};

class Plato
{
	private:
		int _id;
		char _nombre[20];
		float _precio;
		PlatoTipo _tipo;
		bool _disponible;
		//string _nombre;

	public:
		Plato();

		int getId();
		char* getNombre();
		float getPrecio();
		PlatoTipo getTipo();
		string getTipoStr();
		bool getDisponible();
		string getDisponibleStr();

		void setId(int i);
		void setNombre(char* n);
		void setPrecio(float p);
		void setTipo(PlatoTipo t);
		void setDispobible(bool d);
};

#endif

