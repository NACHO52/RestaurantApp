#include "Plato.h"
#include <string>
using namespace std;

Plato::Plato()
{
    _id = 0;
    strcpy(_nombre, "");
    //_nombre = "";
    _precio = 0;
    _tipo = PlatoTipo::Entrada;
    _disponible = true;
}

int Plato::getId()
{
    return _id;
}

//string Plato::getNombre()
//{
//    return _nombre;
//}

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

string Plato::getTipoStr()
{
    string resultado;
    switch (_tipo)
    {
        case PlatoTipo::Bebida:
            resultado = "Bebida";
            break;
        case PlatoTipo::Entrada:
            resultado = "Entrada";
            break;
        case PlatoTipo::Guarnicion:
            resultado = "Guarnicion";
            break;
        case PlatoTipo::Postre:
            resultado = "Postre";
            break;
        case PlatoTipo::Principal:
            resultado = "Principal";
            break;
        default:
            resultado = "";
            break;
    }
    return resultado;
}

bool Plato::getDisponible()
{
    return _disponible;
}
string Plato::getDisponibleStr()
{
    return _disponible ? "Si" : "No";
}

void Plato::setId(int i)
{
    _id = i;
}

void Plato::setNombre(char* n)
{
    strcpy(_nombre, n);
    //_nombre = n;
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
