#include <iostream>
#include "rlutil.h"
#include "Empleado.h"
#include "Logica.h"
#include "ModuloEmpleado.h"

using namespace std;

void MenuModuloEmpleado()
{
    int opcion;
    bool volver = false;

    while (!volver)
    {
        DibujarMenuModuloEmpleado();

        cin >> opcion;

        switch (opcion)
        {
        case 1:
            system("cls");
            CrearEmpleadoVista();
            cout << "Opción 1" << endl;
            system("cls");
            break;
        case 2:
            system("cls");
            MenuModuloEmpleadoBuscar();
            system("cls");
            break;
            /*case 3:
                system("cls");
                cout << "opcion 3" << endl;
                system("cls");
                break;*/
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

void DibujarMenuModuloEmpleado()
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
    cout << "1 _ CREAR";

    rlutil::locate(25, 9);
    cout << "2 _ BUSCAR";

    rlutil::locate(25, 15);
    cout << "0 _ VOLVER";


    rlutil::locate(25, 20);
    cout << "OPCION:";

    rlutil::setColor(rlutil::WHITE);
    rlutil::locate(34, 20);
}

void DibujarMenuEmpleadoReportes()
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
    cout << "1 _ ENTRADAS";

    rlutil::locate(25, 9);
    cout << "2 _ PRINCIPALES";

    rlutil::locate(25, 11);
    cout << "3 _ GUARNICIONES";

    rlutil::locate(25, 15);
    cout << "0 _ VOLVER";


    rlutil::locate(25, 20);
    cout << "OPCION:";

    rlutil::setColor(rlutil::WHITE);
    rlutil::locate(34, 20);
}

void DibujarMenuEmpleadoBuscar()
{
    rlutil::setBackgroundColor(rlutil::BLACK);
    rlutil::setColor(rlutil::LIGHTGREEN);
    rlutil::locate(24, 2);
    cout << "SELECCIONE FILTRO";

    rlutil::locate(15, 5);
    cout << "1 _ TODOS";
    rlutil::locate(15, 7);
    cout << "2 _ ID";
    rlutil::locate(15, 9);
    cout << "3 _ TIPO";
    rlutil::locate(15, 11);
    cout << "4 _ ACTIVO";

    rlutil::locate(15, 16);
    cout << "0 _ VOLVER";


    rlutil::locate(15, 19);
    cout << "FILTRO:";

    rlutil::setColor(rlutil::WHITE);
    rlutil::locate(23, 19);

}

void MenuModuloEmpleadoBuscar()
{
    rlutil::setBackgroundColor(rlutil::BLACK);
    rlutil::setColor(rlutil::LIGHTGREEN);
    int filtro;
    bool volver = false;
    while (!volver)
    {
        DibujarMenuEmpleadoBuscar();

        cin >> filtro;

        switch (filtro)
        {
        case 1:
            system("cls");
            BuscarEmpleadoTodos();
            system("pause");
            system("cls");
            break;
        case 2:
            system("cls");
            BuscarEmpleadoPorId();
            system("cls");
            break;
        case 3:
            system("cls");
            BuscarEmpleadoPorTipo();
            system("cls");
            break;
        case 4:
            system("cls");
            BuscarEmpleadoPorActivo();
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

void BuscarEmpleadoTodos()
{
    rlutil::setBackgroundColor(rlutil::BLACK);
    rlutil::setColor(rlutil::LIGHTGREEN);
    int cantidad;

    FILE* f = fopen("Empleado.dat", "rb");
    if (f == NULL)
    {
        rlutil::locate(18, 10);
        cout << "NO EXISTEN REGISTROS DE DATOS" << endl << endl;
    }
    else
    {
        fseek(f, 0, SEEK_SET);
        Empleado empleado;
        cout << endl << " ID  NOMBRE                 APELLIDO                DNI      TIPO        ACTIVO" << endl;
        cout << "_______________________________________________________________________________" << endl << endl;
        int i = 0;
        while (fread(&empleado, sizeof(Empleado), 1, f) == 1)
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
        }
        cout << endl << endl;
        fclose(f);
    }
}

void BuscarEmpleadoPorActivo()
{
    rlutil::setBackgroundColor(rlutil::BLACK);
    rlutil::setColor(rlutil::LIGHTGREEN);
    bool disponible;
    rlutil::locate(10, 2);
    cout << "ACTIVO: ";
    rlutil::locate(23, 2);
    cin >> disponible;

    FILE* f = fopen("Empleado.dat", "rb");
    if (f == NULL)
    {
        rlutil::locate(18, 10);
        cout << "NO EXISTEN REGISTROS DE DATOS" << endl << endl;
        system("pause");
    }
    else
    {
        fseek(f, 0, SEEK_SET);
        Empleado empleado;
        cout << endl << " ID  NOMBRE                 APELLIDO                DNI      TIPO        ACTIVO" << endl;
        cout << "_______________________________________________________________________________" << endl << endl;
        int i = 0;
        while (fread(&empleado, sizeof(Empleado), 1, f) == 1)
        {
            if (empleado.getActivo() == disponible)
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
            }
        }
        cout << endl << endl;
        MenuEmpleadoEdicion();
        fclose(f);
    }
}

void BuscarEmpleadoPorTipo()
{
    rlutil::setBackgroundColor(rlutil::BLACK);
    rlutil::setColor(rlutil::LIGHTGREEN);
    int tipo;
    rlutil::locate(10, 2);
    cout << "TIPO: ";
    rlutil::locate(17, 2);
    cin >> tipo;

    FILE* f = fopen("Empleado.dat", "rb");
    if (f == NULL)
    {
        rlutil::locate(18, 10);
        cout << "NO EXISTEN REGISTROS DE DATOS" << endl << endl;
        system("pause");
    }
    else
    {
        fseek(f, 0, SEEK_SET);
        Empleado empleado;
        cout << endl << " ID  NOMBRE                 APELLIDO                DNI      TIPO        ACTIVO" << endl;
        cout << "_______________________________________________________________________________" << endl << endl;
        int i = 0;
        while (fread(&empleado, sizeof(Empleado), 1, f) == 1)
        {
            if (empleado.getTipo() == (EmpleadoTipo)tipo)
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
            }
        }
        cout << endl << endl;
        fclose(f);
        MenuEmpleadoEdicion();
    }
}

void BuscarEmpleadoPorId()
{
    rlutil::setBackgroundColor(rlutil::BLACK);
    rlutil::setColor(rlutil::LIGHTGREEN);
    int id;
    int cantidad;
    rlutil::locate(10, 2);
    cout << "ID: ";
    rlutil::locate(18, 2);
    cin >> id;

    FILE* f = fopen("Empleado.dat", "rb");
    if (f == NULL)
    {
        rlutil::locate(18, 10);
        cout << "NO EXISTEN REGISTROS DE DATOS" << endl << endl;
        system("pause");
    }
    else
    {
        fseek(f, 0, SEEK_SET);
        Empleado empleado;
        cout << endl << " ID  NOMBRE                 APELLIDO                DNI      TIPO        ACTIVO" << endl;
        cout << "_______________________________________________________________________________" << endl << endl;
        int i = 0;
        while (fread(&empleado, sizeof(Empleado), 1, f) == 1)
        {
            if (empleado.getId() == id)
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
                break;
            }
        }
        cout << endl << endl;
        MenuEmpleadoEdicion();
        fclose(f);
    }
}

void MenuEmpleadoEdicion()
{
    rlutil::locate(8,16);
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
        Empleado empleado = GetEmpleadoById(opcion);

        rlutil::locate(10, 2);
        cout << "NOMBRE: " << empleado.getNombre();
        rlutil::locate(10, 5);
        cout << "APELLIDO: " << empleado.getApellido();
        rlutil::locate(10, 8);
        cout << "D.N.I.: " << empleado.getDni();
        rlutil::locate(45, 2);
        cout << "TIPO: " << empleado.getTipoStr();
        rlutil::locate(45, 5);
        cout << "ACTIVO: " << empleado.getActivoStr();

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

        empleado.setNombre(nombre);
        empleado.setApellido(apellido);
        empleado.setDni(dni);
        empleado.setTipo((EmpleadoTipo)tipo);
        empleado.setActivo(activo);

        rlutil::setColor(rlutil::LIGHTGREEN);
        rlutil::locate(26, 20);
        if (EmpleadoGuardar(empleado, false))
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

void CrearEmpleadoVista()
{
    rlutil::setColor(rlutil::LIGHTGREEN);
    char apellido[30];
    char nombre[30];
    char dni[20];
    int tipo;

    rlutil::locate(24, 2);
    cout << "CREAR EMPLEADO";

    rlutil::locate(9, 5);
    cout << "NOMBRE: ";
    rlutil::locate(9, 7);
    cout << "APELLIDO: ";
    rlutil::locate(9, 9);
    cout << "D.N.I.: ";
    rlutil::locate(9, 11);
    cout << "TIPO: ";

    rlutil::setColor(rlutil::WHITE);

    rlutil::locate(24, 5);
    cin >> nombre;
    rlutil::locate(24, 7);
    cin >> apellido;
    rlutil::locate(24, 9);
    cin >> dni;
    rlutil::locate(24, 11);
    cin >> tipo;

    int nuevoId = EmpleadoGetUltimoId();

    Empleado obj;
    obj.setApellido(apellido);
    obj.setNombre(nombre);
    obj.setDni(dni);
    obj.setTipo((EmpleadoTipo)tipo);
    obj.setId(nuevoId + 1);

    rlutil::locate(25, 20);
    if (EmpleadoGuardar(obj, true))
    {
        rlutil::setColor(rlutil::LIGHTGREEN);
        cout << "EL REGISTRO SE GUARDO CORRECTAMENTE.";
        rlutil::locate(25, 22);
        system("pause");
    }
    else
    {
        cout << "HA OCURRIDO UN ERROR AL GUARDAR LOS DATOS.";
        rlutil::locate(25, 22);
        system("pause");
    }
}

int EmpleadoGetUltimoId()
{
    int id = 0;
    FILE* f = fopen("Empleado.dat", "rb+");
    if (f == NULL)
    {
        return 0;
    }
    fseek(f, (sizeof(Empleado) * (GetEmpleadosCantidad() - 1)), SEEK_SET);
    Empleado obj;
    if (fread(&obj, sizeof(obj), 1, f))
    {
        id = obj.getId();
    }
    fclose(f);
    return id;
}

bool EmpleadoGuardar(Empleado obj, bool nuevo)
{
    if (nuevo)
    {
        FILE* f = fopen("Empleado.dat", "ab");
        if (f == NULL)
        {
            return false;
        }
        fseek(f, 0, SEEK_END);
        fwrite(&obj, sizeof(Empleado), 1, f);
        fclose(f);
        return true;
    }
    else
    {
        FILE* f = fopen("Empleado.dat", "rb+");
        if (f == NULL)
        {
            return false;
        }
        int pos = obj.getId() - 1;
        fseek(f, sizeof(Empleado) * pos, SEEK_SET);
        fwrite(&obj, sizeof(Empleado), 1, f);
        fclose(f);
        return true;
    }
}

int GetEmpleadosCantidad()
{
    int bytes;
    FILE* f = fopen("Empleado.dat", "rb");
    if (f == NULL)
    {
        return -1;
    }
    fseek(f, 0, SEEK_END);
    bytes = ftell(f);
    fclose(f);
    return bytes / sizeof(Empleado);
}

Empleado GetEmpleadoById(int id)
{
    Empleado obj;
    FILE* f = fopen("Empleado.dat", "rb+");
    if (f != NULL)
    {
        fseek(f, (sizeof(Empleado) * (id - 1)), SEEK_SET);
        fread(&obj, sizeof(obj), 1, f);
        fclose(f);
    }

    return obj;
}

