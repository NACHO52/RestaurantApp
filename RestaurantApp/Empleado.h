#ifndef EMPLEADO_H
#define EMPLEADO_H

#include "Persona.h"


enum class EmpleadoTipo {
	Mesero = 1,
	Repartidor = 2
};

class Empleado : public Persona
{
	private:
		EmpleadoTipo _tipo;

	public:
		Empleado();

		EmpleadoTipo getTipo();
		void setTipo(EmpleadoTipo t);
};

#endif
