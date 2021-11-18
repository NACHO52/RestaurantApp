#include <iostream>
#include "rlutil.h"
#include "ModuloCliente.h"

using namespace std;

int ExisteCliente(char * dni)
{
    int clienteId = -1;
	FILE* f = fopen("Cliente.dat", "rb");
	if (f == NULL) return clienteId;
	Cliente obj;
	fseek(f, 0, SEEK_SET);
	while (fread(&obj, sizeof(Cliente), 1, f))
	{
		if (strcmp(obj.getDni(), dni) == 0)
		{
            clienteId = obj.getId();
            break;
		}
	}
    fclose(f);
	return clienteId;
}

int CrearClienteVista(char * dni)
{
    rlutil::setColor(rlutil::LIGHTGREEN);
    char apellido[30];
    char nombre[30];
    int compras;
    int clienteId = -1;

    system("cls");
    rlutil::locate(24, 2);
    cout << "CREAR CLIENTE";

    rlutil::locate(9, 5);
    cout << "NOMBRE: ";
    rlutil::locate(9, 7);
    cout << "APELLIDO: ";

    rlutil::setColor(rlutil::WHITE);

    rlutil::locate(24, 5);
    cin >> nombre;
    rlutil::locate(24, 7);
    cin >> apellido;

    int nuevoId = ClienteGetUltimoId();

    Cliente obj;
    obj.setApellido(apellido);
    obj.setNombre(nombre);
    obj.setDni(dni);
    obj.setCompras(0);
    obj.setId(nuevoId + 1);

    rlutil::locate(25, 20);
    if (ClienteGuardar(obj, true))
    {
        clienteId = obj.getId();
        rlutil::setColor(rlutil::LIGHTGREEN);
        cout << "EL REGISTRO SE GUARDO CORRECTAMENTE.";
    }
    else
    {
        rlutil::setColor(rlutil::LIGHTRED);
        cout << "HA OCURRIDO UN ERROR AL GUARDAR LOS DATOS.";
    }
    rlutil::locate(25, 22);
    system("pause");
    system("cls");
    return clienteId;
}

bool ClienteGuardar(Cliente obj, bool nuevo)
{
    if (nuevo)
    {
        FILE* f = fopen("Cliente.dat", "ab");
        if (f == NULL)
        {
            return false;
        }
        fseek(f, 0, SEEK_END);
        fwrite(&obj, sizeof(Cliente), 1, f);
        fclose(f);
        return true;
    }
    else
    {
        FILE* f = fopen("Cliente.dat", "rb+");
        if (f == NULL)
        {
            return false;
        }
        int pos = obj.getId() - 1;
        fseek(f, sizeof(Cliente) * pos, SEEK_SET);
        fwrite(&obj, sizeof(Cliente), 1, f);
        fclose(f);
        return true;
    }
}

int ClienteGetUltimoId()
{
    int id = 0;
    FILE* f = fopen("Empleado.dat", "rb+");
    if (f == NULL)
    {
        return 0;
    }
    fseek(f, (sizeof(Cliente) * (GetClientesCantidad() - 1)), SEEK_SET);
    Cliente obj;
    if (fread(&obj, sizeof(obj), 1, f))
    {
        id = obj.getId();
    }
    fclose(f);
    return id;
}

int GetClientesCantidad()
{
    int bytes;
    FILE* f = fopen("Cliente.dat", "rb");
    if (f == NULL)
    {
        return -1;
    }
    fseek(f, 0, SEEK_END);
    bytes = ftell(f);
    fclose(f);
    return bytes / sizeof(Cliente);
}


Cliente GetClienteById(int id)
{
    Cliente obj;
    FILE* f = fopen("Cliente.dat", "rb+");
    if (f != NULL)
    {
        fseek(f, (sizeof(Cliente) * (id - 1)), SEEK_SET);
        fread(&obj, sizeof(obj), 1, f);
        fclose(f);
    }

    return obj;
}