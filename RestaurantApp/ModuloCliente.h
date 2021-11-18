#include "Cliente.h"

int ExisteCliente(char* dni);
int CrearClienteVista(char* dni);
int ClienteGetUltimoId();
bool ClienteGuardar(Cliente obj, bool nuevo);
int GetClientesCantidad();
Cliente GetClienteById(int id);