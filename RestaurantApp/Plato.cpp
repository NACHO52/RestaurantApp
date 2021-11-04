#include "Plato.h"
#include <string>

Plato::Plato()
{
    _id = 0;
    strcpy(_nombre, "");
    _precio = 0;
    _tipo = PlatoTipo::Entrada;
    _disponible = true;
}

int Plato::getId()
{
    return _id;
}

char* Plato::getNombre()
{
    return _nombre;
}

float Plato::getPrecio()
{
    return _precio;
}

PlatoTipo Plato::getTipo()
{
    return _tipo;
}

bool Plato::getDisponible()
{
    return _disponible;
}

void Plato::setId(int i)
{
    _id = i;
}

void Plato::setNombre(char* n)
{
    strcpy(_nombre, n);
}

void Plato::setPrecio(float p)
{
    _precio = p;
}

void Plato::setTipo(PlatoTipo t)
{
    _tipo = t;
}

void Plato::setDispobible(bool d)
{
    _disponible = d;
}
