#include <iostream>
#include "rlutil.h"
#include "Cliente.h"

using namespace std;

int main()
{
    int option;
    cout << "Bienvenido" << endl;

    while (true)
    {
        system("cls");
        cout << "1 _ PLATOS" << endl;
        cout << "2 _ CLIENTES" << endl;
        cout << "3 _ EMPLEADOS" << endl;
        cout << "4 _ VENTAS" << endl;
        cout << endl << "0 _ SALIR" << endl;

        cin >> option;

        switch (option)
        {
        case 1:
            system("cls");
            cout << "opcion 1" << endl;
            system("pause");
            break;
        case 2:
            system("cls");
            cout << "opcion 2" << endl;
            system("pause");
            break;
        case 3:
            system("cls");
            cout << "opcion 3" << endl;
            system("pause");
            break;
        case 4:
            system("cls");
            cout << "opcion 4" << endl;
            system("pause");
            break;
        default:
            return 0;
            break;
        }

    }

    system("pause");
}