#include "BruteForceKP01wCG.h"
#include "Solution.h"
#include "KP01withCGInstance.h"
#include <chrono>
#include "Graph.h"
using namespace std;

BruteForceKP01wCG::BruteForceKP01wCG(const string& archivo) {
    this->_instancia = KP01withCGInstance();
    this->_instancia.cargar_datos(archivo);
    this->_bestSol = Solution();  
}

Solution BruteForceKP01wCG::solve() {
    Mochila_FB(this->_bestSol, 0);
    return this->_bestSol;
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
