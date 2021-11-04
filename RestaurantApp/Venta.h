#ifndef VENTA_H
#define VENTA_H

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
		//TODO: poner fecha
		MedioEntrega _entrega;
		MedioPago _pago;

	public:
		Venta();

		void setId(int i);
		void setClienteId(int cId);
		void setPlatoId(int pId);
		void setEntrega(MedioEntrega e);
		void setPago(MedioPago p);

		int getId();
		int getClienteId();
		int getPlatoId();
		MedioEntrega getEntrega();
		MedioPago getPago();
};
#endif