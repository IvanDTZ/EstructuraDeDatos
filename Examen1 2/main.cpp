#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Municipio {
public:
    string nombre;
    int habitantes;
    string presidente;

    Municipio(string n, int h, string p) : nombre(n), habitantes(h), presidente(p) {}

    void mostrar() const {
        cout << "Municipio: " << nombre << ", Habitantes: " << habitantes << ", Presidente: " << presidente << endl;
    }
};

class SistemaMunicipios {
public:
    vector<Municipio> municipios;

    void agregar() {
        string nombre, presidente;
        int habitantes;

        cout << "Nombre del municipio: ";
        cin.ignore();
        getline(cin, nombre);

        cout << "Cantidad de habitantes: ";
        cin >> habitantes;

        cout << "Presidente municipal: ";
        cin.ignore();
        getline(cin, presidente);

        municipios.push_back(Municipio(nombre, habitantes, presidente));
    }

    void mostrarTodos() const {
        if (municipios.empty()) {
            cout << "No hay municipios registrados." << endl;
        } else {
            for (size_t i = 0; i < municipios.size(); ++i) {
                cout << "-Municipio:" << i + 1 << " -----" << endl;
                municipios[i].mostrar();
            }
        }
    }
};

void ejercicio1() {
    cout << "En pocas palabras es una estructura, tambien puede ser un array, un registro es algo que nos permite guardar datos bajo el mismo nombre." << endl;
}

void mostrarOrdenado(int array[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }

    cout << "Estaturas en orden: " << endl;
    for (int i = 0; i < n; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

void ejercicio2() {
    int dec = 0;
    cout << "¿De cuántas personas quiere su arreglo de estatura?" << endl;
    cin >> dec;
    int estatura[dec];

    for (int i = 0; i < dec; i++) {
        cout << "Dame la estatura de la persona " << i + 1 << ": ";
        cin >> estatura[i];
    }

    cout << "Estaturas ingresadas: " << endl;
    for (int i = 0; i < dec; i++) {
        cout << estatura[i] << endl;
    }

    mostrarOrdenado(estatura, dec);
}

void ejercicio3() {
    SistemaMunicipios sistema;
    int opcion;

    do {
        cout << "\nMenu:" << endl;
        cout << "1 Agregar municipio" << endl;
        cout << "2 Mostrar todos los municipios" << endl;
        cout << "3 Salir" << endl;
        cout << "Seleccione una opción: ";
        cin >> opcion;

        if (opcion == 1) {
            sistema.agregar();
        } else if (opcion == 2) {
            sistema.mostrarTodos();
        }

    } while (opcion != 3);
}

int main() {
    int dec = 0;
    menu:
    cout << "¿Qué desea hacer?" << endl
         << "1 = Ejercicio 1" << endl
         << "2 = Ejercicio 2" << endl
         << "3 = Ejercicio 3" << endl
         << "4 = Salir" << endl;
    cin >> dec;

    switch (dec) {
        case 1:
            ejercicio1();
            break;
        case 2:
            ejercicio2();
            break;
        case 3:
            ejercicio3();
            break;
        case 4:
            exit(0);
            break;
        default:
            cout << "Selecciona algo valido" << endl;

    }
    goto menu;
    return 0;
}
