#include <string.h>

#include <cmath>
#include <iostream>

#include "pilas.h"

using namespace std;
void prefija(char ei[], int n);
void postfija(char ei[], int n);
void evpre(char ei[], int n);
void evpost(char ei[], int n);

int main() {
    char ei[20];
    int n;
    int op;
    do {
        system("cls");
        cout << "-----------------------------" << endl;
        cout << "-Pilas y Notacion Polaca-" << endl;
        cout << "-----------------------------" << endl;
        cout << "1. Convertir infija a prefija" << endl;
        cout << "2. Convertir infija a postfija" << endl;
        cout << "3. Evaluar expresion prefija" << endl;
        cout << "4. Evaluar expresion postfija" << endl;
        cout << "5. Salir" << endl;
        cout << "OPCION >>> ";
        cin >> op;
        switch (op) {
            case 1:
                system("cls");
                cout << "-------------------------------------------------"
                     << endl;
                cout << "-CONVERSION EXPRESION INFIJA A PREFIJA-" << endl;
                cout << "-------------------------------------------------"
                     << endl;
                cout << endl << "Expresion Infija: ";
                cin >> ei;
                n = strlen(ei);
                prefija(ei, n);
                system("pause");
                break;
            case 2:
                system("cls");
                cout << "-------------------------------------------------"
                     << endl;
                cout << "-CONVERSION EXPRESION INFIJA A POSTFIJA-" << endl;
                cout << "-------------------------------------------------"
                     << endl;
                cout << endl << "Expresion Infija: ";
                cin >> ei;
                n = strlen(ei);
                postfija(ei, n);
                system("pause");
                break;
            case 3:
                system("cls");
                cout << "-------------------------------------------------"
                     << endl;
                cout << "-CALCULAR EXPRESION PREFIJA-" << endl;
                cout << "-------------------------------------------------"
                     << endl;
                cout << endl << "Expresion Prefija: ";
                cin >> ei;
                n = strlen(ei);
                evpre(ei, n);
                system("pause");
                break;
            case 4:
                system("cls");
                cout << "-------------------------------------------------"
                     << endl;
                cout << "-CALCULAR EXPRESION POSTFIJA-" << endl;
                cout << "-------------------------------------------------"
                     << endl;
                cout << endl << "Expresion Postfija: ";
                cin >> ei;
                n = strlen(ei);
                evpost(ei, n);
                system("pause");
                break;
            case 5:
                // system("cls");
                cout << "\n...Saliendo del programa...";
                // system("pause");
                break;
            default:
                cout << "\nInserte una opcion valida [1-5]";
                // system("pause");
                break;
        }
    } while (op < 5);

    return 0;
}

int prioridad(char a) {
    if (a == '^') {
        return 3;
    } else if (a == '*' || a == '/') {
        return 2;
    } else if (a == '+' || a == '-') {
        return 1;
    }
    return 0;
}

void prefija(char ei[], int n) {
    char pila[n];
    char epre[n];
    int tope = -1;
    int i = n - 1;
    int j = -1;
    while (i > -1) {
        if (ei[i] == ')') {
            tope++;
            pila[tope] = ei[i];
        } else {
            if (ei[i] == '(') {
                while (pila[tope] != ')') {
                    j++;
                    epre[j] = pila[tope];
                    tope--;
                }
                tope--;
            } else {
                if (isdigit(ei[i])) {
                    j++;
                    epre[j] = ei[i];
                } else {
                    while (tope > -1 &&
                           prioridad(ei[i]) < prioridad(pila[tope])) {
                        j++;
                        epre[j] = pila[tope];
                        tope--;
                    }
                    tope++;
                    pila[tope] = ei[i];
                }
            }
        }
        i--;
    }
    while (tope > -1) {
        j++;
        epre[j] = pila[tope];
        tope--;
    }

    cout << "Expresion Prefija: ";
    for (int k = j; k > -1; k--) {
        cout << epre[k];
    }
    cout << endl;
}

void postfija(char ei[], int n) {
    char pila[n];
    char epost[n];
    int tope = -1;
    int i = 0;
    int j = -1;
    while (i < n) {
        if (ei[i] == '(') {
            tope++;
            pila[tope] = ei[i];
        } else {
            if (ei[i] == ')') {
                while (pila[tope] != '(') {
                    j++;
                    epost[j] = pila[tope];
                    tope--;
                }
                tope--;
            } else {
                if (isdigit(ei[i])) {
                    j++;
                    epost[j] = ei[i];
                } else {
                    while (tope > -1 &&
                           prioridad(ei[i]) <= prioridad(pila[tope])) {
                        j++;
                        epost[j] = pila[tope];
                        tope--;
                    }
                    tope++;
                    pila[tope] = ei[i];
                }
            }
        }
        i++;
    }
    while (tope > -1) {
        j++;
        epost[j] = pila[tope];
        tope--;
    }

    cout << "Expresion Prefija: ";
    for (int k = 0; k <= j; k++) {
        cout << epost[k];
    }
    cout << endl;
}

void evpre(char ei[], int n) {
    int pila[n];
    int tope = -1;
    int i = n - 1;
    int op1;
    int op2;
    while (i > -1) {
        if (isdigit(ei[i])) {
            tope++;
            pila[tope] = ei[i] - '0';
        } else {
            op1 = pila[tope--];
            op2 = pila[tope];
            int res;
            switch (ei[i]) {
                case '+':
                    res = op1 + op2;
                    break;
                case '-':
                    res = op1 - op2;
                    break;
                case '*':
                    res = op1 * op2;
                    break;
                case '/':
                    res = op1 / op2;
                    break;
                case '^':
                    res = pow(op1, op2);
                    break;
            }
            pila[tope] = res;
        }
        i--;
    }
    cout << endl << "Resultado: " << pila[tope] << endl;
}


// 1 + 2 * 3
// 1 + 23*
// 123*+
void evpost(char ei[], int n) {
    int pila[n];
    int tope = -1;
    int i = 0;
    int op1;
    int op2;
    while (i < n) {
        if (isdigit(ei[i])) {
            tope++;
            pila[tope] = ei[i] - '0';
        } else {
            op1 = pila[tope--];
            op2 = pila[tope];
            int res;
            switch (ei[i]) {
                case '+':
                    res = op1 + op2;
                    break;
                case '-':
                    res = op1 - op2;
                    break;
                case '*':
                    res = op1 * op2;
                    break;
                case '/':
                    res = op1 / op2;
                    break;
                case '^':
                    res = pow(op1, op2);
                    break;
            }
            pila[tope] = res;
        }
        i++;
    }
    cout << endl << "Resultado: " << pila[tope] << endl;
}