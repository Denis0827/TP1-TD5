#include <iostream>
#include <string>
#include "Graph.h"
using namespace std;

int errores = 0;

void caso_construccion_matriz_vacia() {
    cout << "[Caso: Construcción de matriz vacía]..." << endl;
    Graph G;
    G.construirMatriz(5);
    auto matriz = G.getMatriz();

    if (matriz.size() != 5) errores++;
    for (const auto& fila : matriz) {
<<<<<<< HEAD
        if (fila.size() != 5) errores++;
=======
        ASSERT_EQ(fila.size(), 5); 
>>>>>>> f3ddc46078aa1684835a13fb5aadee60747e0c25
        for (bool valor : fila) {
            if (valor) errores++;
        }
    }
    if (G.getCantidadConflictos() != 0) errores++;
}

void caso_agregar_conflicto() {
    cout << "[Caso: Agregar un conflicto]..." << endl;
    Graph G;
    G.construirMatriz(3);
    G.addConflict(0, 1);
    auto matriz = G.getMatriz();

    if (!matriz[0][1]) errores++;
    if (!matriz[1][0]) errores++;
    if (G.getCantidadConflictos() != 1) errores++;
}

void caso_eliminar_conflicto() {
    cout << "[Caso: Eliminar un conflicto]..." << endl;
    Graph G;
    G.construirMatriz(4);
    G.addConflict(1, 2);
    G.removeConflict(1, 2);
    auto matriz = G.getMatriz();

    if (matriz[1][2]) errores++;
    if (matriz[2][1]) errores++;
    if (G.getCantidadConflictos() != 0) errores++;
}

void caso_conflictos_multiples() {
    cout << "[Caso: Agregar múltiples conflictos]..." << endl;
    Graph G;
    G.construirMatriz(5);
    G.addConflict(0, 1);
    G.addConflict(1, 2);
    G.addConflict(3, 4);
    auto matriz = G.getMatriz();

    if (!matriz[0][1] || !matriz[1][0]) errores++;
    if (!matriz[1][2] || !matriz[2][1]) errores++;
    if (!matriz[3][4] || !matriz[4][3]) errores++;
    if (G.getCantidadConflictos() != 3) errores++;
}

void caso_conflicto_repetido() {
    cout << "[Caso: Agregar y eliminar conflicto repetidamente]..." << endl;
    Graph G;
    G.construirMatriz(3);
    G.addConflict(0, 2);
    G.removeConflict(0, 2);
    G.addConflict(0, 2);
    G.removeConflict(0, 2);
    auto matriz = G.getMatriz();

    if (matriz[0][2]) errores++;
    if (matriz[2][0]) errores++;
    if (G.getCantidadConflictos() != 0) errores++;
}

int main() {
    caso_construccion_matriz_vacia();
    caso_agregar_conflicto();
    caso_eliminar_conflicto();
    caso_conflictos_multiples();
    caso_conflicto_repetido();

    if (errores == 0) {
        cout << "\n Todos los casos de prueba de Graph pasaron correctamente." << endl;
    } else {
        cout << "\n Se detectaron " << errores << " errores en los tests de Graph." << endl;
    }

    return 0;
}