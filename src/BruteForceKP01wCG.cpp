// BacktrackingKP01.cpp
#include "BruteForceKP01wCG.h"
#include "Solution.h"
using namespace std;

BruteForceKP01wCG::BruteForceKP01wCG(const string& archivo) {
    this->_instancia = KP01withCGInstance();
    this->_instancia.cargar_datos(archivo);
    this->_bestSol = Solution(this->_instancia.getNumItems());  
}

Solution BruteForceKP01wCG::solve() {
    Mochila(this->_bestSol, 0);
    return this->_bestSol;
}

int main() {
    BruteForceKP01wCG FB = BruteForceKP01wCG("mochila_chica_n20_no_conflict.txt");
    Solution S = FB.solve();
    S.printSolution();
}
