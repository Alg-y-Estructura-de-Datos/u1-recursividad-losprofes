/*
 Ejercicio N°6
Crear un programa que pida al usuario un número entero positivo "n". Luego implementar
 una función recursiva que cuente la cantidad de dígitos pares que ocupan posiciones
 impares (identificándolas de izquierda a derecha) en "n". Ej.: si el número es 22005
 el resultado es 2, y si fuera 1414 el resultado es 0

 */

#include <iostream>

using namespace std;

// Función recursiva para contar dígitos pares en posiciones impares
int contarParesEnPosicionesImpares( unsigned int n,  int tamanionumero ) { //22005
    // Caso base: si n es 0, no hay más dígitos que revisar
    if (n == 0) {
        return 0;
    }
    // Verificar si la posición actual es impar y el dígito es par
    int digitoActual = n % 10;
    if (tamanionumero % 2 != 0 && digitoActual % 2 == 0) {
        // Incrementar el contador y realizar la llamada recursiva
        return 1 + contarParesEnPosicionesImpares(n / 10, tamanionumero - 1);
    } else {
        // Realizar la llamada recursiva sin incrementar el contador
        return contarParesEnPosicionesImpares(n / 10, tamanionumero - 1);
    }
}

int main() {
    unsigned int n;
    int d;
    cout << "Ingrese cantidad de dígitos: ";
    cin >> d;

    cout << "Ingrese un numero entero positivo: ";
    cin >> n;

    // Contar dígitos pares en posiciones impares usando la función recursiva
    int resultado = contarParesEnPosicionesImpares(n,d);

    cout << "Cantidad de dígitos pares en posiciones impares: " << resultado << endl;

    return 0;
}
