#include <iostream>
#include "listas.h"
using namespace std;

int main()
{
    int opc;
    char ref[20];
    nodo *p = NULL;
    do
    {
        system("cls");
        cout << "----------------------------" << endl;
        cout << "--LISTAS ENLAZADAS SIMPLES--" << endl;
        cout << "----------------------------" << endl;
        cout << "1. Crear lista desde el inicio" << endl;
        cout << "2. Crear lista desde el final" << endl;
        cout << "3. Insertar desde el inicio" << endl;
        cout << "4. Insertar desde el final" << endl;
        cout << "5. Insertar antes de una referencia" << endl;
        cout << "6. Insertar despues de una referencia" << endl;
        cout << "7. Eliminar el primer nodo" << endl;
        cout << "8. Eliminar el ultimo nodo" << endl;
        cout << "9. Eliminar un nodo especifico" << endl;
        cout << "10. Eliminar el nodo anterior a una referencia" << endl;
        cout << "11. Eliminar el nodo posterior a una referencia" << endl;
        cout << "12. Mostrar la lista simple enlazada actual" << endl;
        cout << "13. Salir" << endl;
        cout << ">>> ";
        cin >> opc;
        switch (opc)
        {
        case 1:
            system("cls");
            cout << "---------------------------------" << endl;
            cout << "--CREANDO LISTA DESDE EL INICIO--" << endl;
            cout << "---------------------------------" << endl;
            p = NULL;
            crea_i(p);
            system("pause");
            break;

        case 2:
            system("cls");
            cout << "---------------------------------" << endl;
            cout << "--CREANDO LISTA DESDE EL FINAL--" << endl;
            cout << "---------------------------------" << endl;
            p = NULL;
            crea_f(p);
            system("pause");
            break;

        case 3:
            system("cls");
            cout << "-------------------------------------" << endl;
            cout << "--INSERTANDO UN NODO DESDE EL INCIO--" << endl;
            cout << "-------------------------------------" << endl;
            inserta_i(p);
            system("pause");
            break;

        case 4:
            system("cls");
            cout << "-------------------------------------" << endl;
            cout << "--INSERTANDO UN NODO DESDE EL FINAL--" << endl;
            cout << "-------------------------------------" << endl;
            inserta_f(p);
            system("pause");
            break;

        case 5:
            system("cls");
            cout << "----------------------------------------------" << endl;
            cout << "--INSERTANDO UN NODO ANTES DE UNA REFERENCIA--" << endl;
            cout << "----------------------------------------------" << endl;
            recorre(p);
            cout << "\nREFERENCIA: ";
            cin >> ref;
            inserta_ad(p, ref);
            system("pause");
            break;

        case 6:
            system("cls");
            cout << "------------------------------------------------" << endl;
            cout << "--INSERTANDO UN NODO DESPUES DE UNA REFERENCIA--" << endl;
            cout << "------------------------------------------------" << endl;
            recorre(p);
            cout << "\nREFERENCIA: ";
            cin >> ref;
            despues_dd(p, ref);
            system("pause");
            break;
        case 7:
            system("cls");
            cout << "-----------------------------" << endl;
            cout << "--ELIMINANDO EL PRIMER NODO--" << endl;
            cout << "-----------------------------" << endl;
            recorre(p);
            eliminar_p(p);
            system("pause");
            break;
        case 8:
            system("cls");
            cout << "-----------------------------" << endl;
            cout << "--ELIMINANDO EL ULTIMO NODO--" << endl;
            cout << "-----------------------------" << endl;
            recorre(p);
            eliminar_u(p);
            system("pause");
            break;
        case 9:
            system("cls");
            cout << "------------------------------------" << endl;
            cout << "--ELIMINANDO UN NODO EN ESPECIFICO--" << endl;
            cout << "------------------------------------" << endl;
            recorre(p);
            cout << "\nREFERENCIA: ";
            cin >> ref;
            eliminar_x(p,ref);
            system("pause");
            break;
        case 10:
            system("cls");
            cout << "------------------------------------------------" << endl;
            cout << "--ELIMINANDO UN NODO ANTERIOR A UNA REFERENCIA--" << endl;
            cout << "------------------------------------------------" << endl;
            recorre(p);
            cout << "\nREFERENCIA: ";
            cin >> ref;
            eliminar_ad(p,ref);
            system("pause");
            break;
        case 11:
            system("cls");
            cout << "------------------------------------------------" << endl;
            cout << "--ELIMINANDO UN NODO POSTERIOR A UNA REFERENCIA--" << endl;
            cout << "------------------------------------------------" << endl;
            recorre(p);
            cout << "\nREFERENCIA: ";
            cin >> ref;
            eliminar_dd(p,ref);
            system("pause");
            break;
        case 12:
            system("cls");
            recorre(p);
            system("pause");
            break;
        case 13:
            cout << "---------------------" << endl;
            cout << "SALIENDO DEL PROGRAMA" << endl;
            cout << "---------------------" << endl;
            system("pause");
            break;
        default:
            cout << "-------------------------------" << endl;
            cout << "Eliga una opcion valida [1-7]!!" << endl;
            cout << "-------------------------------" << endl;
            opc = 0;
            system("pause");
            break;
        }
    } while (opc < 13);

    return 0;
}