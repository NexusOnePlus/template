#include <iostream>
#include <string.h>

#include "array.h"
#define max 10
using namespace std;

int main() {
    alumno x[max], y[max];
    int op, dec, n = -1, m = -1;
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
                            inserta_d(x, n, max);
                            break;
                        case 2:
                            system("cls");
                            elimina_d(x, n);
                            cout << "El dato se elimino correctamente!!"
                                 << endl;
                            system("pause");
                            break;
                        case 3:
                            system("cls");
                            modificar_d(x, n);
                            break;
                        case 4:
                            mostrar(x, n);
                            system("cls");
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
                            inserta_o(y, m, max);
                            break;
                        case 2:
                            elimina_o(y, m);
                            system("cls");
                            break;
                        case 3:
                            modificar_o(y, m);
                            system("cls");
                            break;
                        case 4:
                            mostrar(y, m);
                            system("cls");
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