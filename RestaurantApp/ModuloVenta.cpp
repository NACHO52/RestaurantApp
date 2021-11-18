#include <iostream>
#include "rlutil.h"
#include "Venta.h"
#include "Logica.h"
#include "ModuloVenta.h"
#include "ModuloPlato.h"
#include "Plato.h"
#include "ModuloCliente.h"

using namespace std;


void DibujarMenuModuloVenta()
{

    rlutil::setBackgroundColor(rlutil::BLACK);
    rlutil::setColor(rlutil::LIGHTGREEN);

    for (int i = 0; i < 20; i++)
    {
        rlutil::locate(24 + i, 5);
        cout << (char)205;
        rlutil::locate(24 + i, 17);
        cout << (char)205;
    }

    for (int i = 0; i < 11; i++)
    {
        rlutil::locate(23, 6 + i);
        cout << (char)186;
        rlutil::locate(44, 6 + i);
        cout << (char)186;
    }
    rlutil::locate(23, 5);
    cout << (char)201;
    rlutil::locate(44, 5);
    cout << (char)187;
    rlutil::locate(23, 17);
    cout << (char)200;
    rlutil::locate(44, 17);
    cout << (char)188;

    rlutil::locate(25, 7);
    cout << "1 _ NUEVO";

    rlutil::locate(25, 9);
    cout << "2 _ BUSCAR";

    rlutil::locate(25, 15);
    cout << "0 _ VOLVER";


    rlutil::locate(25, 20);
    cout << "OPCION:";

    rlutil::setColor(rlutil::WHITE);
    rlutil::locate(34, 20);
}

void MenuModuloVenta()
{
    int opcion;
    bool volver = false;

    while (!volver)
    {
        DibujarMenuModuloVenta();

        cin >> opcion;

        switch (opcion)
        {
        case 1:
            system("cls");
            CrearVentaVista();
            system("cls");
            break;
        case 2:
            system("cls");
            MenuModuloVentaBuscar();
            system("cls");
            break;
        case 0:
            volver = true;
            break;
        default:
            system("cls");
            rlutil::setColor(rlutil::LIGHTRED);
            rlutil::locate(25, 22);
            cout << "OPCION INCORRECTA" << endl;
            break;
        }
    }
}

void DibujarMenuVentaReportes()
{
    rlutil::setBackgroundColor(rlutil::BLACK);
    rlutil::setColor(rlutil::LIGHTGREEN);

    for (int i = 0; i < 20; i++)
    {
        rlutil::locate(24 + i, 5);
        cout << (char)205;
        rlutil::locate(24 + i, 17);
        cout << (char)205;
    }

    for (int i = 0; i < 11; i++)
    {
        rlutil::locate(23, 6 + i);
        cout << (char)186;
        rlutil::locate(44, 6 + i);
        cout << (char)186;
    }
    rlutil::locate(23, 5);
    cout << (char)201;
    rlutil::locate(44, 5);
    cout << (char)187;
    rlutil::locate(23, 17);
    cout << (char)200;
    rlutil::locate(44, 17);
    cout << (char)188;

    rlutil::locate(25, 7);
    cout << "1 _ CLIENTE";

    rlutil::locate(25, 9);
    cout << "2 _ PLATO";

    rlutil::locate(25, 11);
    cout << "3 _ FECHA";

    rlutil::locate(25, 15);
    cout << "0 _ VOLVER";


    rlutil::locate(25, 20);
    cout << "OPCION:";

    rlutil::setColor(rlutil::WHITE);
    rlutil::locate(34, 20);
}

void DibujarMenuVentaBuscar()
{
    rlutil::setBackgroundColor(rlutil::BLACK);
    rlutil::setColor(rlutil::LIGHTGREEN);
    rlutil::locate(24, 2);
    cout << "SELECCIONE FILTRO";

    rlutil::locate(15, 5);
    cout << "1 _ TODOS";
    /*rlutil::locate(15, 7);
    cout << "2 _ ID";
    rlutil::locate(15, 9);
    cout << "3 _ TIPO";
    rlutil::locate(15, 11);
    cout << "4 _ ACTIVO";*/

    rlutil::locate(15, 16);
    cout << "0 _ VOLVER";


    rlutil::locate(15, 19);
    cout << "FILTRO:";

    rlutil::setColor(rlutil::WHITE);
    rlutil::locate(23, 19);

}

void MenuModuloVentaBuscar()
{
    rlutil::setBackgroundColor(rlutil::BLACK);
    rlutil::setColor(rlutil::LIGHTGREEN);
    int filtro;
    bool volver = false;
    while (!volver)
    {
        DibujarMenuVentaBuscar();

        cin >> filtro;

        switch (filtro)
        {
        case 1:
            system("cls");
            BuscarVentaTodos();
            system("pause");
            system("cls");
            break;
        case 2:
            system("cls");
            BuscarVentaPorId();
            system("cls");
            break;
        case 3:
            system("cls");
            //BuscarEmpleadoPorTipo();
            cout << "opcion 3";
            system("cls");
            break;
        case 4:
            system("cls");
            //BuscarEmpleadoPorActivo();
            cout << "opcion 4";
            system("cls");
            break;
        case 0:
            volver = true;
            break;
        default:
            system("cls");
            rlutil::setColor(rlutil::LIGHTRED);
            rlutil::locate(25, 22);
            cout << "OPCION INCORRECTA" << endl;
            break;
        }
    }
}

void BuscarVentaTodos()
{
    rlutil::setBackgroundColor(rlutil::BLACK);
    rlutil::setColor(rlutil::LIGHTGREEN);
    int cantidad;

    FILE* f = fopen("Venta.dat", "rb");
    if (f == NULL)
    {
        rlutil::locate(18, 10);
        cout << "NO EXISTEN REGISTROS DE DATOS" << endl << endl;
    }
    else
    {
        fseek(f, 0, SEEK_SET);
        Venta venta;
        rlutil::locate(2, 2);
        cout << "ID";
        rlutil::locate(6, 2);
        cout << "ENTREGA";
        rlutil::locate(15, 2);
        cout << "D.N.I.";
        rlutil::locate(26, 2);
        cout << "PAGO";
        rlutil::locate(36, 2);
        cout << "PLATO";
        rlutil::locate(56, 2);
        cout << "PRECIO";
        cout << endl << "_______________________________________________________________________________" << endl << endl;
        int i = 0;
        while (fread(&venta, sizeof(Venta), 1, f) == 1)
        {
            Cliente cliente = venta.getClienteObj();
            Plato plato = venta.getPlatoObj();
            rlutil::locate(2, 6 + i);
            cout << venta.getId();
            rlutil::locate(6, 6 + i);
            cout << venta.getEntregaStr();
            rlutil::locate(15, 6 + i);
            cout << cliente.getDni();
            rlutil::locate(26, 6 + i);
            cout << venta.getPagoStr();
            rlutil::locate(36, 6 + i);
            cout << plato.getNombre();
            rlutil::locate(56, 6 + i);
            cout << "$" << plato.getPrecio();
           /* rlutil::locate(66, 6 + i);
            cout << venta.getFechaStr() << " ";*/
            i++;
        }
        cout << endl << endl;
        fclose(f);
    }
}

void BuscarVentaPorActivo()
{
    rlutil::setBackgroundColor(rlutil::BLACK);
    rlutil::setColor(rlutil::LIGHTGREEN);
    bool disponible;
    rlutil::locate(10, 2);
    cout << "ACTIVO: ";
    rlutil::locate(23, 2);
    cin >> disponible;

    FILE* f = fopen("Venta.dat", "rb");
    if (f == NULL)
    {
        rlutil::locate(18, 10);
        cout << "NO EXISTEN REGISTROS DE DATOS" << endl << endl;
        system("pause");
    }
    else
    {
        fseek(f, 0, SEEK_SET);
        Venta venta;
        cout << endl << " ID  NOMBRE                 APELLIDO                DNI      TIPO        ACTIVO" << endl;
        cout << "_______________________________________________________________________________" << endl << endl;
        int i = 0;
        while (fread(&venta, sizeof(Venta), 1, f) == 1)
        {
            /*if (venta.getActivo() == disponible)
            {
                rlutil::locate(2, 6 + i);
                cout << empleado.getId();
                rlutil::locate(6, 6 + i);
                cout << empleado.getNombre();
                rlutil::locate(29, 6 + i);
                cout << empleado.getApellido();
                rlutil::locate(53, 6 + i);
                cout << empleado.getDni();
                rlutil::locate(62, 6 + i);
                cout << empleado.getTipoStr();
                rlutil::locate(74, 6 + i);
                cout << empleado.getActivoStr();
                i++;
            }*/
        }
        cout << endl << endl;
        MenuVentaEdicion();
        fclose(f);
    }
}

void BuscarVentaPorTipo()
{
    rlutil::setBackgroundColor(rlutil::BLACK);
    rlutil::setColor(rlutil::LIGHTGREEN);
    int tipo;
    rlutil::locate(10, 2);
    cout << "TIPO: ";
    rlutil::locate(17, 2);
    cin >> tipo;

    FILE* f = fopen("Venta.dat", "rb");
    if (f == NULL)
    {
        rlutil::locate(18, 10);
        cout << "NO EXISTEN REGISTROS DE DATOS" << endl << endl;
        system("pause");
    }
    else
    {
        fseek(f, 0, SEEK_SET);
        Venta venta;
        cout << endl << " ID  NOMBRE                 APELLIDO                DNI      TIPO        ACTIVO" << endl;
        cout << "_______________________________________________________________________________" << endl << endl;
        int i = 0;
        while (fread(&venta, sizeof(Venta), 1, f) == 1)
        {
            /*if (empleado.getTipo() == (EmpleadoTipo)tipo)
            {
                rlutil::locate(2, 6 + i);
                cout << empleado.getId();
                rlutil::locate(6, 6 + i);
                cout << empleado.getNombre();
                rlutil::locate(29, 6 + i);
                cout << empleado.getApellido();
                rlutil::locate(53, 6 + i);
                cout << empleado.getDni();
                rlutil::locate(62, 6 + i);
                cout << empleado.getTipoStr();
                rlutil::locate(74, 6 + i);
                cout << empleado.getActivoStr();
                i++;
            }*/
        }
        cout << endl << endl;
        fclose(f);
        MenuVentaEdicion();
    }
}

void BuscarVentaPorId()
{
    rlutil::setBackgroundColor(rlutil::BLACK);
    rlutil::setColor(rlutil::LIGHTGREEN);
    int id;
    int cantidad;
    rlutil::locate(10, 2);
    cout << "ID: ";
    rlutil::locate(18, 2);
    cin >> id;

    FILE* f = fopen("Venta.dat", "rb");
    if (f == NULL)
    {
        rlutil::locate(18, 10);
        cout << "NO EXISTEN REGISTROS DE DATOS" << endl << endl;
        system("pause");
    }
    else
    {
        fseek(f, 0, SEEK_SET);
        Venta venta;
        cout << endl << " ID  NOMBRE                 APELLIDO                DNI      TIPO        ACTIVO" << endl;
        cout << "_______________________________________________________________________________" << endl << endl;
        int i = 0;
        while (fread(&venta, sizeof(Venta), 1, f) == 1)
        {
            if (venta.getId() == id)
            {
                /*rlutil::locate(2, 6 + i);
                cout << empleado.getId();
                rlutil::locate(6, 6 + i);
                cout << empleado.getNombre();
                rlutil::locate(29, 6 + i);
                cout << empleado.getApellido();
                rlutil::locate(53, 6 + i);
                cout << empleado.getDni();
                rlutil::locate(62, 6 + i);
                cout << empleado.getTipoStr();
                rlutil::locate(74, 6 + i);
                cout << empleado.getActivoStr();*/
                break;
            }
        }
        cout << endl << endl;
        MenuVentaEdicion();
        fclose(f);
    }
}

void MenuVentaEdicion()
{
    rlutil::locate(8, 16);
    cout << "PARA EDITAR INGRESE EL ID DEL REGISTRO";

    rlutil::locate(8, 18);
    cout << "PARA VOLVER INGRESE UN CERO (0)";

    int opcion;


    rlutil::locate(8, 21);
    cout << "OPCION: ";
    rlutil::setColor(rlutil::WHITE);
    cin >> opcion;

    if (opcion != 0)
    {
        system("cls");
        rlutil::setColor(rlutil::LIGHTGREEN);
        Venta venta = GetVentaById(opcion);

        /*rlutil::locate(10, 2);
        cout << "NOMBRE: " << venta.getNombre();
        rlutil::locate(10, 5);
        cout << "APELLIDO: " << venta.getApellido();
        rlutil::locate(10, 8);
        cout << "D.N.I.: " << venta.getDni();
        rlutil::locate(45, 2);
        cout << "TIPO: " << venta.getTipoStr();
        rlutil::locate(45, 5);
        cout << "ACTIVO: " << venta.getActivoStr();*/

        rlutil::locate(8, 12);
        cout << "NUEVOS DATOS: ";

        rlutil::locate(10, 15);
        cout << "NOMBRE: ";
        rlutil::locate(10, 18);
        cout << "APELLIDO: ";
        rlutil::locate(10, 21);
        cout << "D.N.I.: ";
        rlutil::locate(45, 15);
        cout << "TIPO: ";
        rlutil::locate(45, 18);
        cout << "ACTIVO: ";

        char nombre[23];
        char apellido[23];
        char dni[10];
        int tipo;
        bool activo;

        rlutil::setColor(rlutil::WHITE);
        rlutil::locate(21, 15);
        cin >> nombre;
        rlutil::locate(21, 18);
        cin >> apellido;
        rlutil::locate(21, 21);
        cin >> dni;
        rlutil::locate(53, 15);
        cin >> tipo;
        rlutil::locate(53, 18);
        cin >> activo;

       /* empleado.setNombre(nombre);
        empleado.setApellido(apellido);
        empleado.setDni(dni);
        empleado.setTipo((EmpleadoTipo)tipo);
        empleado.setActivo(activo);*/

        rlutil::setColor(rlutil::LIGHTGREEN);
        rlutil::locate(26, 20);
        if (VentaGuardar(venta, false))
        {
            cout << "GUARDADO EXITOSO" << endl;

            system("pause");
        }
        else
        {
            cout << "Ups...  :(";
        }
        cout << endl;
    }
}

void CrearVentaVista()
{
    rlutil::setColor(rlutil::LIGHTGREEN);
    
    int dia, mes, anio, pago, entrega;

    rlutil::locate(24, 2);
    cout << "NUEVA VENTA";

    rlutil::locate(9, 5);
    cout << "DIA: ";
    rlutil::locate(9, 7);
    cout << "MES: ";
    rlutil::locate(9, 9);
    cout << "ANIO: ";
    rlutil::locate(9, 11);
    cout << "MEDIO DE PAGO: ";
    rlutil::locate(9, 13);
    cout << "ENTREGA: ";

    rlutil::setColor(rlutil::WHITE);

    rlutil::locate(24, 5);
    cin >> dia;
    rlutil::locate(24, 7);
    cin >> mes;
    rlutil::locate(24, 9);
    cin >> anio;
    rlutil::locate(24, 11);
    cin >> pago;
    rlutil::locate(24, 13);
    cin >> entrega;

    rlutil::setColor(rlutil::LIGHTGREEN);
    int platoId = CreacionVentaSeleccionarPlato();
    if (platoId == -1) return;
    Plato plato = GetPlatoById(platoId);
    int nuevoId = VentaGetUltimoId();
    char dni[10] = "";

    rlutil::locate(24, 2);
    cout << "NUEVA VENTA";

    rlutil::locate(9, 5);
    cout << "FECHA: " << dia << "/" << mes << "/" << anio;
    rlutil::locate(9, 7);
    cout << "MEDIO DE PAGO: " << pago;
    rlutil::locate(9, 9);
    cout << "ENTREGA: " << entrega;
    rlutil::locate(9, 11);
    cout << "PLATO: " << plato.getNombre();
    rlutil::locate(9, 13);
    cout << "D.N.I. DE CLIENTE: ";
    rlutil::setColor(rlutil::WHITE);
    rlutil::locate(29, 13);
    cin >> dni;
    int clienteId = ExisteCliente(dni);
    if (clienteId == -1)
    {
        clienteId = CrearClienteVista(dni);
        if (clienteId == -1) return;
    }

    Venta obj;
    obj.setId(nuevoId + 1);
    obj.setClienteId(clienteId);
    obj.setEntrega((MedioEntrega)entrega);
    obj.setFecha(Fecha(dia,mes,anio));
    obj.setPago((MedioPago)pago);
    obj.setPlatoId(platoId);

    rlutil::locate(25, 20);
    if (VentaGuardar(obj, true))
    {
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
    rlutil::setColor(rlutil::LIGHTGREEN);
}

int CreacionVentaSeleccionarPlato()
{
    int platoId = -1;
    system("cls");
    FILE* f = fopen("Plato.dat", "rb");
    if (f == NULL)
    {
        rlutil::locate(6, 6);
        cout << "NO HAY REGISTROS.";
        return platoId;
    }
    Plato obj;
    int i = 0;
    bool hayDisponibles = false;
    while (fread(&obj, sizeof(Plato), 1, f))
    {
        if (obj.getDisponible())
        {
            rlutil::locate(2, 3 + i);
            cout << obj.getId();
            rlutil::locate(6, 3 + i);
            cout << obj.getNombre();
            rlutil::locate(29, 3 + i);
            cout << obj.getPrecio();
            rlutil::locate(43, 3 + i);
            cout << obj.getTipoStr();
            i++;
            hayDisponibles = true;
        }
    }
    fclose(f);
    rlutil::locate(6, 8 + i);
    if (hayDisponibles)
    {
        cout << "INGRESE EL ID DEL REGISTRO PARA SELECCIONARLO: ";
        rlutil::locate(53, 8 + i);

        rlutil::setColor(rlutil::WHITE);
        cin >> platoId;

        rlutil::setColor(rlutil::LIGHTGREEN);
        system("cls");
    }
    else
    {
        cout << "NO SE ENCUENTRAN PLATOS DISPONIBLES.";
        system("pause");

        system("cls");
    }
    return platoId;
}

int VentaGetUltimoId()
{
    int id = 0;
    FILE* f = fopen("Venta.dat", "rb+");
    if (f == NULL)
    {
        return 0;
    }
    fseek(f, (sizeof(Venta) * (GetVentasCantidad() - 1)), SEEK_SET);
    Venta obj;
    if (fread(&obj, sizeof(obj), 1, f))
    {
        id = obj.getId();
    }
    fclose(f);
    return id;
}

bool VentaGuardar(Venta obj, bool nuevo)
{
    if (nuevo)
    {
        FILE* f = fopen("Venta.dat", "ab");
        if (f == NULL)
        {
            return false;
        }
        fseek(f, 0, SEEK_END);
        fwrite(&obj, sizeof(Venta), 1, f);
        fclose(f);
        return true;
    }
    else
    {
        FILE* f = fopen("Venta.dat", "rb+");
        if (f == NULL)
        {
            return false;
        }
        int pos = obj.getId() - 1;
        fseek(f, sizeof(Venta) * pos, SEEK_SET);
        fwrite(&obj, sizeof(Venta), 1, f);
        fclose(f);
        return true;
    }
}

int GetVentasCantidad()
{
    int bytes;
    FILE* f = fopen("Venta.dat", "rb");
    if (f == NULL)
    {
        return -1;
    }
    fseek(f, 0, SEEK_END);
    bytes = ftell(f);
    fclose(f);
    return bytes / sizeof(Venta);
}

Venta GetVentaById(int id)
{
    Venta obj;
    FILE* f = fopen("Venta.dat", "rb+");
    if (f != NULL)
    {
        fseek(f, (sizeof(Venta) * (id - 1)), SEEK_SET);
        fread(&obj, sizeof(obj), 1, f);
        fclose(f);
    }

    return obj;
}

