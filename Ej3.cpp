/*
 Ejercicio N°3
Implementar una función recursiva que dado un número entero lo muestre de forma
 invertida ej: 10523 de mostrar 32501. Dar aviso de error en caso de uso de números
 negativos y mostrar primero el número a invertir y después el número invertido.

 */

#include <iostream>

using namespace std;

void mostrarInvertido(int numero, int& invertido) {

    /*Condición Base*/
    if (numero == 0) {
        return;
    } else {
        /*Código necesario*/
        invertido = invertido * 10 + numero % 10;
        /*Recursividad y Terminación*/
        mostrarInvertido(numero / 10, invertido);
    }
}

int main() {
    int numero = 10523;
    cout << "Número original: " << numero << endl;

    if (numero < 0) {
        cout << "Error: Número negativo no permitido." << endl;
        return 1; // Salir del programa con error
    }

    int invertido = 0;
    mostrarInvertido(numero, invertido);

    cout << "Número invertido: " << invertido << endl;
    return 0;
}

