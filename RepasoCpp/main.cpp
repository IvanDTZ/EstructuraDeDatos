#include <iostream>

using namespace std;

class Calculator {
public:
    Calculator();
    ~Calculator();

    void showMenu();
    void sumUntilZero();
    void sumNineOfType();

private:
    int getNumber();
};

Calculator::Calculator() {
    cout << "se esta iniciando" << endl;
}

Calculator::~Calculator() {
    cout << "se esta apagando." << endl;
}

void Calculator::showMenu() {
    cout << "\nLe menu:" << endl;
    cout << "1. Suma infinita" << endl;
    cout << "2. Suma de 9, par o inpar" << endl;
    cout << "3. Exit" << endl;
}

int Calculator::getNumber() {
    int num;
    cout << "Dame un numero: ";
    cin >> num;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Dame un numero valido" << endl;
        return getNumber();
    }
    return num;
}

void Calculator::sumUntilZero() {
    int num, count = 0, sum = 0;

    cout << "Ingresa los numeros a sumar, hasta que pongas 0" << endl;
    do {
        num = getNumber();
        if (num != 0) {
            count++;
            sum += num;
        }
    } while (num != 0);

    cout << "\nNumeros ingresados: " << count << endl;
    cout << "Suma: " << sum << endl;
}

void Calculator::sumNineOfType() {
    int num, firstType, count = 0, sum = 0;
    bool validType = true;

    cout << "Dame el primer numero: ";
    num = getNumber();
    firstType = num % 2;

    for (int i = 1; i <= 9; i++) {
        if (i > 1) {
            cout << "Dame el numero #" << i << ": ";
            num = getNumber();
        }

        if (num % 2 != firstType) {
            validType = false;
            break;
        } else {
            count++;
            sum += num;
        }
    }

    if (validType) {
        cout << "\nIngresaste: " << count << " valido." << endl;
        cout << "Suma: " << sum << endl;
    } else {
        cout << "No es del tipo correcto, par o inpar." << endl;
    }
}

int main() {
    Calculator calc;
    int choice;

    mainMenu:
    calc.showMenu();
    cout << "Que le gusta hacer?";
    cin >> choice;

    if (cin.fail()) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Dame algo del menu, que paso ahi?" << endl;
        goto mainMenu;
    }

    switch (choice) {
        case 1:
            calc.sumUntilZero();
            goto mainMenu;
        case 2:
            calc.sumNineOfType();
            goto mainMenu;
        case 3:
            cout << "Adios vaquero" << endl;
            break;
        default:
            cout << "Dame algo valiod" << endl;
            goto mainMenu;
    }

    return 0;
}
