#include <string>
#include "Graph.h"
using namespace std;

// Caso 1: Construcción inicial de la matriz
TEST(graph_tests, construirMatrizInicializaCorrectamente) {
    Graph G;
    G.construirMatriz(5);

    auto matriz = G.getMatriz();
    ASSERT_EQ(matriz.size(), 5);
    for (const auto& fila : matriz) {
        ASSERT_EQ(fila.size(), 5); 
        for (bool valor : fila) {
            ASSERT_FALSE(valor);
        }
    }

    ASSERT_EQ(G.getCantidadConflictos(), 0);
}

// Caso 2: Agregar un conflicto y verificar simetría
TEST(graph_tests, agregarUnConflicto) {
    Graph G;
    G.construirMatriz(3);
    G.addConflict(0, 1);

    auto matriz = G.getMatriz();
    ASSERT_TRUE(matriz[0][1]);
    ASSERT_TRUE(matriz[1][0]);
    ASSERT_EQ(G.getCantidadConflictos(), 1);
}

// Caso 3: Eliminar un conflicto
TEST(graph_tests, eliminarConflicto) {
    Graph G;
    G.construirMatriz(4);
    G.addConflict(1, 2);
    G.removeConflict(1, 2);

    auto matriz = G.getMatriz();
    ASSERT_FALSE(matriz[1][2]);
    ASSERT_FALSE(matriz[2][1]);
    ASSERT_EQ(G.getCantidadConflictos(), 0);
}

// Caso 4: Agregar múltiples conflictos
TEST(graph_tests, agregarMultiplesConflictos) {
    Graph G;
    G.construirMatriz(5);
    G.addConflict(0, 1);
    G.addConflict(1, 2);
    G.addConflict(3, 4);

    auto matriz = G.getMatriz();
    ASSERT_TRUE(matriz[0][1]);
    ASSERT_TRUE(matriz[1][0]);
    ASSERT_TRUE(matriz[1][2]);
    ASSERT_TRUE(matriz[2][1]);
    ASSERT_TRUE(matriz[3][4]);
    ASSERT_TRUE(matriz[4][3]);
    ASSERT_EQ(G.getCantidadConflictos(), 3);
}

// Caso 5: Agregar y remover el mismo conflicto múltiples veces
TEST(graph_tests, agregarYRemoverRepetido) {
    Graph G;
    G.construirMatriz(3);
    G.addConflict(0, 2);
    G.removeConflict(0, 2);
    G.addConflict(0, 2);
    G.removeConflict(0, 2);

    auto matriz = G.getMatriz();
    ASSERT_FALSE(matriz[0][2]);
    ASSERT_FALSE(matriz[2][0]);
    ASSERT_EQ(G.getCantidadConflictos(), 0);
}