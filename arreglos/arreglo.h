#include <string.h>

#include <iostream>
using namespace std;

void inserta_d(int *, int &, int, int);
void elimina_d(int *, int &, int &);
void modificar_d(int *, int &, int &, int &);
void mostrar(int *, int &);
/***********************************************************/
int busca_o(int *, int , int &);
void inserta_o(int *, int &, int, int &);
void elimina_o(int *, int &, int &);
void modificar_o(int *, int &, int &, int &);
void mostrar(int *, int &);

/***********************************************************************/
void inserta_d(int *x, int &n, int dato, int max) {
    if (n < max - 1) {
        n++;
        x[n] = dato;
    } else {
        system("cls");
        cout << "El arreglo se encuentra lleno." << endl;
        cout << "No se pudo insertar el dato." << endl;
        system("pause");
    }
}
/***********************************************************************/
void elimina_d(int *x, int &n, int &dato) {
    if (n >= 0) {
        int i = 0;
        bool cen = 0;
        while (i <= n && cen == 0) {
            if (x[i] == dato) {
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
            cout << "El dato no se encuentra en el arreglo" << endl;
            system("pause");
        }
    } else {
        cout << "El array esta vacio. No se puede eliminar el dato" << endl;
        system("pause");
    }
}
/***********************************************************************/
void modificar_d(int *x, int &n, int &dato, int &dato2) {
    if (n > -1) {
        int i = 0;
        bool cen = 0;
        while (i <= n && cen == 0) {
            if (x[i] == dato) {
                cen = 1;
                x[i] = dato2;
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
void mostrar(int *x, int &n) {
    if (n > -1) {
        for (int i = 0; i <= n; i++) {
            cout << "x[" << i + 1 << "] : " << x[i] <<endl;
        }
        system("pause");
    } else {
        cout << "El arreglo se encuentra vacio." << endl;
        system("pause");
    }
}
/***************************************************************************************************************************************/
int busca_o(int *y, int m, int &dato) {
    int i = 0;
    while (i <= m && y[i] < dato) {
        i++;
    }
    if (i > m || y[i] > dato) {
        return -i - 1;
    } else {
        return i;
    }
}
/***********************************************************************/
void inserta_o(int *y, int &m, int max, int &dato) {
    if (m < max - 1) {
        int pos = busca_o(y, m, dato);
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
/***********************************************************************/
void elimina_o(int *y, int &m, int &dato) {
    if (m > -1) {
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
        cout << "El arreglo se encuentra vacio." << endl;
        cout << "No se pudo eliminar el dato." << endl;
        system("pause");
    }
}
/***********************************************************************/
void modificar_o(int *y, int &m, int &dato, int &dato2) {
    if (m > -1) {
        int pos = busca_o(y, m, dato);
        if (pos >= 0) {
            if (dato == dato2) {
                y[pos] = dato2;
            } else {
                int pos2 = busca_o(y, m, dato2);
                if (pos2 < 0) {
                    for (int i = pos; i < m; i++) {
                        y[i] = y[i + 1];
                    }
                    pos2 = busca_o(y, m-1, dato2);
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
        cout << "El arreglo esta vacio. No se puede modificar el dato";
        system("pause");
    }
}