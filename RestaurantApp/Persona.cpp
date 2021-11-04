#include "Persona.h"
#include <string>

Persona::Persona()
{
	_id = 0;
	strcpy(_apellido, "");
	strcpy(_nombre, "");
	strcpy(_dni, "");
}

void Persona::setId(int i)
{
	_id = i;
}

void Persona::setApellido(char* a)
{
	strcpy(_apellido, a);
}

void Persona::setNombre(char* n)
{
	strcpy(_nombre, n);
}

void Persona::setDni(char* d)
{
	strcpy(_dni, d);
}

int Persona::getId()
{
	return _id;
}

char* Persona::getApellido()
{
	return _apellido;
}

char* Persona::getNombre()
{
	return _nombre;
}

char* Persona::getDni()
{
	return _dni;
}
