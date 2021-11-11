#include "Empleado.h"
#include <string>
using namespace std;

Empleado::Empleado()
{
	_id = 0;
	strcpy(_apellido, "");
	strcpy(_nombre, "");
	strcpy(_dni, "");
	_tipo = EmpleadoTipo::Mesero;
    _activo = true;
}

EmpleadoTipo Empleado::getTipo()
{
	return _tipo;
}

string Empleado::getTipoStr()
{
	string resultado;
    switch (_tipo)
    {
    case EmpleadoTipo::Mesero:
        resultado = "Mesero";
        break;
    case EmpleadoTipo::Repartidor:
        resultado = "Repartidor";
        break;
    default:
        resultado = "";
        break;
    }
	return resultado;
}

bool Empleado::getActivo()
{
    return _activo;
}

string Empleado::getActivoStr()
{
    return _activo ? "Si" : "No";
}

void Empleado::setTipo(EmpleadoTipo t)
{
	_tipo = t;
}

void Empleado::setActivo(bool a)
{
    _activo = a;
}
