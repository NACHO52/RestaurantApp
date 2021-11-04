#include "Cliente.h"
#include <string>

Cliente::Cliente()
{
    _id = 0;
    strcpy(_apellido, "");
    strcpy(_nombre, "");
    strcpy(_dni, "");
    _compras = 0;
}

int Cliente::getCompras()
{
    return _compras;
}

void Cliente::setCompras(int c)
{
    _compras = c;
}
