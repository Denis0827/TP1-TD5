// BacktrackingKP01.cpp
#include "BacktrackingKP01wCG.h"

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
    BacktrackingKP01wCG FB = BacktrackingKP01wCG("mochila_chica_n10_no_conflict.txt");
    Solution S = FB.solve();
    S.printSolution();
    return 0;
}