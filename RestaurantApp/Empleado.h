#ifndef EMPLEADO_H
#define EMPLEADO_H
#include <string>
#include "Persona.h"
using namespace std;


enum class EmpleadoTipo {
	Mesero = 1,
	Repartidor = 2
};

class Empleado : public Persona
{
	private:
		EmpleadoTipo _tipo;
		bool _activo;

	public:
		Empleado();

		EmpleadoTipo getTipo();
		string getTipoStr();
		bool getActivo();
		string getActivoStr();

		void setTipo(EmpleadoTipo t);
		void setActivo(bool a);
};

#endif
