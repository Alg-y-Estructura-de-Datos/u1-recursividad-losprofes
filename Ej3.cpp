/*
 Ejercicio N°3
Implementar una función recursiva que dado un número entero lo muestre de forma
 invertida ej: 10523 de mostrar 32501. Dar aviso de error en caso de uso de números
 negativos y mostrar primero el número a invertir y después el número invertido.

 */

#include <iostream>

using namespace std;

void mostrarInvertido(int numero, int& invertido) { //n = 123 invertido = 0

    /*Condición Base*/
    if (numero == 0) {
        return;
    } else {
        /*Código necesario*/
        invertido = invertido * 10 + numero % 10;       //invertido = 0*10 + 123 % 10 = 0+3 = 3
        //invertido = 3*10 + 12%10 = 30 + 2 = 32
        // invertido = 32*10 + 1%10 = 320 + 1 = 321
        /*Recursividad y Terminación*/
        mostrarInvertido(numero / 10, invertido); // return;
    }
}

int main() {
    int numero = 123;
    cout << "Numero original: " << numero << endl;

    if (numero < 0) {
        cout << "Error: Número negativo no permitido." << endl;
        return 1; // Salir del programa con error
    }

    int resultado = 0;
    mostrarInvertido(numero, resultado);

    cout << "Numero invertido: " << resultado << endl;
    return 0;
}

