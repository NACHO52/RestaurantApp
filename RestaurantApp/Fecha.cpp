#include "Fecha.h"
#include <ctime>

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