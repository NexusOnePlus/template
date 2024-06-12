#include <iostream>
#include <string.h>
using namespace std;

// 
template <typename T>
void pila_insertar(T *, int, int, T *);
template <typename T>
T pila_eliminar(T* , int);


template <typename T>
void pila_insertar(T *pila, int max, int tope, T *dato) {
    if(tope < max){
        tope++;
        pila[tope] = dato;
    } else {
        cout << "\nPila llena" << endl;
    }
}

template <typename T>
T pila_eliminar(T *pila, int tope){
    if (tope > 0){
        T dato = pila[tope];
        tope--;
        return dato;
    } else {
        cout << "\nNo hay elementos" << endl;
    }
}
