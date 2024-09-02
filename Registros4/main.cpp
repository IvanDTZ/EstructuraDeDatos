#include <iostream>
#include <cstring>

using namespace std;

struct Store {
    int storeNumber;
    char managerName[50];
    double salesLastTwoMonths[2];
};

void bubbleSort(Store stores[], int count, bool ascending) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            bool condition = ascending ? (stores[j].storeNumber > stores[j + 1].storeNumber)
                                       : (stores[j].storeNumber < stores[j + 1].storeNumber);
            if (condition) {
                Store temp = stores[j];
                stores[j] = stores[j + 1];
                stores[j + 1] = temp;
            }
        }
    }
}

void inputStores(Store stores[], int &count) {
    int storeNumber;
    double sales;
    char managerName[50];

    cout << "Dame el numero de tienda: ";
    while (!(cin >> storeNumber) || storeNumber <= 0) {
        cout << "Tiene que ser entero ";
        cin.clear();
        cin.ignore(10000, '\n');
    }
    stores[count].storeNumber = storeNumber;
    cin.ignore();

    cout << "Dame el nombre del gerente: ";
    cin.getline(managerName, 50);
    strcpy(stores[count].managerName, managerName);

    for (int j = 0; j < 2; j++) {
        cout << "Dame las ventas por mes " << j + 1 << ": $";
        while (!(cin >> sales) || sales < 0) {
            cout << "No pueden ser negativas, que paso ahi?: ";
            cin.clear();
            cin.ignore(10000, '\n');
        }
        stores[count].salesLastTwoMonths[j] = sales;
    }

    count++;
}

void showStores(Store stores[], int count) {
    for (int i = 0; i < count; i++) {
        cout << "Numero de tienda: " << stores[i].storeNumber << endl;
        cout << "Gerente: " << stores[i].managerName << endl;
        cout << "Ventas de los ultimos dos meses: $" << stores[i].salesLastTwoMonths[0] << ", $" << stores[i].salesLastTwoMonths[1] << endl;
        cout << "--------------------------" << endl;
    }
}

int main() {
    Store stores[100];
    int count = 0;
    int choice;
    bool ascending;

    mainMenu:
    cout << "Le menu:" << endl;
    cout << "1. Ver tiendas en orden ascendiente" << endl;
    cout << "2. Ver tiendas en orden descendente" << endl;
    cout << "3. Registrar nueva tienda" << endl;
    cout << "4. Salir" << endl;
    cout << "Que gustas hacer?";

    while (!(cin >> choice) || choice < 1 || choice > 4) {
        cout << "Selecciona algo valido ";
        cin.clear();
        cin.ignore(10000, '\n');
    }

    if (choice == 1) {
        ascending = true;
        bubbleSort(stores, count, ascending);
        showStores(stores, count);
        goto mainMenu;
    } else if (choice == 2) {
        ascending = false;
        bubbleSort(stores, count, ascending);
        showStores(stores, count);
        goto mainMenu;
    } else if (choice == 3) {
        if (count < 100) {
            inputStores(stores, count);
        } else {
            cout << "Ya se llego al limite, si quiere registrar mas contacte con ventas para ampliar su suscripcion" << endl;
        }
        goto mainMenu;
    } else if (choice == 4) {
        cout << "Adios vaquero" << endl;
        return 0;
    }

    return 0;
}
