#include <iostream>
#include "listasDobles.h"
#include <string.h>

using namespace std;

int main() {
    char codigo[10];
    nodo *p = NULL, *f = NULL;
    int op;
    do{
        system("cls");
        cout << "-----------------------------" << endl;
        cout << "-Listas Doblemente Enlazadas-" << endl;
        cout << "-----------------------------" << endl;
        cout << "1. Crear lista doblemente enlazada por el inicio" << endl;
        cout << "2. Crear lista doblemente enlazada por el final" << endl;
        cout << "3. Insertar al inicio" << endl;
        cout << "4. Insertar al final" << endl;
        cout << "5. Insertar antes de una referencia" << endl;
        cout << "6. Insertar despues de una referencia" << endl;
        cout << "7. Elimina el primer nodo" << endl;
        cout << "8. Elimina el ultimo nodo" << endl;
        cout << "9. Elimina un nodo especifico" << endl;
        cout << "10. Eliminar el nodo anterior a una referencia" << endl;
        cout << "11. Eliminar el nodo posterior a una referencia" << endl;
        cout << "12. Mostrar lista doblemente enlazada" << endl;
        cout << "13. Salir" << endl;
        cout << "OPCION >>> ";
        cin >> op;
        switch (op) {
            case 1:
                system("cls");
                cout << "-------------------------------------------------" << endl;
                cout << "-CREANDO LISTA DOBLEMENTE ENLAZADA POR EL INICIO-" << endl;
                cout << "-------------------------------------------------" << endl;
                cread_i(p, f);
                system("pause");
                break;
            case 2:
                system("cls");
                cout << "------------------------------------------------" << endl;
                cout << "-CREANDO LISTA DOBLEMENTE ENLAZADA POR EL FINAL-" << endl;
                cout << "------------------------------------------------" << endl;
                cread_f(p,f);
                system("pause");
                break;
            case 3:
                system("cls");
                cout << "----------------------------------" << endl;
                cout << "-INSERTANDO UN NODO POR EL INICIO-" << endl;
                cout << "----------------------------------" << endl;
                insertad_i(p, f);
                system("pause");
                break;
            case 4:
                system("cls");
                cout << "---------------------------------" << endl;
                cout << "-INSERTANDO UN NODO POR EL FINAL-" << endl;
                cout << "---------------------------------" << endl;
                insertad_f(p, f);
                system("pause");
                break;
            case 5:
                system("cls");
                cout << "--------------------------------------------" << endl;
                cout << "-INSERTANDO UN NODO ANTES DE UNA REFERENCIA-" << endl;
                cout << "--------------------------------------------" << endl;
                cout << "\nREFERENCIA: ";
                cin >> codigo;
                insertad_ad(p, codigo);
                system("pause");
                break;
            case 6:
                system("cls");
                cout << "----------------------------------------------" << endl;
                cout << "-INSERTANDO UN NODO DESPUES DE UNA REFERENCIA-" << endl;
                cout << "----------------------------------------------" << endl;
                cout << "\nREFERENCIA: ";
                cin >> codigo;
                insertad_dd(f, codigo);
                recorre(p);
                system("pause");
                break;
            case 7:
                system("cls");
                cout << "---------------------------------------" << endl;
                cout << "-ELIMINANDO EL PRIMER NODO DE LA LISTA-" << endl;
                cout << "---------------------------------------" << endl;
                eliminard_p(p,f);
                system("pause");
                break;
            case 8:
                system("cls");
                cout << "---------------------------------------" << endl;
                cout << "-ELIMINANDO EL ULTIMO NODO DE LA LISTA-" << endl;
                cout << "---------------------------------------" << endl;
                eliminard_u(p,f);
                system("pause");
                break;
            case 9:
                system("cls");
                cout << "-------------------------------------------" << endl;
                cout << "-ELIMINANDO UN NODO ESPECIFICO DE LA LISTA-" << endl;
                cout << "-------------------------------------------" << endl;
                cout << "\nREFERENCIA: ";
                cin >> codigo;
                eliminard_x(p,f,codigo);
                system("pause");
                break;
            case 10:
                system("cls");
                cout << "-------------------------------------------" << endl;
                cout << "-ELIMINANDO UN NODO ANTES DE UNA REFERNCIA-" << endl;
                cout << "-------------------------------------------" << endl;
                cout << "\nREFERENCIA: ";
                cin >> codigo;
                eliminard_ad(p, codigo);
                system("pause");
                break;
            case 11:
                system("cls");
                cout << "----------------------------------------------" << endl;
                cout << "-ELIMINANDO UN NODO DESPUES DE UNA REFERENCIA-" << endl;
                cout << "----------------------------------------------" << endl;
                cout << "\nREFERENCIA: ";
                cin >> codigo;
                eliminard_dd(f,codigo);
                recorre(p);
                system("pause");
                break;
            case 12:
                system("cls");
                recorre(p);
                system("pause");
                break;
            case 13:
                // system("cls");
                cout << "\n...Saliendo del programa...";
                // system("pause");
                break;
            default: 
                cout << "\nInserte una opcion valida [1-13]";
                system("pause");
                break;
        }

    } while(op < 13);

    return 0;
} 