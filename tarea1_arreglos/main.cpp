#include <iostream>
#include <cstring>

using namespace std;


class IntegerArray {
public:
    int arr[10];
    int originalArr[10];

    IntegerArray() {
        initializeArray();
        sortArray();
    }

    void initializeArray() {
        int temp[] = {6, 4, 6, 7, 7, 8, 1, 5, 9, 0};
        for (int i = 0; i < 10; i++) {
            arr[i] = temp[i];
            originalArr[i] = temp[i];
        }
    }

    void showOriginalArray() {
        for (int i = 0; i < 10; i++) {
            cout << originalArr[i] << " ";
        }
        cout << endl;
    }

    void showSortedArray() {
        for (int i = 0; i < 10; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void sortArray() {
        for (int i = 0; i < 10 - 1; i++) {
            for (int j = 0; j < 10 - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }

    void showBothArrays() {
        cout << "Areglo original: ";
        showOriginalArray();
        cout << "Arreglo ordenado ";
        showSortedArray();
    }
};

class StringArray {
public:
    char arr[5][20];
    char originalArr[5][20];

    StringArray() {
        initializeArray();
        sortArray();
    }

    void initializeArray() {
        const char* temp[] = {"Allmight", "uraraka", "ichigo", "Deku", "bam"};
        for (int i = 0; i < 5; i++) {
            strcpy(arr[i], temp[i]);
            strcpy(originalArr[i], temp[i]);
        }
    }

    void showOriginalArray() {
        for (int i = 0; i < 5; i++) {
            cout << originalArr[i] << endl;
        }
    }

    void showSortedArray() {
        for (int i = 0; i < 5; i++) {
            cout << arr[i] << endl;
        }
    }

    void sortArray() {
        for (int i = 0; i < 5 - 1; i++) {
            for (int j = 0; j < 5 - i - 1; j++) {
                if (strcmp(arr[j], arr[j + 1]) > 0) {
                    char temp[20];
                    strcpy(temp, arr[j]);
                    strcpy(arr[j], arr[j + 1]);
                    strcpy(arr[j + 1], temp);
                }
            }
        }
    }

    void showBothArrays() {
        cout << "Arreglo original: " << endl;
        showOriginalArray();
        cout << "Arerglo ordenado: " << endl;
        showSortedArray();
    }
};

int main() {
    IntegerArray intArray;
    StringArray strArray;
    int choice;

    mainMenu:
    cout << "Le menu:" << endl;
    cout << "1. Mostrar el arreglo de enteros" << endl;
    cout << "2. Mostrar el arreglo de strings" << endl;
    cout << "3. Salir" << endl;
    cout << "Que gustas hacer ";
    cin >> choice;

    if (choice == 1) {
        cout << "\nArreglod e enteros:" << endl;
        intArray.showBothArrays();
        goto mainMenu;
    } else if (choice == 2) {
        cout << "\nArreglo de strings:" << endl;
        strArray.showBothArrays();
        goto mainMenu;
    } else if (choice == 3) {
        cout << "Adios vaquero" << endl;
        return 0;
    } else {
        cout << "dame algo valido" << endl;
        goto mainMenu;
    }

    return 0;
}
