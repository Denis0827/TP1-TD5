// BacktrackingKP01.cpp
#include "BacktrackingKP01wCG.h"
#include <chrono>
#include "Graph.h"

BacktrackingKP01wCG::BacktrackingKP01wCG(const string& archivo) {
    this->_instancia = KP01withCGInstance(); // O(1)
    this->_instancia.cargarDatos(archivo); // O(N^2 + C)
}

Solution BacktrackingKP01wCG::solve() {
    Solution bestSol = Solution(); // O(1)
    Solution parcialSol = Solution(); // O(1)
    Mochila_BT(parcialSol, 0, bestSol); // O(2^N*(N + S)) en el peor caso
    return bestSol; // O(1)
}


int main() {
    auto start = std::chrono::high_resolution_clock::now();

    BacktrackingKP01wCG BT = BacktrackingKP01wCG("instances/costo_peso_correlaciona_n20_cycle.txt");
    Solution S = BT.solve();
    S.printSolution();

    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> elapsed = end - start;
    std::cout << "Tiempo de ejecución: " << elapsed.count() << " segundos\n";

    return 0;
}
    