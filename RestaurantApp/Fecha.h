#ifndef FECHA_H
#define FECHA_H

#include <string>
using namespace std;

class Fecha
{
	private:
        int _dia;
        int _mes;
        int _anio;

	public:
        Fecha(int dia, int mes, int anio);
        Fecha();

        int getDia();
        int getMes();
        int getAnio();
        
        void setDia(int dia);
        void setMes(int mes);
        void setAnio(int anio);

        char* getFechaCompleta();
};

#endif