#include <string.h>

#include <iostream>
using namespace std;

struct alumno {
    char codi[12], nomb[20];
    float nota1, nota2, prom;

    void agregar() {
        cout << "\n\t\tALUMNO A INSERTAR : \n";
        cout << "\n\tCODIGO: ";
        cin >> codi;
        cout << "\n\tNOMBRE: ";
        cin >> nomb;
        cout << "\n\tNOTA 1: ";
        cin >> nota1;
        cout << "\n\tNOTA 2: ";
        cin >> nota2;
        prom = (nota1 + nota2) / 2;
    }
    void modificar() {
        int opc, dato2;
        system("cls");
        cout << "\n\nDATO A MODIFICAR";
        cout << "\n1. CODIGO";
        cout << "\n2. NOMBRE";
        cout << "\n3. NOTA 1";
        cout << "\n4. NOTA 2";
        cout << "\n>>> ";
        cin >> opc;
        switch (opc) {
            case 1:
                system("cls");
                cout << "CODIGO POR EL CUAL INTERCAMBIAR: ";
                cin >> codi;
                cin.ignore(100, '\n');
                break;
            case 2:
                system("cls");
                cout << "NOMBRE POR EL CUAL INTERCAMBIAR: ";
                cin >> nomb;
                break;
            case 3:
                system("cls");
                cout << "NOTA 1 POR EL CUAL INTERCAMBIAR: ";
                cin >> nota1;
                prom = (nota1 + nota2) / 2;
                break;
            case 4:
                system("cls");
                cout << "NOTA 2 POR EL CUAL INTERCAMBIAR: ";
                cin >> nota2;
                prom = (nota1 + nota2) / 2;
                break;
            default:
                cout << "OPCION NO DISPONIBLE" << endl;
                system("pause");
                break;
        }
    }
};

void inserta_d(int *, int &, int);
void elimina_d(alumno *, int &);
void modificar_d(int *, int &);
void mostrar(alumno *, int &);
/***********************************************************/
int busca_o(alumno *, int , char *);
void inserta_o(int *, int &, int &);
void elimina_o(int *, int &);
void modificar_o(int *, int &, int, int);
void mostrar(int *, int &);

/***********************************************************************/
void inserta_d(alumno *x, int &n, int max) {
    if (n < max - 1) {
        n++;
        alumno dato;
        dato.agregar();
        x[n] = dato;
    } else {
        system("cls");
        cout << "El arreglo se encuentra lleno." << endl;
        cout << "No se pudo insertar el dato." << endl;
        system("pause");
    }
}
/***********************************************************************/
void elimina_d(alumno *x, int &n) {
    if (n >= 0) {
        char dato[12];
        cout << "Codigo del estudiante a eliminar: ";
        cin >> dato;
        int i = 0;
        bool cen = 0;
        while (i <= n && cen == 0) {
            if (strcmp(dato, x[i].codi) == 0) {
                cen = 1;
                n--;
                for (int j = i; j <= n; j++) {
                    x[j] = x[j + 1];
                }
            } else {
                i++;
            }
        }
        if (cen == 0) {
            system("cls");
            cout << "El dato no se encuentra en el arreglo" << endl;
            system("pause");
        }
    } else {
        system("cls");
        cout << "El array esta vacio. No se puede eliminar el dato" << endl;
        system("pause");
    }
}
/***********************************************************************/
void modificar_d(alumno *x, int &n) {
    if (n > -1) {
        int i = 0;
        bool cen = 0;
        char dato[12];
        cout << "Codigo del estudiante a modificar: ";
        cin >> dato;
        while (i <= n && cen == 0) {
            if (strcmp(dato, x[i].codi) == 0) {
                cen = 1;
                x[i].modificar();
            } else {
                i++;
            }
        }
        if (cen == 0) {
            cout << "El dato no se encuentra en el arreglo." << endl;
            system("pause");
        }
    } else {
        system("cls");
        cout << "El arreglo esta vacio. No se puede modificar el dato";
    }
}

/***********************************************************************/
void mostrar(alumno *x, int &n) {
    if (n > -1) {
        system("cls");
        for (int i = 0; i <= n; i++) {
            cout << "x[" << i + 1 << "] : " << endl;
            cout << "\n\tCodigo: " << x[i].codi << endl;
            cout << "\tNombre: " << x[i].nomb << endl;
            cout << "\tNota 1: " << x[i].nota1 << endl;
            cout << "\tNota 2: " << x[i].nota2 << endl;
            cout << "\tPromedio: " << x[i].prom << endl << endl;
        }
        system("pause");
    } else {
        system("cls");
        cout << "El arreglo se encuentra vacio." << endl;
        system("pause");
    }
}
/***************************************************************************************************************************************/
int busca_o(alumno *y, int m, char *dato) {
    int i = 0;
    while (i <= m && strcmp(y[i].codi, dato) < 0) {
        i++;
    }
    if (i > m || strcmp(y[i].codi, dato) > 0) {
        return -i - 1;
    } else {
        return i;
    }
}
void inserta_o(alumno *y, int &m, int max) {
    if (m < max - 1) {
        alumno dato;
        dato.agregar();
        int pos = busca_o(y, m, dato.codi);
        if (pos < 0) {
            pos = -(pos + 1);
            m++;
            for (int i = m; i > pos; i--) {
                y[i] = y[i - 1];
            }
            y[pos] = dato;
        } else {
            cout << "El dato ya existe en el arreglo" << endl;
            system("pause");
        }

    } else {
        system("cls");
        cout << "El arreglo se encuentra lleno." << endl;
        cout << "No se pudo insertar el dato." << endl;
        system("pause");
    }
}

void elimina_o(alumno *y, int &m) {
    if (m > -1) {
        char dato[12];
        cout << "Codigo del estudiante a eliminar: ";
        cin >> dato;
        int pos = busca_o(y, m, dato);
        if (pos >= 0) {
            m--;
            for (int i = pos; i <= m; i++) {
                y[i] = y[i + 1];
            }

        } else {
            cout << "El dato no se encuentra en el arreglo" << endl;
            system("pause");
        }

    } else {
        system("cls");
        cout << "El arreglo se encuentra vacio." << endl;
        cout << "No se pudo eliminar el dato." << endl;
        system("pause");
    }
}

void modificar_o(alumno *y, int &m) {
    if (m > -1) {
        char dato[12];
        cout << "Codigo del estudiante a modificar: ";
        cin >> dato;
        int pos = busca_o(y, m, dato);
        if (pos >= 0) {
            alumno dato2 = y[pos];
            dato2.modificar();
            if (strcmp(y[pos].codi, dato2.codi) == 0) {
                y[pos] = dato2;
            } else {
                int pos2 = busca_o(y, m, dato2.codi);
                if (pos2 < 0) {
                    for (int i = pos; i < m; i++) {
                        y[i] = y[i + 1];
                    }
                    pos2 = busca_o(y, m-1, dato2.codi);
                    pos2 = -(pos2 + 1);
                    for (int i = m; i > pos2; i--) {
                        y[i] = y[i - 1];
                    }
                    y[pos2] = dato2;
                } else {
                    cout << "El codigo ya existe en el arreglo" << endl;
                    system("pause");
                }
            }
        } else {
            cout << "El dato no se encuentra en el arreglo" << endl;
            system("pause");
        }
    } else {
        system("cls");
        cout << "El arreglo esta vacio. No se puede modificar el dato";
        system("pause");
    }
}