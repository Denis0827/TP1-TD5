// BruteForceKP01wCG.h
#ifndef BRUTEFORCEKP01WCG_H
#define BRUTEFORCEKP01WCG_H

#include "Solution.h"
#include "KP01withCGInstance.h"
#include "Graph.h"

class BruteForceKP01wCG {
private:
    KP01withCGInstance _instancia;

    void Mochila_FB(Solution& S, int k, Solution& B) {
        if (k == this->_instancia.getNumItems()) {
            if (S.getWeightSolution() <= this->_instancia.getCapacity() 
                && S.getProfitSolution() > B.getProfitSolution()
                && !this->_instancia.hasConflictTotal(S.getItems())) {
                B = S;
            } 
        } else {
            S.addItem(k, this->_instancia.getWeight(k), this->_instancia.getProfit(k));
            Mochila_FB(S, k + 1, B);
            S.removeItem(k);
            Mochila_FB(S, k + 1, B);
        }
    };

public:
    BruteForceKP01wCG(const string& archivo);
    Solution solve();

};

#endif // BRUTEFORCEKP01WCG_H