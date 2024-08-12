/*
 Ejercicio N°4

 Crear un programa que emplee recursividad para calcular el mayor de los elementos
 de un vector de “n” tamaño dado por pantalla por el usuario.
 */

#include <iostream>
#include <vector>

using namespace std;

// Función recursiva para encontrar el mayor elemento en un vector
int encontrarMayorRecursivo(const vector<int>& vec, int n) { //vec[3]={4,5,6} n=3
    // Caso base: si el vector tiene un solo elemento, ese elemento es el mayor
    if (n == 1) {
        return vec[0];
    }
    /////
    // Llamada recursiva: comparar el último elemento con el mayor de los anteriores
    int maxAnterior = encontrarMayorRecursivo(vec, n - 1);
// int maxAnterior =    5;
// int maxAnterior = vec[0];; n=2
// return vec[0];

    if (vec[n - 1] > maxAnterior) { //   6  > 5
        return vec[n - 1];
    } else {
        return maxAnterior;
    }
}

int main() {
    int n;
    cout << "Ingrese el tamaño del vector: ";
    cin >> n;

    vector<int> vec(n);
    //int vec [n];

    cout << "Ingrese los elementos del vector:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }

    // Llamar a la función recursiva para encontrar el mayor elemento
    int mayor = encontrarMayorRecursivo(vec, n);
    cout << "El mayor elemento del vector es: " << mayor << endl;

    return 0;
}
