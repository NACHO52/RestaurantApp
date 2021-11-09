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
    cout << "2 _ REPORTES";

    rlutil::locate(25, 11);
    cout << "3 _ BUSCAR";

    rlutil::locate(25, 15);
    cout << "0 _ VOLVER";


    rlutil::locate(25, 20);
    cout << "OPCION:";

    rlutil::setColor(rlutil::WHITE);
    rlutil::locate(34, 20);
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
    if (nuevoId == 1)
    {
        //TODO: mensaje de error
    }

    Plato obj;
    obj.setDispobible(true);
    obj.setNombre(nombre);
    obj.setPrecio(precio);
    obj.setTipo((PlatoTipo)tipo);
    obj.setId(nuevoId);

    rlutil::locate(25, 20);
    if (PlatoGuardar(obj))
    {
        cout << "El archivo se guardo correctamente.";
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
            cout << "opcion 2" << endl;
            system("pause");
            system("cls");
            break;
        case 3:
            system("cls");
            cout << "opcion 3" << endl;
            system("pause");
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

int PlatoGetUltimoId()
{
    int id = 1;
    FILE* f = fopen("Plato.dat", "wb+");
    if (f == NULL)
    {
        return -1;
    }
    fseek(f, -1, SEEK_END);
    Plato obj;
    if (fread(&obj, sizeof(obj), 1, f))
    {
        id = obj.getId();
    }
    fclose(f);
    return id;
}

bool PlatoGuardar(Plato obj)
{
    FILE* f = fopen("Plato.dat", "wb");
    if (f == NULL)
    {
        return false;
    }
    fseek(f, 0, SEEK_END);
    fwrite(&obj, sizeof(obj), 1, f);
    fclose(f);
    return true;
}