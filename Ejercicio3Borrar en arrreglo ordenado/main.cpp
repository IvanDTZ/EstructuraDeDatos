#include <iostream>

using namespace std;

int main() {
    const int MAX_SIZE = 10;
    int arr[MAX_SIZE] = {1, 3, 5, 7, 9};
    int numElements = 5;
    int valueToInsert, valueToDelete, indexToDelete;
    int choice;

    do {
        cout << "Le menu:" << endl;
        cout << "1. Insertar numeros" << endl;
        cout << "2. Eliminar por valor" << endl;
        cout << "3. Eliminar por index" << endl;
        cout << "4. Ver arreglo" << endl;
        cout << "5. Salir" << endl;
        cout << "Que deseas hacer?: ";
        cin >> choice;

        int found = -1;

        switch (choice) {
            case 1:
                cout << "Que valor quieres ingresar?: ";
                cin >> valueToInsert;

                if (numElements >= MAX_SIZE) {
                    cout << "Esta lleno el arreglo, elimina algun dato primero" << endl;
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

                    cout << "Listo, se inserto" << endl;
                }
                break;

            case 2:
                cout << "Dame el valor para eliminar ";
                cin >> valueToDelete;

                for (int i = 0; i < numElements; i++) {
                    if (arr[i] == valueToDelete) {
                        found = i;
                        break;
                    }
                }

                if (found != -1) {
                    for (int i = found; i < numElements - 1; i++) {
                        arr[i] = arr[i + 1];
                    }
                    numElements--;
                    cout << "Se elimino jejje." << endl;
                } else {
                    cout << "No se encontro ese valor en el arreglo, f." << endl;
                }
                break;

            case 3:
                cout << "Dame el index a eliminar (0 a " << numElements - 1 << "): ";
                cin >> indexToDelete;

                if (indexToDelete < 0 || indexToDelete >= numElements) {
                    cout << "no existe ese index, f " << endl;
                } else {
                    for (int i = indexToDelete; i < numElements - 1; i++) {
                        arr[i] = arr[i + 1];
                    }
                    numElements--;
                    cout << "Elemento en el index " << indexToDelete << " Se elimino" << endl;
                }
                break;

            case 4:
                cout << "Arreglo: ";
                for (int i = 0; i < numElements; i++) {
                    cout << arr[i] << " ";
                }
                cout << endl;
                break;

            case 5:
                cout << "Adios vaquero" << endl;
                break;

            default:
                cout << "Dame algo valido" << endl;
                break;
        }
    } while (choice != 5);

    return 0;
}
