#include "Empleado.h"
#include <string>

Empleado::Empleado()
{
	_id = 0;
	strcpy(_apellido, "");
	strcpy(_nombre, "");
	strcpy(_dni, "");
	_tipo = EmpleadoTipo::Mesero;
}

EmpleadoTipo Empleado::getTipo()
{
	return _tipo;
}

void Empleado::setTipo(EmpleadoTipo t)
{
	_tipo = t;
}
