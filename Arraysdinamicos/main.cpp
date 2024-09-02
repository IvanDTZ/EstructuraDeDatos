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
    for (int i = 0; i < filas * columnas - 1; i++) {
        for (int j = i + 1; j < filas * columnas; j++) {
            int fila1 = i / columnas;
            int columna1 = i % columnas;
            int fila2 = j / columnas;
            int columna2 = j % columnas;

            if (*(*(arr + fila1) + columna1) > *(*(arr + fila2) + columna2)) {
                int temp = *(*(arr + fila1) + columna1);
                *(*(arr + fila1) + columna1) = *(*(arr + fila2) + columna2);
                *(*(arr + fila2) + columna2) = temp;
            }
        }
    }
}

int main() {
    string nombre {};
    string apellidoMaterno {};
    string apellidoPaterno {};
    int opcion{};
    int filas{}, columnas{};
int contador{};
    cout << "Cual es tu nombre?" << endl;
    cin >> nombre;
    cout << "Cual es tu apellido materno?" << endl;
    cin >> apellidoMaterno;
    cout << "Cual es tu apellido paterno?" << endl;
    cin >> apellidoPaterno;
    cout << "Cuantas filas quieres para tu arreglo?" << endl;
    cin >> filas;
    cout << "De cuantas columnas quieres tu arreglo?" << endl;
    cin >> columnas;

    int** arreglo = new int*[filas];
    for (int i = 0; i < filas; i++) {
        arreglo[i] = new int[columnas];
    }

    cout << "Introduce los valores para el arreglo:" << endl;
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            contador ++;
            cout <<  contador  << ": "<<endl;
            cin >> *(*(arreglo + i) + j);
        }
    }


        loop:
        cout << "Hola " << nombre << " "<< apellidoMaterno<< " " << apellidoPaterno<< " " << endl;
        cout << "\nMenu:"<<endl;
        cout << "1 Mostrar arreglo"<<endl;
        cout << "2 Ordenar y mostrar"<<endl;
        cout << "3 Salir"<<endl;
        cout << "Elige una opción: "<<endl;
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Arreglo original:" << endl;
                mostrarArreglo(arreglo, filas, columnas);
                break;
            case 2: {
                int** arregloOrdenado = new int*[filas];
                for (int i = 0; i < filas; i++) {
                    arregloOrdenado[i] = new int[columnas];
                    for (int j = 0; j < columnas; j++) {
                        *(*(arregloOrdenado + i) + j) = *(*(arreglo + i) + j);
                    }
                }

                ordenarArreglo(arregloOrdenado, filas, columnas);

                cout << "Arreglo ordenado:" << endl;
                mostrarArreglo(arregloOrdenado, filas, columnas);

                for (int i = 0; i < filas; i++) {
                    delete[] arregloOrdenado[i];
                }
                delete[] arregloOrdenado;
                break;
            }
            case 3:

            for (int i = 0; i < filas; i++) {
                delete[] arreglo[i];
            }
            delete[] arreglo;

             cout << "Adios vaquero" << endl;
                exit(0);
                break;
            default:
                cout << "Opción no válida" << endl;
                break;
        }
    goto loop;


}