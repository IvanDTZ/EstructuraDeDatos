#include <iostream>

using namespace std;

class Calculator {
public:
    Calculator();
    ~Calculator();

    void showMenu();
    void performAddition();
    void performSubtraction();
    void performMultiplication();
    void performDivision();

private:
    void getNumbers(double &num1, double &num2);

    double num1, num2;
};

Calculator::Calculator() {
    cout << "Se esta iniciando" << endl;
}

Calculator::~Calculator() {
    cout << "Se esta apagando" << endl;
}

void Calculator::showMenu() {
    cout << "\nLe menu" << endl;
    cout << "1. Suma" << endl;
    cout << "2. Resta" << endl;
    cout << "3. Multiplicacion" << endl;
    cout << "4. Division" << endl;
    cout << "5. Salir" << endl;
}

void Calculator::getNumbers(double &num1, double &num2) {
    cout << "Dame el primer numero ";
    cin >> num1;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Dame algo valido" << endl;
        return;
    }

    cout << "Dame el segundo numero ";
    cin >> num2;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Dame algo valido" << endl;
    }
}

void Calculator::performAddition() {
    getNumbers(num1, num2);
    if (!cin.fail()) {
        cout << "Resultado: " << num1 << " + " << num2 << " = " << num1 + num2 << endl;
    }
}

void Calculator::performSubtraction() {
    getNumbers(num1, num2);
    if (!cin.fail()) {
        cout << "Resultado: " << num1 << " - " << num2 << " = " << num1 - num2 << endl;
    }
}

void Calculator::performMultiplication() {
    getNumbers(num1, num2);
    if (!cin.fail()) {
        cout << "Resultado: " << num1 << " * " << num2 << " = " << num1 * num2 << endl;
    }
}

void Calculator::performDivision() {
    getNumbers(num1, num2);
    if (!cin.fail()) {
        if (num2 == 0) {
            cout << "No se puede dividir entre cero, de regreso a requisitos" << endl;
        } else {
            cout << "Resultado: " << num1 << " / " << num2 << " = " << num1 / num2 << endl;
        }
    }
}

int main() {
    Calculator calc;
    int choice;

    mainMenu:
    calc.showMenu();
    cout << "Dame tu opcion";
    cin >> choice;

    if (cin.fail()) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Dame algo valido" << endl;
        goto mainMenu;
    }

    switch (choice) {
        case 1:
            calc.performAddition();
            goto mainMenu;
        case 2:
            calc.performSubtraction();
            goto mainMenu;
        case 3:
            calc.performMultiplication();
            goto mainMenu;
        case 4:
            calc.performDivision();
            goto mainMenu;
        case 5:
            cout << "Adios vaquero" << endl;
            break;
        default:
            cout << "Dame algo valido" << endl;
            goto mainMenu;
    }

    return 0;
}
