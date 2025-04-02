// BruteForceKP01wCG.h
#ifndef BRUTEFORCEKP01WCG_H
#define BRUTEFORCEKP01WCG_H

#include "Solution.h"
#include "KP01withCGInstance.h"

class BruteForceKP01wCG {
private:
    KP01withCGInstance _instancia;
    Solution _bestSol;

    Solution Mochila(Solution S, int k) {
        if (k == this->_instancia.getNumItems()) {
            if (S.getWeightTotal() <= this->_instancia.getCapacity() && S.getProfitTotal() > this->_bestSol.getProfitTotal()) {
                this->_bestSol = S;
            } return S;
        } else {
            if (!this->_instancia.hasConflict(S.getItems(), k)) {
                return Mochila(S, k + 1); 
                S.addItem(k, this->_instancia.getWeight(k), this->_instancia.getProfit(k)); 
                return Mochila(S, k + 1); 
            } else {
                return Mochila(S, k + 1);
            }
        }
    };

public:
    BruteForceKP01wCG(const string& archivo);
    Solution solve();
};

#endif // BRUTEFORCEKP01WCG_H