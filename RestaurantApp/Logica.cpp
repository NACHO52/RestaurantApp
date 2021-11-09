#include <iostream>
#include <cstdio>
#include "rlutil.h"
using namespace std;

void MenuPrincipal()
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
    cout << "1 _ PLATOS";

    rlutil::locate(25, 9);
    cout << "2 _ CLIENTES";

    rlutil::locate(25, 11);
    cout << "3 _ EMPLEADOS";

    rlutil::locate(25, 13);
    cout << "4 _ VENTAS";

    rlutil::locate(25, 15);
    cout << "0 _ SALIR";


    rlutil::locate(25, 20);
    cout << "OPCION:";

    rlutil::setColor(rlutil::WHITE);
    rlutil::locate(34, 20);
}


void CargarCadena(char* pal, int tam) 
{
    fflush(stdin);
    int i;
    for (i = 0; i < tam; i++) 
    {
        pal[i] = cin.get();
        if (pal[i] == '\n') break;
    }
    pal[i] = '\0';
    fflush(stdin);
}
