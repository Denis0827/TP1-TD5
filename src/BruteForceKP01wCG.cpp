#include "BruteForceKP01wCG.h"
#include "Solution.h"
#include "KP01withCGInstance.h"
#include <chrono>
#include "Graph.h"
using namespace std;

// Constructor: carga la instancia desde archivo
BruteForceKP01wCG::BruteForceKP01wCG(const string& archivo) {
    this->_instancia = KP01withCGInstance(); // O(1)
    this->_instancia.cargar_datos(archivo);  // O(N^2 + C)
}

// Método que lanza el algoritmo de fuerza bruta
Solution BruteForceKP01wCG::solve() {
    Solution bestSol = Solution(); // O(1)
    Solution parcialSol = Solution(); // O(1)
    Mochila_FB(parcialSol, 0, bestSol); // O(2^N * (N + S^2))
    return bestSol; // O(1)
}

/*
int main() {
    auto start = std::chrono::high_resolution_clock::now();

    BruteForceKP01wCG FB = BruteForceKP01wCG("costo_peso_correlaciona_n20_cycle.txt");
    Solution S = FB.solve();
    S.printSolution();

    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> elapsed = end - start;
    std::cout << "Tiempo de ejecución: " << elapsed.count() << " segundos\n";

    return 0;
}
    */
    