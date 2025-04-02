// BruteForceKP01wCG.h
#ifndef BRUTEFORCEKP01WCG_H
#define BRUTEFORCEKP01WCG_H

#include "Solution.h"
#include "KP01withCGInstance.h"

class BruteForceKP01wCG {
private:
    KP01withCGInstance _instancia;
    Solution _bestSol;

    void Mochila_FB(Solution S, int k) {
        if (k == this->_instancia.getNumItems()) {
            if (S.getWeightSolution() <= this->_instancia.getCapacity() && S.getProfitSolution() > this->_bestSol.getProfitSolution()) {
                this->_bestSol = S;
            } 
        } else {
            if (!this->_instancia.hasConflict(S.getItems(), k)) {
                Mochila_FB(S, k + 1); 
                S.addItem(k, this->_instancia.getWeight(k), this->_instancia.getProfit(k)); 
                Mochila_FB(S, k + 1); 
            } else {
                Mochila_FB(S, k + 1);
            }
        }
    };

public:
    BruteForceKP01wCG(const string& archivo);
    Solution solve();
};

#endif // BRUTEFORCEKP01WCG_H