#include "utils.h"

ScreenStack::ScreenStack(int size) {
    screens = new string[size];
    maxSize = size;
    top = -1;
}

ScreenStack::~ScreenStack() {
    delete[] screens;
}

bool ScreenStack::isFull() {
    return top == maxSize - 1;
}

bool ScreenStack::isEmpty() {
    return top == -1;
}

void ScreenStack::push(string screen) {
    if (isFull()) {
        cout << "La pila está llena. No se puede agregar más pantallas\n";
    } else if (isValidModel(screen)) {
        screens[++top] = screen;
    } else {
        cout << "Modelo de pantalla no válido. Debe empezar con una letra seguida de números\n";
    }
}

string ScreenStack::pop() {
    if (isEmpty()) {
        return "La pila está vacía. No hay pantallas para extraer";
    }
    return screens[top--];
}

string ScreenStack::peek() {
    if (isEmpty()) {
        return "La pila está vacía";
    }
    return screens[top];
}

void ScreenStack::display() {
    if (isEmpty()) {
        cout << "La pila está vacía\n";
    } else {
        cout << "Pantallas en la pila: \n";
        for (int i = top; i >= 0; i--) {
            cout << screens[i] << "\n";
        }
    }
}

bool ScreenStack::isValidModel(string model) {
    if (isalpha(model[0])) {
        for (int i = 1; i < model.length(); i++) {
            if (!isdigit(model[i])) {
                return false;
            }
        }
        return true;
    }
    return false;
}
