/*
Ejercicio N°5
Crear un programa que pida al usuario un número entero positivo "n" y un dígito "d".
 Luego crear una función recursiva que determine si “d” está en “n”. Si está,
 la función debe retornar verdadero y si no está debe retornar falso.
Ej.: si n=1323 y d = 5, retorna Verdadero y si d= 1 retorna falso.
*/


#include <iostream>

using namespace std;

// Función recursiva para determinar si el dígito 'd' está en el número 'n'
bool contieneDigito(int n, int d) {
    // Caso base: si n es 0, hemos revisado todos los dígitos y no encontramos 'd'
    if (n == 0) {
        return false;
    }
    // Si el dígito actual (n % 10) es igual a 'd', retornar verdadero
    if (n % 10 == d) {
        return true;
    }
    // Llamada recursiva con el número sin el último dígito
    return contieneDigito(n / 10, d);
}

int main() {
    int n, d;
    cout << "Ingrese un numero entero positivo: ";
    cin >> n;
    cout << "Ingrese un digito: ";
    cin >> d;

    // Verificar si el dígito está en el número usando la función recursiva
    bool resultado = contieneDigito(n, d);
    if (resultado) {
        cout << "El digito " << d << " esta en el numero " << n << "." << endl;
    } else {
        cout << "El digito " << d << " no esta en el numero " << n << "." << endl;
    }

    return 0;
}


int potenciaIterativa(int base, int exponente) {
    // Resultado inicial es 1 (base^0 = 1)
    int resultado = 1;

    // Si el exponente es negativo, la potencia no es definida para números enteros
    if (exponente < 0) {
        cout << "El exponente debe ser un número entero no negativo." << endl;
        return -1; // Indicamos error con un valor negativo
    }

    // Iterar desde 1 hasta el exponente
    for (int i = 0; i < exponente; ++i) {
        resultado *= base;
    }

    return resultado;
}