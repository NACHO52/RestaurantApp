#include <iostream>
#include "rlutil.h"
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

    rlutil::setColor(rlutil::WHITE);
    rlutil::locate(25, 20);
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
            cout << "opcion 1" << endl;
            system("pause");
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