#include "Venta.h"
#include <string>
#include "Plato.h"
#include "ModuloPlato.h"
#include "Cliente.h"
#include "ModuloCliente.h"
using namespace std;

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

string Venta::getEntregaStr()
{
	string ret = "";
	switch (_entrega)
	{
	case MedioEntrega::EnLocal:
		ret = "En local";
		break;
	case MedioEntrega::Delivery:
		ret = "Delivery";
		break;
	}
	return ret;
}

string Venta::getPagoStr()
{
	string ret = "";
	switch (_pago)
	{
	case MedioPago::Efectivo:
		ret = "Efectivo";
		break;
	case MedioPago::Tarjeta:
		ret = "Tarjeta";
		break;
	}
	return ret;
}

char* Venta::getFechaStr()
{
	return _fecha.getFechaCompleta();
}

Plato Venta::getPlatoObj()
{
	return GetPlatoById(_platoId);
}


Cliente Venta::getClienteObj()
{
	return GetClienteById(Venta::_clienteId);
}