#include <iostream>

using namespace std;

void mostrarArreglo(int** arr, int filas, int columnas) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            cout << *(*(arr + i) + j) << " ";
        }
        cout << endl;
    }
}

void ordenarArreglo(int** arr, int filas, int columnas) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas - 1; j++) {
            for (int k = j + 1; k < columnas; k++) {
                if (*(*(arr + i) + j) > *(*(arr + i) + k)) {
                    int temp = *(*(arr + i) + j);
                    *(*(arr + i) + j) = *(*(arr + i) + k);
                    *(*(arr + i) + k) = temp;
                }
            }
        }
    }
}

int main() {
    string nombre {};
    string apellidoMaterno {};
    string apellidoPaterno {};
    int filas{}, columnas{};

    cout << "¿Cuál es tu nombre?" << endl;
    cin >> nombre;
    cout << "¿Cuál es tu apellido materno?" << endl;
    cin >> apellidoMaterno;
    cout << "¿Cuál es tu apellido paterno?" << endl;
    cin >> apellidoPaterno;
    cout << "¿De cuántas filas quieres tu arreglo?" << endl;
    cin >> filas;
    cout << "¿De cuántas columnas quieres tu arreglo?" << endl;
    cin >> columnas;

    // Crear arreglo bidimensional dinámico
    int** arreglo = new int*[filas];
    for (int i = 0; i < filas; i++) {
        arreglo[i] = new int[columnas];
    }

    // Llenar el arreglo con datos proporcionados por el usuario
    cout << "Introduce los valores para el arreglo:" << endl;
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            cout << "Elemento [" << i << "][" << j << "]: ";
            cin >> *(*(arreglo + i) + j);
        }
    }

    int opcion;
    do {
        cout << "\nMenú:\n";
        cout << "1. Mostrar arreglo\n";
        cout << "2. Ordenar y mostrar (sin modificar el original)\n";
        cout << "3. Salir\n";
        cout << "Elige una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Arreglo original:" << endl;
                mostrarArreglo(arreglo, filas, columnas);
                break;
            case 2: {
                // Crear un arreglo nuevo para ordenar
                int** arregloOrdenado = new int*[filas];
                for (int i = 0; i < filas; i++) {
                    arregloOrdenado[i] = new int[columnas];
                    for (int j = 0; j < columnas; j++) {
                        *(*(arregloOrdenado + i) + j) = *(*(arreglo + i) + j);
                    }
                }

                // Ordenar el arreglo copiado
                ordenarArreglo(arregloOrdenado, filas, columnas);

                cout << "Arreglo ordenado:" << endl;
                mostrarArreglo(arregloOrdenado, filas, columnas);

                // Liberar memoria del arreglo ordenado
                for (int i = 0; i < filas; i++) {
                    delete[] arregloOrdenado[i];
                }
                delete[] arregloOrdenado;
                break;
            }
            case 3:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opción no válida. Intenta de nuevo." << endl;
                break;
        }
    } while (opcion != 3);

    // Liberar memoria del arreglo original
    for (int i = 0; i < filas; i++) {
        delete[] arreglo[i];
    }
    delete[] arreglo;

    return 0;
}