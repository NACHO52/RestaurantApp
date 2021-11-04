#ifndef PLATO_H
#define PLATO_H

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

	public:
		Plato();

		int getId();
		char* getNombre();
		float getPrecio();
		PlatoTipo getTipo();
		bool getDisponible();

		void setId(int i);
		void setNombre(char* n);
		void setPrecio(float p);
		void setTipo(PlatoTipo t);
		void setDispobible(bool d);
};

#endif

