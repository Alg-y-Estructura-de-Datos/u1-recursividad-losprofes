/*
 Ejercicio N°1:

 Implemente una función para potencias enteras con recursividad. Definición recursiva
 para elevar un número a una potencia: Un número elevado a la potencia cero produce
 la unidad; la potencia de un número se obtiene multiplicándolo por sí mismo elevando
 a la potencia menos uno. Por ejemplo:

    32=3*(31)=3*[3*(30)]=3*(3*1)=9
 */

#include <iostream>

using namespace std;

int potenciaRecursiva(int base, int exponente) {

// Función recursiva para calcular la potencia
    int potenciaRecursiva(int base, int exponente) {
        // Caso base: cualquier número elevado a la potencia 0 es 1
        if (exponente == 0) {
            return 1;
        } else {
            // Llamada recursiva: multiplica la base por la base elevada al exponente menos uno
            return base * potenciaRecursiva(base, exponente - 1);
        }
    }
}

int main() {

    int base = 2;
    int exponente = 5;

    // Imprimir la base y el exponente
    cout << base << " elevado a la potencia " << exponente << " es: ";
    // Llamar a la función recursiva para calcular la potencia
    int resultado = potenciaRecursiva(base, exponente);
    // Imprimir el resultado de la potencia
    cout << resultado << endl;

    return 0;
}






