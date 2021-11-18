#include <iostream>
#include <Windows.h>

#include "rlutil.h"
#include "Logica.h"
#include "ModuloPlato.h"
#include "ModuloEmpleado.h"
#include "ModuloVenta.h"

using namespace std;

int main()
{
    int option;
    rlutil::locate(30,10);

    /*cout << "BIENVENIDO";
    Sleep(2000);*/

    system("cls");
    while (true)
    {
        MenuPrincipal();
        cin >> option;

        switch (option)
        {
        case 1:
            system("cls");
            MenuModuloPlato();
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
            MenuModuloEmpleado();
            system("cls");
            break;
        case 4:
            system("cls");
            MenuModuloVenta();
            system("cls");
            break;
        case 0:
            return 0;
            break;
        default:
            system("cls");
            rlutil::setColor(rlutil::LIGHTRED);
            rlutil::locate(25,22);
            cout << "OPCION INCORRECTA" << endl;
            break;
        }

    }

    system("pause");
}