
/*
Ejercicio N°7: Búsqueda de una Clase en el Horario Escolar.
Eres un estudiante que necesita encontrar el horario de una clase específica en tu horario semanal
 de clases. Estás interesado en comparar dos tipos de búsquedas, la secuencial y la binaria.
 Usando recursividad, implementa el código en lenguaje C++. Se puede usar la librería String.

Búsqueda Secuencial Recursiva:

Implementa una función recursiva que busque la clase en una lista (Vector y Librería String)
 desordenada de clases y horarios y cuente las comparaciones (if) realizadas.

Búsqueda Binaria Recursiva:

Implementa una función recursiva que busque la clase en una lista (Vector y Librería String)
 ordenada de clases y horarios y cuente las comparaciones (if) realizadas.

Requisitos:

El programa debe solicitar al usuario ingresar el número de clases, las clases y los horarios
 en la lista (Vector y Librería String). Considerar que se necesitarán un vector para las clases
 y otro vector para los horarios.

El programa debe imprimir el nombre de la clase encontrada y el horario que le corresponde.
 También debe imprimir el número de comparaciones (if) realizadas en cada tipo de búsqueda.

El programa debe impedir que se ingrese una lista desordenada para la búsqueda binaria.
 Pedile al usuario que ingrese en orden alfabético y que el programa verifique que así sea.
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Función para ordenar un vector usando el algoritmo de inserción
void ordenarPorInsercion(vector<string>& clases, vector<string>& horarios) {
    int n = clases.size();
    for (int i = 1; i < n; ++i) {
        string clave = clases[i];
        string claveHorario = horarios[i];
        int j = i - 1;

        // Mover los elementos del vector que son mayores que la clave
        while (j >= 0 && clases[j] > clave) {
            clases[j + 1] = clases[j];
            horarios[j + 1] = horarios[j];
            --j;
        }
        clases[j + 1] = clave;
        horarios[j + 1] = claveHorario;
    }
}

// Función recursiva para búsqueda secuencial
bool busquedaSecuencialRecursiva(const vector<string>& clases, const vector<string>& horarios,
                                 const string& claseObjetivo, int index, int& comparaciones) {
    if (index == clases.size()) {
        return false;
    }
    comparaciones++;
    if (clases[index] == claseObjetivo) {
        cout << "Clase: " << claseObjetivo << ", Horario: " << horarios[index] << endl;
        return true;
    }
    return busquedaSecuencialRecursiva(clases, horarios, claseObjetivo, index + 1, comparaciones);
}

// Función recursiva para búsqueda binaria
bool busquedaBinariaRecursiva(const vector<string>& clases, const vector<string>& horarios,
                              const string& claseObjetivo, int inicio, int fin, int& comparaciones) {
    if (inicio > fin) {
        return false;
    }
    comparaciones++;
    int medio = inicio + (fin - inicio) / 2;
    if (clases[medio] == claseObjetivo) {
        cout << "Clase: " << claseObjetivo << ", Horario: " << horarios[medio] << endl;
        return true;
    } else if (clases[medio] > claseObjetivo) {
        return busquedaBinariaRecursiva(clases, horarios, claseObjetivo, inicio, medio - 1, comparaciones);
    } else {
        return busquedaBinariaRecursiva(clases, horarios, claseObjetivo, medio + 1, fin, comparaciones);
    }
}

// Función para verificar si un vector está ordenado
bool estaOrdenado(const vector<string>& clases) {
    for (size_t i = 1; i < clases.size(); ++i) {
        if (clases[i] < clases[i - 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    cout << "Ingrese el numero de clases: ";
    cin >> n;

    vector<string> clases(n);
    vector<string> horarios(n);

    cout << "Ingrese las clases y los horarios correspondientes:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "Clase " << i + 1 << ": ";
        cin >> clases[i];
        cout << "Horario " << i + 1 << ": ";
        cin >> horarios[i];
    }

    // Verificación y ordenación del vector de clases
    if (!estaOrdenado(clases)) {
        cout << "El arreglo de clases no esta ordenado. Ordenando ahora..." << endl;
        ordenarPorInsercion(clases, horarios);
        cout << "Clases ordenadas:" << endl;
        for (int i = 0; i < n; ++i) {
            cout << "Clase " << i + 1 << ": " << clases[i] << ", Horario: " << horarios[i] << endl;
        }
    }

    // Búsqueda Secuencial Recursiva
    string claseObjetivo;
    cout << "Ingrese la clase a buscar (busqueda secuencial): ";
    cin >> claseObjetivo;

    int comparacionesSecuencial = 0;
    bool encontradoSecuencial = busquedaSecuencialRecursiva(clases, horarios, claseObjetivo, 0, comparacionesSecuencial);

    if (!encontradoSecuencial) {
        cout << "Clase no encontrada (busqueda secuencial)" << endl;
    }
    cout << "Numero de comparaciones realizadas en la busqueda secuencial: " << comparacionesSecuencial << endl;

    // Búsqueda Binaria Recursiva
    cout << "Ingrese la clase a buscar (busqueda binaria): ";
    cin >> claseObjetivo;

    int comparacionesBinaria = 0;
    bool encontradoBinario = busquedaBinariaRecursiva(clases, horarios, claseObjetivo, 0, n - 1, comparacionesBinaria);

    if (!encontradoBinario) {
        cout << "Clase no encontrada (busqueda binaria)" << endl;
    }
    cout << "Numero de comparaciones realizadas en la busqueda binaria: " << comparacionesBinaria << endl;

    return 0;
}
