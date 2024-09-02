#include <iostream>

using namespace std;

struct Address {
    char street[50];
    int number;
    char postalCode[10];
};

struct Supplier {
    char name[50];
    Address address;
};

void showCatalog(Supplier catalog[], int count) {
    for (int i = 0; i < count; i++) {
        cout << "Provedor: " << catalog[i].name << endl;
        cout << "Calle: " << catalog[i].address.street << endl;
        cout << "Numero: " << catalog[i].address.number << endl;
        cout << "Codigo postal: " << catalog[i].address.postalCode << endl;
        cout << "--------------------------" << endl;
    }
}

bool compareStrings(char str1[], char str2[]) {
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return false;
        }
        i++;
    }
    return str1[i] == str2[i];
}

void searchSupplier(Supplier catalog[], int count) {
    char name[50];
    cout << "Cual es el nombre del proovedor que estas buscando?  ";
    cin.ignore();
    cin.getline(name, 50);

    for (int i = 0; i < count; i++) {
        if (compareStrings(catalog[i].name, name)) {
            cout << "Se encontro: " << endl;
            cout << "Calle: " << catalog[i].address.street << endl;
            cout << "Numero: " << catalog[i].address.number << endl;
            cout << "Codigo postal: " << catalog[i].address.postalCode << endl;
            return;
        }
    }

    cout << "No se encontro, F " << endl;
}

void registerSupplier(Supplier catalog[], int &count) {
    cout << "Nombre: ";
    cin.ignore();
    cin.getline(catalog[count].name, 50);

    cout << "Calle: ";
    cin.getline(catalog[count].address.street, 50);

    cout << "Numero: ";
    cin >> catalog[count].address.number;

    cout << "Codigo postal: ";
    cin.ignore();
    cin.getline(catalog[count].address.postalCode, 10);

    count++;
}

int main() {
    int count = 0;
    Supplier catalog[100];
    int choice;

    mainMenu:
    cout << "le menu:" << endl;
    cout << "1. Ver proovedores" << endl;
    cout << "2. Buscar provedor por nombre" << endl;
    cout << "3. Registrar provedor" << endl;
    cout << "4. salid" << endl;
    cout << "Que le gusta hacer? ";
    cin >> choice;

    if (choice == 1) {
        showCatalog(catalog, count);
        goto mainMenu;
    } else if (choice == 2) {
        searchSupplier(catalog, count);
        goto mainMenu;
    } else if (choice == 3) {
        registerSupplier(catalog, count);
        goto mainMenu;
    } else if (choice == 4) {
        cout << "Adios vaquero" << endl;
        return 0;
    } else {
        cout << "Ingresa algo valido" << endl;
        goto mainMenu;
    }

    return 0;
}
