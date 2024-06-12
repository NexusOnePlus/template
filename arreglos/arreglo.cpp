#include <iostream>
#include <string.h>

#include "arreglo.h"
#define max 10
using namespace std;

int main() {
    int x[max], y[max];
    int op, dec, n = -1, m = -1, dato, dato2;
    do {
        system("cls");
        cout << "\n\nMENU DE OPCIONES";
        cout << "\n1. Array Desordenados";
        cout << "\n2. Array Ordenados";
        cout << "\n3. Salir";
        cout << "\n>>> ";
        cin >> op;
        switch (op) {
            case 1:
                do {
                    system("cls");
                    cout << "\n\nARREGLOS DESORDENADOS";
                    cout << "\n1. Insertar";
                    cout << "\n2. Eliminar";
                    cout << "\n3. Modificar";
                    cout << "\n4. Mostrar";
                    cout << "\n5. Salir";
                    cout << "\n>>> ";
                    cin >> dec;
                    switch (dec) {
                        case 1:
                            system("cls");
                            cout << "\n\nDato a insertar: ";
                            cin >> dato;
                            inserta_d(x, n, dato, max);
                            break;
                        case 2:
                            system("cls");
                            cout << "\n\nDato a eliminar: ";
                            cin >> dato;
                            elimina_d(x, n, dato);
                            break;
                        case 3:
                            system("cls");
                            cout << "\n\nDato a modificar: ";
                            cin >> dato;
                            cout << "\n\nDato nuevo: ";
                            cin >> dato2;
                            modificar_d(x, n, dato, dato2);
                            break;
                        case 4:
                            system("cls");
                            mostrar(x, n);
                            break;
                        case 5:
                            break;
                        default:
                            cout << "\nOpcion no valida. Eliga entre [1-5].\n";
                            system("pause");
                            break;
                    }
                } while (dec > 0 && dec < 5);
                break;
            case 2:
                do {
                    system("cls");
                    cout << "\n\nARREGLOS ORDENADOS";
                    cout << "\n1. Insertar";
                    cout << "\n2. Eliminar";
                    cout << "\n3. Modificar";
                    cout << "\n4. Mostrar";
                    cout << "\n5. Salir";
                    cout << "\n>>> ";
                    cin >> dec;
                    switch (dec) {
                        case 1:
                            system("cls");
                            cout << "\n\nDato a insertar: ";
                            cin >> dato;
                            inserta_o(y, m, max, dato);
                            break;
                        case 2:
                            system("cls");
                            cout << "\n\nDato a eliminar: ";
                            cin >> dato;
                            elimina_o(y, m, dato);
                            break;
                        case 3:
                            system("cls");
                            cout << "\n\nDato a modificar: ";
                            cin >> dato;
                            cout << "\n\nDato nuevo: ";
                            cin >> dato2;
                            modificar_o(y, m, dato, dato2);
                            break;
                        case 4:
                            system("cls");
                            mostrar(y, m);
                            break;
                        case 5:
                            break;
                        default:
                            cout << "\nOpcion no valida. Eliga entre [1-5].\n";
                            system("pause");
                            break;
                    }
                } while (dec > 0 && dec < 5);
                break;
            case 3:
                break;
            default:
                cout << "\nOpcion no valida. Eliga entre [1-3].\n";
                system("pause");
        }
    } while (op > 0 && op < 3);
    return 0;
}
