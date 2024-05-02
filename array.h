#include <iostream>
#include <string>
using namespace std;

struct alumno {
    char codi[10], nomb[20];
    float nota1, nota2, prom;
    alumno(){};
    alumno(int a) {
        cout << "\n\t\tALUMNO A INSERTAR : \n";
        cout << "\n\tCODIGO: ";
        cin >> codi;;
        cout << "\n\tNOMBRE: ";
        cin >> nomb;
        cout << "\n\tNOTA 1: ";
        cin >> nota1;
        cout << "\n\tNOTA 2: ";
        cin >> nota2;
    }
};
//**************************************************************************************************
void mostrar(int *x, int n);
void inserta_d(int *x, int &n, int max);
// ***********************************************************************************************
void inserta_d(alumno *x, int &n, alumno a ,int max) {
    if (n < max-1) {
        n++;
        x[n] = a;
    } else {
        cout << "El array esta llena.\n";
        system("pause");
    }
}
// ***********************************************************************************************
void mostrar(int *x, int n) {
    if (n >= 0) {
        for (int i = 0; i < n; i++) {
            cout << "x[" << i + 1 << "] = " << x[i] << endl;
        }
    } else {
        cout << "El array esta vacio. << endl";
        system("pause");
    }
}