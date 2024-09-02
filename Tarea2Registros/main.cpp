#include <iostream>
#include <cstring>

using namespace std;

class Employee {
public:
    char name[50];
    int height;
    double weeklySalary;

    Employee() {
        strcpy(name, "");
        height = 0;
        weeklySalary = 0.0;
    }

    void inputEmployee() {
        cout << "Cual es el nombre del empleado: ";
        cin.ignore();
        cin.getline(name, 50);
        cout << "Dame la altura del empleado pero en  cm, eh : ";
        cin >> height;
        cout << "dame el salario del empleado: ";
        cin >> weeklySalary;
    }

    void showEmployee() {
        cout << "Nombre: " << name << ", Altura: " << height << " cm, Salario semanal: $" << weeklySalary << endl;
    }
};

void showArray(Employee employees[], int count) {
    for (int i = 0; i < count; i++) {
        employees[i].showEmployee();
    }
}

void bubbleSort(Employee employees[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (strcmp(employees[j].name, employees[j + 1].name) > 0) {
                Employee temp = employees[j];
                employees[j] = employees[j + 1];
                employees[j + 1] = temp;
            }
        }
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

void registerEmployee(Employee employees[], int &count) {
    employees[count].inputEmployee();
    count++;
}

void deleteEmployee(Employee employees[], int &count) {
    char name[50];
    cout << "dame el nombre del que no va a ser nombrado, osea se elimina ";
    cin.ignore();
    cin.getline(name, 50);

    for (int i = 0; i < count; i++) {
        if (compareStrings(employees[i].name, name)) {
            for (int j = i; j < count - 1; j++) {
                employees[j] = employees[j + 1];
            }
            count--;
            cout << "se elimino, yey." << endl;
            return;
        }
    }

    cout << "no se encontro, f " << endl;
}

void editEmployee(Employee employees[], int count) {
    char name[50];
    cout << "Dame el nombre del empleado qeu quieres editar: ";
    cin.ignore();
    cin.getline(name, 50);

    for (int i = 0; i < count; i++) {
        if (compareStrings(employees[i].name, name)) {
            employees[i].inputEmployee();
            cout << "se modifico yay" << endl;
            return;
        }
    }

    cout << "No se encontro, f." << endl;
}

int main() {
    Employee employees[100];
    int count = 0;
    int choice;

    mainMenu:
    cout << "Le menu:" << endl;
    cout << "1. Ver empleados desordenados" << endl;
    cout << "2. Ver empleados ordenados" << endl;
    cout << "3. Registrar nuevo empleado" << endl;
    cout << "4. Editar o eliminar empleados" << endl;
    cout << "5. Salir" << endl;
    cout << "Que le gusta hacer?: ";
    cin >> choice;

    if (choice == 1) {
        cout << "Empleados desordenados" << endl;
        showArray(employees, count);
        goto mainMenu;
    } else if (choice == 2) {
        bubbleSort(employees, count);
        cout << "Empleados ordenados:" << endl;
        showArray(employees, count);
        goto mainMenu;
    } else if (choice == 3) {
        registerEmployee(employees, count);
        goto mainMenu;
    } else if (choice == 4) {
        int editChoice;
        editMenu:
        cout << "Menu le edite:" << endl;
        cout << "1. Editar empleado" << endl;
        cout << "2. Eliminar empleado" << endl;
        cout << "3. Regresar a le menu principal" << endl;
        cout << "Que le gusta hacer? ";
        cin >> editChoice;

        if (editChoice == 1) {
            editEmployee(employees, count);
            goto editMenu;
        } else if (editChoice == 2) {
            deleteEmployee(employees, count);
            goto editMenu;
        } else if (editChoice == 3) {
            goto mainMenu;
        } else {
            cout << "Dame algo valido" << endl;
            goto editMenu;
        }
    } else if (choice == 5) {
        cout << "Adios vaquero" << endl;
        return 0;
    } else {
        cout << "Dame algo valido" << endl;
        goto mainMenu;
    }

    return 0;
}
