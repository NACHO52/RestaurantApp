#include <iostream>
#include "rlutil.h"
#include "Plato.h"
#include "Logica.h"
#include "ModuloPlato.h"

using namespace std;

void DibujarMenuModuloPlato()
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

void DibujarMenuPlatoReportes()
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

void DibujarMenuPlatoBuscar()
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
    cout << "3 _ NOMBRE";
    rlutil::locate(15, 11);
    cout << "4 _ DISPONIBLE";
    rlutil::locate(15, 13);
    cout << "5 _ TIPO";

    rlutil::locate(15, 16);
    cout << "0 _ VOLVER";


    rlutil::locate(15, 19);
    cout << "FILTRO:";

    rlutil::setColor(rlutil::WHITE);
    rlutil::locate(23, 19);

}

void MenuModuloPlatoBuscar()
{
    rlutil::setBackgroundColor(rlutil::BLACK);
    rlutil::setColor(rlutil::LIGHTGREEN);
    int filtro;
    bool volver = false;
    while (!volver)
    {
        DibujarMenuPlatoBuscar();

        cin >> filtro;

        switch (filtro)
        {
        case 1:
            system("cls");
            BuscarPlatoTodos();
            system("pause");
            system("cls");
            break;
        case 2:
            system("cls");
            BuscarPlatoPorId();
            system("cls");
            break;
        case 3:
            system("cls");
            BuscarPlatoPorNombre();
            system("cls");
            break;
        case 4:
            system("cls");
            BuscarPlatoPorDisponible();
            system("cls");
            break;
        case 5:
            system("cls");
            BuscarPlatoPorTipo();
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

void BuscarPlatoTodos()
{
    rlutil::setBackgroundColor(rlutil::BLACK);
    rlutil::setColor(rlutil::LIGHTGREEN);
    int cantidad;

    FILE* f = fopen("Plato.dat", "rb");
    if (f == NULL)
    {
        rlutil::locate(18, 10);
        cout << "NO EXISTEN REGISTROS DE DATOS" << endl << endl;
    }
    else
    {
        fseek(f, 0, SEEK_SET);
        Plato plato;
        cout << endl << " ID  NOMBRE                 PRECIO        TIPO          DISPONIBLE " << endl;
        cout << "____________________________________________________________________" << endl << endl;
        int i = 0;
        while (fread(&plato, sizeof(Plato), 1, f) == 1)
        {
            rlutil::locate(2, 6 + i);
            cout << plato.getId();
            rlutil::locate(6, 6 + i);
            cout << plato.getNombre();
            rlutil::locate(29, 6 + i);
            cout << plato.getPrecio();
            rlutil::locate(43, 6 + i);
            cout << plato.getTipoStr();
            rlutil::locate(57, 6 + i);
            cout << plato.getDisponibleStr();
            i++;
        }
        cout << endl << endl;
        fclose(f);
    }
}

void BuscarPlatoPorNombre()
{
    rlutil::setBackgroundColor(rlutil::BLACK);
    rlutil::setColor(rlutil::LIGHTGREEN);
    char nombre[20] = {};
    int cantidad;
    rlutil::locate(10, 2);
    cout << "NOMBRE: ";
    rlutil::locate(18, 2);
    cin >> nombre;

    FILE* f = fopen("Plato.dat", "rb");
    if (f == NULL)
    {
        rlutil::locate(18, 10);
        cout << "NO EXISTEN REGISTROS DE DATOS" << endl << endl;
        system("pause");
    }
    else
    {
        fseek(f, 0, SEEK_SET);
        Plato plato;
        cout << endl << " ID  NOMBRE                 PRECIO        TIPO          DISPONIBLE " << endl;
        cout << "____________________________________________________________________" << endl << endl;
        int i = 0;
        while (fread(&plato, sizeof(Plato), 1, f) == 1)
        {
            if (strcmp(plato.getNombre(), nombre) == 0)
            {
                rlutil::locate(2, 6 + i);
                cout << plato.getId();
                rlutil::locate(6, 6 + i);
                cout << plato.getNombre();
                rlutil::locate(29, 6 + i);
                cout << plato.getPrecio();
                rlutil::locate(43, 6 + i);
                cout << plato.getTipoStr();
                rlutil::locate(57, 6 + i);
                cout << plato.getDisponibleStr();
                i++;
                break;
            }
        }
        cout << endl << endl;
        MenuPlatoEdicion();
        fclose(f);
    }
}

void BuscarPlatoPorDisponible()
{
    rlutil::setBackgroundColor(rlutil::BLACK);
    rlutil::setColor(rlutil::LIGHTGREEN);
    bool disponible;
    rlutil::locate(10, 2);
    cout << "DISPONIBLE: ";
    rlutil::locate(23, 2);
    cin >> disponible;

    FILE* f = fopen("Plato.dat", "rb");
    if (f == NULL)
    {
        rlutil::locate(18, 10);
        cout << "NO EXISTEN REGISTROS DE DATOS" << endl << endl;
        system("pause");
    }
    else
    {
        fseek(f, 0, SEEK_SET);
        Plato plato;
        cout << endl << " ID  NOMBRE                 PRECIO        TIPO          DISPONIBLE " << endl;
        cout << "____________________________________________________________________" << endl << endl;
        int i = 0;
        while (fread(&plato, sizeof(Plato), 1, f) == 1)
        {
            if (plato.getDisponible() == disponible)
            {
                rlutil::locate(2, 6 + i);
                cout << plato.getId();
                rlutil::locate(6, 6 + i);
                cout << plato.getNombre();
                rlutil::locate(29, 6 + i);
                cout << plato.getPrecio();
                rlutil::locate(43, 6 + i);
                cout << plato.getTipoStr();
                rlutil::locate(57, 6 + i);
                cout << plato.getDisponibleStr();
                i++;
            }
        }
        cout << endl << endl;
        MenuPlatoEdicion();
        fclose(f);
    }
}

void BuscarPlatoPorTipo()
{
    rlutil::setBackgroundColor(rlutil::BLACK);
    rlutil::setColor(rlutil::LIGHTGREEN);
    int tipo;
    rlutil::locate(10, 2);
    cout << "TIPO: ";
    rlutil::locate(17, 2);
    cin >> tipo;

    FILE* f = fopen("Plato.dat", "rb");
    if (f == NULL)
    {
        rlutil::locate(18, 10);
        cout << "NO EXISTEN REGISTROS DE DATOS" << endl << endl;
        system("pause");
    }
    else
    {
        fseek(f, 0, SEEK_SET);
        Plato plato;
        cout << endl << " ID  NOMBRE                 PRECIO        TIPO          DISPONIBLE " << endl;
        cout << "____________________________________________________________________" << endl << endl;
        int i = 0;
        while (fread(&plato, sizeof(Plato), 1, f) == 1)
        {
            if (plato.getTipo() == (PlatoTipo)tipo)
            {
                rlutil::locate(2, 6 + i);
                cout << plato.getId();
                rlutil::locate(6, 6 + i);
                cout << plato.getNombre();
                rlutil::locate(29, 6 + i);
                cout << plato.getPrecio();
                rlutil::locate(43, 6 + i);
                cout << plato.getTipoStr();
                rlutil::locate(57, 6 + i);
                cout << plato.getDisponibleStr();
                i++;
            }
        }
        cout << endl << endl;
        MenuPlatoEdicion();
        fclose(f);
    }
}

void BuscarPlatoPorId()
{
    rlutil::setBackgroundColor(rlutil::BLACK);
    rlutil::setColor(rlutil::LIGHTGREEN);
    int id;
    int cantidad;
    rlutil::locate(10, 2);
    cout << "ID: ";
    rlutil::locate(18, 2);
    cin >> id;

    FILE* f = fopen("Plato.dat", "rb");
    if (f == NULL)
    {
        rlutil::locate(18, 10);
        cout << "NO EXISTEN REGISTROS DE DATOS" << endl << endl;
        system("pause");
    }
    else
    {
        fseek(f, 0, SEEK_SET);
        Plato plato;
        cout << endl << " ID  NOMBRE                 PRECIO        TIPO          DISPONIBLE " << endl;
        cout << "____________________________________________________________________" << endl << endl;
        int i = 0;
        while (fread(&plato, sizeof(Plato), 1, f) == 1)
        {
            if (plato.getId() == id)
            {
                rlutil::locate(2, 6 + i);
                cout << plato.getId();
                rlutil::locate(6, 6 + i);
                cout << plato.getNombre();
                rlutil::locate(29, 6 + i);
                cout << plato.getPrecio();
                rlutil::locate(43, 6 + i);
                cout << plato.getTipoStr();
                rlutil::locate(57, 6 + i);
                cout << plato.getDisponibleStr();
                break;
            }
        }
        cout << endl << endl;
        MenuPlatoEdicion();
        fclose(f);
    }
}

void MenuPlatoEdicion()
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
        Plato plato = GetPlatoById(opcion);

        rlutil::locate(10, 2);
        cout << "NOMBRE: " << plato.getNombre();
        rlutil::locate(10, 5);
        cout << "PRECIO: " << plato.getPrecio();
        rlutil::locate(35, 2);
        cout << "TIPO: " << plato.getTipoStr();
        rlutil::locate(35, 5);
        cout << "DISPONIBLE: " << plato.getDisponibleStr();

        rlutil::locate(8, 12);
        cout << "NUEVOS DATOS: ";

        rlutil::locate(10, 15);
        cout << "NOMBRE: ";
        rlutil::locate(10, 18);
        cout << "PRECIO: ";
        rlutil::locate(40, 15);
        cout << "TIPO: ";
        rlutil::locate(40, 18);
        cout << "DISPONIBLE: ";

        char nombre[20];
        float precio;
        int tipo;
        bool disponible;

        rlutil::setColor(rlutil::WHITE);
        rlutil::locate(18, 15);
        cin >> nombre;
        rlutil::locate(18, 18);
        cin >> precio;
        rlutil::locate(52, 15);
        cin >> tipo;
        rlutil::locate(52, 18);
        cin >> disponible;

        plato.setDispobible(disponible);
        plato.setNombre(nombre);
        plato.setPrecio(precio);
        plato.setTipo((PlatoTipo)tipo);

        rlutil::setColor(rlutil::LIGHTGREEN);
        rlutil::locate(26, 20);
        if (PlatoGuardar(plato, false))
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

void CrearPlatoVista()
{
    rlutil::setColor(rlutil::LIGHTGREEN);
    char nombre[20];
    float precio;
    int tipo;
    bool disponible;

    rlutil::locate(24, 2);
    cout << "CREAR PLATO";

    rlutil::locate(9, 5);
    cout << "NOMBRE: ";
    rlutil::locate(9, 7);
    cout << "PRECIO: ";
    rlutil::locate(9, 9);
    cout << "TIPO: ";
    //rlutil::locate(9, 11);
    //cout << "DISPONIBLE: ";

    rlutil::setColor(rlutil::WHITE);

    rlutil::locate(24, 5);
    //CargarCadena(nombre, 20);
    cin >> nombre;

    rlutil::locate(24, 7);
    cin >> precio;
    rlutil::locate(24, 9);
    cin >> tipo;
    /*rlutil::locate(24, 11);
    cin >> disponible;*/


    int nuevoId = PlatoGetUltimoId();

    Plato obj;
    obj.setDispobible(true);
    obj.setNombre(nombre);
    obj.setPrecio(precio);
    obj.setTipo((PlatoTipo)tipo);
    obj.setId(nuevoId + 1);

    rlutil::locate(25, 20);
    if (PlatoGuardar(obj, true))
    {
        rlutil::setColor(rlutil::LIGHTGREEN);
        cout << "EL ARCHIVO SE GUARDO CORRECTAMENTE.";
        rlutil::locate(25, 22);
        system("pause");
    }
    else
    {
        cout << "Ha ocurrido un error al grabar los datos.";
        rlutil::locate(25, 22);
        system("pause");
    }

}

void MenuModuloPlato()
{
    int opcionPlato;
    bool volver = false;

    while (!volver)
    {
        DibujarMenuModuloPlato();

        cin >> opcionPlato;

        switch (opcionPlato)
        {
        case 1:
            system("cls");
            CrearPlatoVista();
            system("cls");
            break;
        case 2:
            system("cls");
            MenuModuloPlatoBuscar();
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

int PlatoGetUltimoId()
{
    int id = 0;
    FILE* f = fopen("Plato.dat", "rb+");
    if (f == NULL)
    {
        return 0;
    }
    fseek(f, (sizeof(Plato) * (GetPlatosCantidad() - 1)), SEEK_SET);
    Plato obj;
    if (fread(&obj, sizeof(obj), 1, f))
    {
        id = obj.getId();
    }
    fclose(f);
    return id;
}

bool PlatoGuardar(Plato obj, bool nuevo)
{
    if (nuevo)
    {
        FILE* f = fopen("Plato.dat", "ab");
        if (f == NULL)
        {
            return false;
        }
        fseek(f, 0, SEEK_END);
        fwrite(&obj, sizeof(Plato), 1, f);
        fclose(f);
        return true;
    }
    else
    {
        FILE* f = fopen("Plato.dat", "rb+");
        if (f == NULL)
        {
            return false;
        }
        int pos = obj.getId() - 1;
        fseek(f, sizeof(Plato) * pos, SEEK_SET);
        fwrite(&obj, sizeof(Plato), 1, f);
        fclose(f);
        return true;
    }
}

int GetPlatosCantidad()
{
    int bytes;
    FILE* f = fopen("Plato.dat", "rb");
    if (f == NULL)
    {
        return -1;
    }
    fseek(f, 0, SEEK_END);
    bytes = ftell(f);
    fclose(f);
    return bytes / sizeof(Plato);
}

Plato GetPlatoById(int id)
{
    Plato obj;
    FILE* f = fopen("Plato.dat", "rb+");
    if (f != NULL)
    {
        fseek(f, (sizeof(Plato) * (id - 1)), SEEK_SET);
        fread(&obj, sizeof(obj), 1, f);
        fclose(f);
    }

    return obj;
}