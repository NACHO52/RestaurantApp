#ifndef VENTA_H
#define VENTA_H
#include "Fecha.h"
#include <string.h>
#include "Plato.h"
#include "Cliente.h"

enum class MedioEntrega {
	EnLocal = 1,
	Delivery = 2
};
enum class MedioPago {
	Efectivo = 1,
	Tarjeta = 2
};

class Venta
{
	private:
		int _id;
		int _clienteId;
		int _platoId;
		Fecha _fecha;
		MedioEntrega _entrega;
		MedioPago _pago;

	public:
		Venta();

		void setId(int i);
		void setClienteId(int cId);
		void setPlatoId(int pId);
		void setEntrega(MedioEntrega e);
		void setPago(MedioPago p);
		void setFecha(Fecha f);

		int getId();
		int getClienteId();
		int getPlatoId();
		MedioEntrega getEntrega();
		MedioPago getPago();
		Fecha getFecha();

		string getEntregaStr();
		string getPagoStr();
		char* getFechaStr();
		Plato getPlatoObj();
		Cliente getClienteObj();
};
#endif