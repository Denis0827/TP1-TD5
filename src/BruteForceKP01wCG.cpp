#include "BruteForceKP01wCG.h"
#include "Solution.h"
#include "KP01withCGInstance.h"
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

int main() {
    BruteForceKP01wCG FB = BruteForceKP01wCG("mochila_chica_n40_no_conflict.txt");
    Solution S = FB.solve();
    S.printSolution();
    return 0;
}
