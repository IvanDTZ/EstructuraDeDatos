#include "utils/utils.h"
#include <iostream>
using namespace std;

int main() {
   int totalScreens;

   cout << "Introduce el número total de pantallas que se pueden registrar: ";
   cin >> totalScreens;

   ScreenStack stack(totalScreens);

   int choice;
   string screenModel;

   do {
      cout << "\nle menu:\n";
      cout << "1. Insertar una pantalla\n";
      cout << "2. Extraer una pantalla\n";
      cout << "3. Consultar la pantalla superior\n";
      cout << "4. Verificar si la pila está vacía\n";
      cout << "5. Verificar si la pila está llena\n";
      cout << "6. Mostrar todas las pantallas\n";
      cout << "7. Salir\n";
      cout << "Que le gusta hacer? ";
      cin >> choice;

      switch (choice) {
         case 1:
            cout << "Introduce el modelo de la pantalla (una letra seguida de números): ";
         cin >> screenModel;
         stack.push(screenModel);
         break;
         case 2:
            cout << "Pantalla extraída: " << stack.pop() << "\n";
         break;
         case 3:
            cout << "Pantalla en el tope: " << stack.peek() << "\n";
         break;
         case 4:
            cout << (stack.isEmpty() ? "La pila está vacía" : "La pila no está vacía") << "\n";
         break;
         case 5:
            cout << (stack.isFull() ? "La pila está llena" : "La pila no está llena") << "\n";
         break;
         case 6:
            stack.display();
         break;
         case 7:
            cout << "Adios vaquero";
         break;
         default:
            cout << "Dame algo valido\n";
         break;
      }
   } while (choice != 7);

   return 0;
}
