// BacktrackingKP01.cpp
#include "BacktrackingKP01wCG.h"
#include <chrono>
#include "Graph.h"

BacktrackingKP01wCG::BacktrackingKP01wCG(const string& archivo) {
    this->_instancia = KP01withCGInstance();
    this->_instancia.cargar_datos(archivo);

    this->_bestSol = Solution(); 
}

Solution BacktrackingKP01wCG::solve() {
    Mochila_BT(this->_bestSol, 0);
    return this->_bestSol;
}


int main() {
    auto start = std::chrono::high_resolution_clock::now();

    BacktrackingKP01wCG BT = BacktrackingKP01wCG("costo_peso_correlaciona_n20_star.txt");
    Solution S = BT.solve();
    S.printSolution();

    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> elapsed = end - start;
    std::cout << "Tiempo de ejecución: " << elapsed.count() << " segundos\n";

    return 0;
}
    