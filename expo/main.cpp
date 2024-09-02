#include <iostream>
using namespace std;

struct Nodo {
    int dato;
    Nodo* siguiente;
};

void agregarNodo(Nodo*& cabeza, int valor) {
    Nodo* nuevoNodo = new Nodo();
    nuevoNodo->dato = valor;
    nuevoNodo->siguiente = cabeza;
    cabeza = nuevoNodo;
}

void mostrarLista(Nodo* cabeza) {
    Nodo* actual = cabeza;
    while (actual != nullptr) {
        cout << actual->dato << " -> ";
        actual = actual->siguiente;
    }
    cout << "null" << endl;
}

int main() {
    Nodo* cabeza = nullptr;
    agregarNodo(cabeza, 10);
    agregarNodo(cabeza, 20);
    agregarNodo(cabeza, 30);

    mostrarLista(cabeza);
    return 0;
}