#include "Fecha.h"
#include <ctime>
#include <string>
using namespace std;

Fecha::Fecha(int dia, int mes, int anio)
{
    _dia = dia;
    _mes = mes;
    _anio = anio;
}
Fecha::Fecha() {
    time_t t;
    struct tm* f;
    time(&t);
    f = localtime(&t);
    _dia = f->tm_mday;
    _mes = f->tm_mon + 1;
    _anio = f->tm_year + 1900;
}
int  Fecha::getDia() {
    return _dia;
}
int  Fecha::getMes() {
    return _mes;
}
int  Fecha::getAnio() {
    return _anio;
}
void Fecha::setDia(int dia) {
    _dia = dia;
}
void Fecha::setMes(int mes) {
    _mes = mes;
}
void Fecha::setAnio(int anio) {
    _anio = anio;
}

char* Fecha::getFechaCompleta()
{
    char fecha[10] = {};
    if (_dia < 10)
    {
        fecha[0] = '0';
        fecha[1] = _dia + 48;
    }
    else
    {
        fecha[0] = (_dia / 10) + 48;
        fecha[1] = _dia > 20 ? (_dia - 20 ) + 48 : (_dia - 10) + 48;
    }
    fecha[2] = '/';
    if (_mes < 10)
    {
        fecha[3] = '0';
        fecha[4] = _mes + 48;
    }
    else
    {
        fecha[3] = (_mes / 10) + 48;
        fecha[4] = (_mes - 10) + 48;
    }
    fecha[5] = '/';
    int unoAnio = _anio % 10;
    int diezAnio = _anio / 10 % 10;
    int cienAnio = _anio / 100 % 10;
    int milAnio = _anio / 1000 % 10;

    fecha[6] = milAnio + 48;
    
    fecha[7] = cienAnio + 48;
    fecha[8] = diezAnio + 48;
    fecha[9] = unoAnio + 48;
    return fecha;
}
