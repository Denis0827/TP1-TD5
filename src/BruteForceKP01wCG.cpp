// BacktrackingKP01.cpp
#include "BruteForceKP01wCG.h"

BruteForceKP01wCG::BruteForceKP01wCG(const string& archivo) {
    this->_instancia = KP01withCGInstance();
    this->_instancia.cargar_datos(archivo);
    this->_bestSol = Solution(this->_instancia.getNumItems());  
}

Solution BruteForceKP01wCG::solve() {
    Mochila(this->_bestSol, 0);
    return this->_bestSol;
}

Solution Mochila(Solution S, int k) {
    if (k == this->_instancia.getNumItems()) {
        if (S.getWeightTotal() <= this->_instancia.getCapacity() && S.getProfitTotal() > this->_bestSol.getProfitTotal()) {
            this->_bestSol = S;
            return S;
        }
    } else {
        if (!this->_instancia.hasConflict(S.getItems(), k)) {
            return Mochila(S, k + 1); 
            S.addItem(k, this->_instancia.getWeight(k), this->_instancia.getProfit(k)); 
            return Mochila(S, k + 1); 
        } else {
            return Mochila(S, k + 1);
        }
    }
}
