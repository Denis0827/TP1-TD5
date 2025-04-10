// BacktrackingKP01.cpp
#include "BacktrackingKP01wCG.h"
#include <chrono>
#include "Graph.h"

BacktrackingKP01wCG::BacktrackingKP01wCG(const string& archivo) {
    this->_instancia = KP01withCGInstance();
    this->_instancia.cargar_datos(archivo);
}

Solution BacktrackingKP01wCG::solve() {
    Solution bestSol = Solution();
    Solution parcialSol = Solution();
    Mochila_BT(parcialSol, 0, bestSol);
    return bestSol;
}

/*
int main() {
    auto start = std::chrono::high_resolution_clock::now();

    BacktrackingKP01wCG BT = BacktrackingKP01wCG("mochila_chica_n20_no_conflict.txt");
    Solution S = BT.solve();
    S.printSolution();

    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> elapsed = end - start;
    std::cout << "Tiempo de ejecución: " << elapsed.count() << " segundos\n";

    return 0;
}
*/