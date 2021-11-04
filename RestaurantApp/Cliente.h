#ifndef CLIENTE_H
#define CLIENTE_H

#include "Persona.h"

class Cliente : public Persona
{
	private:
		int _compras;

	public:
		Cliente();

		int getCompras();
		void setCompras(int c);
};

#endif
