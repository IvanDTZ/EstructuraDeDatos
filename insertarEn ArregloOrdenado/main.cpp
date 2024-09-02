#include <iostream>

using namespace std;

int main() {
    const int MAX_SIZE = 10;
    int arr[MAX_SIZE] = {5, 9, 2, 8, 1};
    int numElements = 5;
    int valueToInsert;
    int choice;

    do {
        cout << "Le menu:" << endl;
        cout << "1. ver arregloy" << endl;
        cout << "2. Insertar datos" << endl;
        cout << "3. salir" << endl;
        cout << "Que gustas hacer?: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Arreglo: ";
            for (int i = 0; i < numElements; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
            break;

            case 2:
                cout << "Que valor gustas insertar?: ";
            cin >> valueToInsert;

            if (numElements >= MAX_SIZE) {
                cout << "El arreglo esta lleno, srry." << endl;
            } else {
                int pos = 0;
                while (pos < numElements && arr[pos] < valueToInsert) {
                    pos++;
                }

                for (int i = numElements; i > pos; i--) {
                    arr[i] = arr[i - 1];
                }

                arr[pos] = valueToInsert;
                numElements++;

                cout << "Se inserto" << endl;
            }
            break;

            case 3:
                cout << "Adios vaquero" << endl;
            break;

            default:
                cout << "Escoge algo valido" << endl;
            break;
        }
    } while (choice != 3);

    return 0;
}
