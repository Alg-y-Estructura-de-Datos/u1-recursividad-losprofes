/*
Ejercicio N°2
Implementar una función recursiva que determine la suma de los “n” primeros números
 naturales ej: para n=5 mostrar por pantalla 1+2+3+4+5 y luego el resultado de la suma.
 */

#include <iostream>

using namespace std;

int sumaRecursiva(int n) { //n=3

    /*Caso Base*/
    if (n == 0) {
        cout << n; // Imprimir el primer número sin el signo "+"
        return 0;

    } else { //else opcional
        cout << n << " + ";
        /*Recursividad y Terminación*/
        return n + sumaRecursiva(n - 1); //return 3 + 3=6


    }
}

int main() {
    int n = 5;
    cout << "Suma de los primeros " << n << " numeros naturales: ";
    int suma = sumaRecursiva(n);
    cout << " = " << suma << endl;
    return 0;
}
