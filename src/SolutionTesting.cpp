#include <iostream>
#include "Solution.h"
#include "Solution.cpp"
using namespace std;

int errores = 0;

void caso_inicializacion() {
    cout << "[Caso: Inicialización]..." << endl;
    Solution sol;
    if (sol.getWeightSolution() != 0) errores++;
    if (sol.getProfitSolution() != 0) errores++;
    if (!sol.getItems().empty()) errores++;
}

void caso_agregado_simple() {
    cout << "[Caso: Agregado simple]..." << endl;
    Solution sol;
    sol.addItem(2, 10, 100);
    if (sol.getWeightSolution() != 10) errores++;
    if (sol.getProfitSolution() != 100) errores++;
    if (sol.getItems().size() != 1) errores++;
    if (sol.getItems()[0] != 2) errores++;
    if (!sol.contains(2)) errores++;
}

void caso_agregado_multiple() {
    cout << "[Caso: Agregado múltiple]..." << endl;
    Solution sol;
    sol.addItem(1, 5, 50);
    sol.addItem(3, 20, 200);
    if (sol.getWeightSolution() != 25) errores++;
    if (sol.getProfitSolution() != 250) errores++;
    if (sol.getItems().size() != 2) errores++;
    if (!sol.contains(3)) errores++;
}

void caso_eliminacion_existente() {
    cout << "[Caso: Eliminación de ítem existente]..." << endl;
    Solution sol;
    sol.addItem(1, 5, 50);
    sol.addItem(2, 10, 100);
    sol.removeItem(1);

    if (sol.getWeightSolution() != 10) errores++;
    if (sol.getProfitSolution() != 100) errores++;
    if (sol.getItems().size() != 1) errores++;
    if (sol.contains(1)) errores++;
}

void caso_eliminacion_inexistente() {
    cout << "[Caso: Eliminación de ítem inexistente]..." << endl;
    Solution sol;
    sol.addItem(1, 5, 50);
    sol.removeItem(2); // no está

    if (sol.getWeightSolution() != 5) errores++;
    if (sol.getProfitSolution() != 50) errores++;
    if (sol.getItems().size() != 1) errores++;
    if (!sol.contains(1)) errores++;
}

void caso_printSolution() {
    cout << "[Caso: Impresión de solución]..." << endl;
    Solution sol;
    sol.addItem(5, 15, 300);
    sol.addItem(6, 10, 100);
    sol.printSolution(); // Validar visualmente
}

int main() {
    caso_inicializacion();
    caso_agregado_simple();
    caso_agregado_multiple();
    caso_eliminacion_existente();
    caso_eliminacion_inexistente();
    caso_printSolution();

    if (errores == 0) {
        cout << "\n Todos los casos de prueba pasaron correctamente." << endl;
    } else {
        cout << "\n Se detectaron " << errores << " errores en los tests de Solution." << endl;
    }

    return 0;
}