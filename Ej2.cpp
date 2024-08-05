/*
Ejercicio N°2
Implementar una función recursiva que determine la suma de los “n” primeros números
 naturales ej: para n=5 mostrar por pantalla 1+2+3+4+5 y luego el resultado de la suma.
 */

#include <iostream>

using namespace std;

int sumaRecursiva(int n) {

    /*Caso Base*/
    if (n == 1) {
        cout << n; // Imprimir el primer número sin el signo "+"
        return 1;

    } else { //else opcional
        cout << n << " + ";
        /*Recursividad y Terminación*/
        return n + sumaRecursiva(n - 1);
    }
}

int main() {
    int n = 5;
    cout << "Suma de los primeros " << n << " numeros naturales: ";
    int suma = sumaRecursiva(n);
    cout << " = " << suma << endl;
    return 0;
}
