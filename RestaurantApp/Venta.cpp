#include "Venta.h"
#include <string>

Venta::Venta()
{
	_id = 0;
	_clienteId = 0;
	_platoId = 0;
	_entrega = MedioEntrega::EnLocal;
	_pago = MedioPago::Efectivo;
}

void Venta::setId(int i)
{
	_id = i;
}

void Venta::setClienteId(int cId)
{
	_clienteId = cId;
}

void Venta::setPlatoId(int pId)
{
	_platoId = pId;
}

void Venta::setEntrega(MedioEntrega e)
{
	_entrega = e;
}

void Venta::setPago(MedioPago p)
{
	_pago = p;
}

void Venta::setFecha(Fecha f)
{
	_fecha = f;
}

int Venta::getId()
{
	return _id;
}

int Venta::getClienteId()
{
	return _clienteId;
}

int Venta::getPlatoId()
{
	return _platoId;
}

MedioEntrega Venta::getEntrega()
{
	return _entrega;
}

MedioPago Venta::getPago()
{
	return _pago;
}

Fecha Venta::getFecha()
{
	return _fecha;
}
